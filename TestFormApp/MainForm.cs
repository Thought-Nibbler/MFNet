using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using MFNet;

namespace TestFormApp
{
	public partial class MainForm : Form
	{
		private MFPCapture CapturePlayer = null;

		public MainForm()
		{
			InitializeComponent();
		}

		private void MainForm_Load(object sender, EventArgs e)
		{
			IntPtr hWnd = this.VideoCanvas.Handle;

			this.CapturePlayer = new MFPCapture();
			this.CapturePlayer.Initialize(hWnd);
		}

		private void BtnPlay_Click(object sender, EventArgs e)
		{
			bool result = this.CapturePlayer.StartCapture();
			if (!result)
			{
				MessageBox.Show("Error");
			}

		}
	}
}
