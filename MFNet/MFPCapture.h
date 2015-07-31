// MFCapture.h

#pragma once
#include <stdio.h>
#include "mfapi.h"
#include "mfidl.h"
#include "mfplay.h"
#include "Mferror.h"
#include "mfreadwrite.h"
#include "shlwapi.h"
#include "wmcodecdsp.h"
#include "MFLog.h"

using namespace System;

namespace MFNet 
{
	public ref class MFPCapture
	{
	private:
		IMFPMediaPlayer *CapturePlayer;
		IMFAttributes *Config; 
		IMFActivate **Devices; 
		UINT32 DeviceCount;
		IMFMediaSource *Source;
		HWND Hwnd;

		bool CreateMediaSource();

		void ReleaseDevices();
	public:
		MFPCapture();

		~MFPCapture();

		bool Initialize(IntPtr hWnd);

		bool StartCapture();

		bool StopCapture();
	};
}
