using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 수업_0516
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void 버튼글자설정()
        {
            button1.Text = "폼의 폼 보드 스타일 = " + FormBorderStyle.ToString() + "\n" + 
                "폼의 크기 = " + Size.ToString() + "\n" + 
                "폼의 클라이언트 크기 = " + ClientSize.ToString();
        }

        private void F(object sender, EventArgs e)
        {

        }

        private void button_click(object sender, EventArgs e)
        {
            if (FormBorderStyle == FormBorderStyle.SizableToolWindow)
                FormBorderStyle = FormBorderStyle.None;
            else
                FormBorderStyle++;
            버튼글자설정();
        }
    }
}
