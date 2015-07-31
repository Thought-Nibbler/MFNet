// これは メイン DLL ファイルです。

#include "stdafx.h"
#include "MFPCapture.h"

namespace MFNet
{
	MFPCapture::MFPCapture()
	{
		MFStartup(MF_VERSION);
	}

	MFPCapture::~MFPCapture()
	{
		MFShutdown();
	}

	bool MFPCapture::CreateMediaSource()
	{
		HRESULT hr;

		pin_ptr<IMFAttributes *> pConfig = &(this->Config);
		hr = MFCreateAttributes(pConfig, 1);
		if (hr != S_OK)
		{ 
			MFLog::ShowErrorNameFromCode(hr);
			return false;
		}

		hr = this->Config->SetGUID(
			MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE, 
			MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_GUID
		); 
		if (hr != S_OK)
		{ 
			MFLog::ShowErrorNameFromCode(hr);
			return false;
		}

		pin_ptr<IMFActivate **> pDevices = &(this->Devices);
		pin_ptr<UINT32> pCount = &(this->DeviceCount);
		hr = MFEnumDeviceSources(this->Config, pDevices, pCount);
		if (hr != S_OK)
		{ 
			MFLog::ShowErrorNameFromCode(hr);
			return false;
		}
		if (this->DeviceCount <= 0) 
		{ 
			MFLog::ShowMessage(TEXT("Device Not Found."), ML_ERROR);
			return false;
		} 

		// Debug : 利用するデバイス（リストの先頭）の名前を確認
		LPWSTR devName = NULL;
		UINT32 devNameLen = 0;
		hr = this->Devices[0]->GetAllocatedString(MF_DEVSOURCE_ATTRIBUTE_FRIENDLY_NAME, &devName, &devNameLen);
		if (hr != S_OK)
		{ 
			MFLog::ShowErrorNameFromCode(hr);
			return false;
		}
		MFLog::ShowMessage(devName, ML_DEBUG);

		pin_ptr<IMFMediaSource *> pSource = &(this->Source);
		hr = this->Devices[0]->ActivateObject(
			__uuidof(IMFMediaSource), 
			reinterpret_cast<void**>(pSource)
		);  
		if (hr != S_OK)
		{ 
			MFLog::ShowErrorNameFromCode(hr);
			return false;
		}

		/*
		// シンボリックリンクを作成（特になくても動く）
		pin_ptr<LPWSTR> pSymLinkName = &(this->SymLinkName);
		pin_ptr<UINT32> pSymLinkLength = &(this->SymLinkLength);
		hr = this->Devices[0]->GetAllocatedString(MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_SYMBOLIC_LINK, pSymLinkName, pSymLinkLength);
		if (hr != S_OK)
		{
			MFUtil::ShowErrorNameFromCode(hr);
			return false;
		}
		*/
		return true;
	}

	bool MFPCapture::Initialize(IntPtr hWnd)
	{
		HRESULT hr = S_OK; 
		bool ret = false;

		ret = this->CreateMediaSource();
		if (!ret)
		{
			return false;
		}

		this->Hwnd = reinterpret_cast<HWND>(hWnd.ToPointer());
		pin_ptr<IMFPMediaPlayer *> pCapturePlayer = &(this->CapturePlayer);
		hr = MFPCreateMediaPlayer( 
			 NULL,
			 FALSE, 
			 0,       
			 NULL,  
			 this->Hwnd, 
			 pCapturePlayer
		);
		if (hr != S_OK)
		{
			MFLog::ShowErrorNameFromCode(hr);
			this->ReleaseDevices();
			return false;
		}

		IMFPMediaItem *pMediaItem = NULL;
		hr = this->CapturePlayer->CreateMediaItemFromObject( 
			this->Source, 
			TRUE,   
			0, 
			&(pMediaItem)
		);
		if (hr != S_OK)
		{
			MFLog::ShowErrorNameFromCode(hr);
			this->ReleaseDevices();
			return false;
		}

		hr = this->CapturePlayer->SetMediaItem(pMediaItem);
		if (hr != S_OK)
		{
			MFLog::ShowErrorNameFromCode(hr);
			this->ReleaseDevices();
			return false;
		}

		return true;
	}

	bool MFPCapture::StartCapture()
	{
		HRESULT hr = this->CapturePlayer->Play();
		if (hr != S_OK)
		{
			MFLog::ShowErrorNameFromCode(hr);
			return false;
		}
		return true;
	}

	bool MFPCapture::StopCapture()
	{
		HRESULT hr = this->CapturePlayer->Stop();
		if (hr != S_OK)
		{
			MFLog::ShowErrorNameFromCode(hr);
			return false;
		}

		return true;
	}

	void MFPCapture::ReleaseDevices()
	{
		for (DWORD i = 0; i < this->DeviceCount; i++) 
		{ 
			this->Devices[i]->Release(); 
		} 
		CoTaskMemFree(this->Devices); 
		this->Source->Release();
		this->Source = NULL;
	}
}
