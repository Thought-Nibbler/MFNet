///////////////////////////////////////////////////
/// MFUtil.h
/// ==============================================
/// MFNet 動作ログ出力機能
///////////////////////////////////////////////////
#pragma once
#include <stdio.h>
#include <Windows.h>
#include <tchar.h>

namespace MFNet
{
	struct ErrorTable
	{
		HRESULT Code;
		TCHAR   Description[384];
		TCHAR   Name[64];
	};

	enum MessageLevel
	{
		ML_DEBUG,
		ML_INFO,
		ML_WARN,
		ML_ERROR
	};

	static class MFLog
	{
	private:
		static const ErrorTable MFErrorTable[281];
	public:
		static void ShowErrorNameFromCode(HRESULT code);
		static void ShowErrorDescriptionFromCode(HRESULT code);
		static void ShowMessage(LPCTSTR message, MessageLevel ml);
	};
}