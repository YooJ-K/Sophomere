using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _0516_수업_2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Click(object sender, EventArgs e)
        {
            panel1.Invalidate();
        }

        private void 그리기(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            Random r = new Random();
            Color c = Color.FromArgb(r.Next(256), r.Next(256), r.Next(256), r.Next(256));
            // Next 는 256보다 작은 양의정수+ 0의 random값을 뽑아서 alpha 값으로 들어간다.
            g.FillRectangle(new SolidBrush(c), e.ClipRectangle);
        
        }
    }
}
