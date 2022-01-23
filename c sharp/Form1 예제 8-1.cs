using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 예제_8_1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button4_click(object sender, EventArgs e)
        {
            label1.Text = FlatStyle.System.ToString();
        }

        private void button1_click(object sender, EventArgs e)
        {
            label1.Text = FlatStyle.Flat.ToString();
        }

        private void button2_click(object sender, EventArgs e)
        {
            label1.Text = FlatStyle.Popup.ToString();
        }

        private void button3_click(object sender, EventArgs e)
        {
            label1.Text = FlatStyle.Standard.ToString();
        }
    }
}
