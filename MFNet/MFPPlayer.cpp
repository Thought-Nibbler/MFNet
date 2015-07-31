// これは メイン DLL ファイルです。

#include "stdafx.h"
#include "msclr/marshal.h"
#include "mfplay.h"
#include "MFLog.h"
#include "MFPPlayer.h"

using namespace msclr::interop;

namespace MFNet
{
	MFPPlayer::MFPPlayer(IntPtr pHwnd, String^ fileName)
	{
		this->IsReady = false;
		this->MFPlayer = NULL;

		HWND hwnd = reinterpret_cast<HWND>(pHwnd.ToPointer());

		pin_ptr<IMFPMediaPlayer *> pMFPlayer = &(this->MFPlayer);

		marshal_context^ context = gcnew marshal_context;

		HRESULT hr = MFPCreateMediaPlayer(
			context->marshal_as<LPCWSTR>(fileName),
			FALSE,                                 
			0,
			NULL,
			hwnd,
			pMFPlayer
		);

		if (hr != S_OK)
		{
			MFLog::ShowErrorNameFromCode(hr);
		}

		delete context;

		this->IsReady = (hr == S_OK);
	}

	MFPPlayer::MFPPlayer(String^ fileName)
	{
		this->IsReady = false;
		this->MFPlayer = NULL;

		pin_ptr<IMFPMediaPlayer *> pMFPlayer = &(this->MFPlayer);

		marshal_context^ context = gcnew marshal_context;

		HRESULT hr = MFPCreateMediaPlayer(
			context->marshal_as<LPCWSTR>(fileName),
			FALSE,                                 
			0,
			NULL,
			NULL,
			pMFPlayer
		);

		delete context;

		this->IsReady = (hr == S_OK);
	}

	bool MFPPlayer::Play()
	{
		if (!(this->IsReady))
		{
			return false;
		}

		HRESULT hr = this->MFPlayer->Play();

		return (hr == S_OK);
	}

	bool MFPPlayer::Pause()
	{
		if (!(this->IsReady))
		{
			return false;
		}

		HRESULT hr = this->MFPlayer->Pause();

		return (hr == S_OK);
	}

	bool MFPPlayer::Stop()
	{
		if (!(this->IsReady))
		{
			return false;
		}

		HRESULT hr = this->MFPlayer->Stop();

		return (hr == S_OK);
	}
}