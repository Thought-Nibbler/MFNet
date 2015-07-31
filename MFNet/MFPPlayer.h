///////////////////////////////////////////////////
/// MFPPlayer.h
/// ==============================================
/// MFPlay ��p�������f�B�A�t�@�C���̍Đ��@�\
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
		/// ����Đ����̃R���X�g���N�^
		/// pHwnd    : ������Đ�����E�B���h�E�i�R���g���[���j�̃n���h��
		/// fileName : �Đ�����t�@�C���̃t���p�X
		///////////////////////////////////////////////////
		MFPPlayer(IntPtr pHwnd, String^ fileName);

		///////////////////////////////////////////////////
		/// �����Đ����̃R���X�g���N�^
		/// fileName : �Đ�����t�@�C���̃t���p�X
		///////////////////////////////////////////////////
		MFPPlayer(String^ fileName);

		bool Play();

		bool Pause();

		bool Stop();
	};
}
