using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace 예제_8_2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void UpdateLabel(string s, bool b)
        {
            if (b)
            {
                label1.Text += s;
            }
            else
            {
                string strTemp = label1.Text;
                int i = strTemp.IndexOf(s);
                label1.Text = strTemp.Remove(i, s.Length);
            }
        }

        private void Checkedcharged_check1(object sender, EventArgs e)
        {
            UpdateLabel(checkBox1.Text, checkBox1.Checked);
        }

        private void Checkedcharged_check2(object sender, EventArgs e)
        {
            UpdateLabel(checkBox2.Text, checkBox2.Checked);

        }

        private void Checkedcharged_check3(object sender, EventArgs e)
        {

            UpdateLabel(checkBox3.Text, checkBox3.Checked);
        }

        private void Checkedcharged_check4(object sender, EventArgs e)
        {

            UpdateLabel(checkBox4.Text, checkBox4.Checked);
        }


    }
}
