using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SalesOrderManagementSystem
{
    public partial class frmMain : Form
    {
        public frmMain()
        {
            InitializeComponent();
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void addNewCategoryToolStripMenuItem_Click(object sender, EventArgs e)
        {
            frmAddCategory frm = new frmAddCategory();
            frm.MdiParent = this;
            frm.Show();
        }

        private void addNewProductToolStripMenuItem_Click(object sender, EventArgs e)
        {
            frmAddProduct frm = new frmAddProduct();
            frm.MdiParent = this;
            frm.Show();
        }

        private void logoutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Database.DisConnect();
            frmLogin frm = new frmLogin();
            this.Hide();
            frm.Show();
        }

        private void addNewCustomerToolStripMenuItem_Click(object sender, EventArgs e)
        {

            frmOrder frm = new frmOrder();
            frm.MdiParent = this;
            frm.Show();
        }
    }
}
