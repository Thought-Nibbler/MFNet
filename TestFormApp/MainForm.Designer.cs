namespace TestFormApp
{
	partial class MainForm
	{
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		/// <param name="disposing">マネージ リソースが破棄される場合 true、破棄されない場合は false です。</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows フォーム デザイナーで生成されたコード

		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		private void InitializeComponent()
		{
			this.VideoCanvas = new System.Windows.Forms.PictureBox();
			this.BtnPlay = new System.Windows.Forms.Button();
			((System.ComponentModel.ISupportInitialize)(this.VideoCanvas)).BeginInit();
			this.SuspendLayout();
			// 
			// VideoCanvas
			// 
			this.VideoCanvas.Location = new System.Drawing.Point(5, 5);
			this.VideoCanvas.Name = "VideoCanvas";
			this.VideoCanvas.Size = new System.Drawing.Size(640, 480);
			this.VideoCanvas.TabIndex = 0;
			this.VideoCanvas.TabStop = false;
			// 
			// BtnPlay
			// 
			this.BtnPlay.Location = new System.Drawing.Point(278, 504);
			this.BtnPlay.Name = "BtnPlay";
			this.BtnPlay.Size = new System.Drawing.Size(75, 23);
			this.BtnPlay.TabIndex = 1;
			this.BtnPlay.Text = "Play";
			this.BtnPlay.UseVisualStyleBackColor = true;
			this.BtnPlay.Click += new System.EventHandler(this.BtnPlay_Click);
			// 
			// MainForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(654, 539);
			this.Controls.Add(this.BtnPlay);
			this.Controls.Add(this.VideoCanvas);
			this.Name = "MainForm";
			this.Text = "MFNet Test";
			this.Load += new System.EventHandler(this.MainForm_Load);
			((System.ComponentModel.ISupportInitialize)(this.VideoCanvas)).EndInit();
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.PictureBox VideoCanvas;
		private System.Windows.Forms.Button BtnPlay;
	}
}

