using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 예제_8_3
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void 라디오1체크(object sender, EventArgs e)
        {
            label1.Text = radioButton1.Text;
        }

        private void 라디오2체크(object sender, EventArgs e)
        {
            label1.Text = radioButton2.Text;
        }

        private void 라디오3체크(object sender, EventArgs e)
        {
            label1.Text = radioButton3.Text;
        }

        private void 라디오4체크(object sender, EventArgs e)
        {
            label1.Text = radioButton4.Text;
        }
    }
}
