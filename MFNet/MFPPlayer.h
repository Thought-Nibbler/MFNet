///////////////////////////////////////////////////
/// MFPPlayer.h
/// ==============================================
/// MFPlay を用いたメディアファイルの再生機能
///////////////////////////////////////////////////
#pragma once

using namespace System;

namespace MFNet 
{
	public ref class MFPPlayer
	{
	private:
		IMFPMediaPlayer *MFPlayer;
		bool IsReady;

	public:
		///////////////////////////////////////////////////
		/// 動画再生時のコンストラクタ
		/// pHwnd    : 動画を再生するウィンドウ（コントロール）のハンドル
		/// fileName : 再生するファイルのフルパス
		///////////////////////////////////////////////////
		MFPPlayer(IntPtr pHwnd, String^ fileName);

		///////////////////////////////////////////////////
		/// 音声再生時のコンストラクタ
		/// fileName : 再生するファイルのフルパス
		///////////////////////////////////////////////////
		MFPPlayer(String^ fileName);

		bool Play();

		bool Pause();

		bool Stop();
	};
}
