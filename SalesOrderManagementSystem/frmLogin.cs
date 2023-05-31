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
    public partial class frmLogin : Form
    {
        public frmLogin()
        {
            InitializeComponent();
        }
        StoreUser user = new StoreUser();
        private void btnLogin_Click(object sender, EventArgs e)
        {
            if(txtUserId.Text=="")
            {
                MessageBox.Show("Please enter the UserId!!");
                return;
            }
            if(txtPassword.Text=="")
            {
                MessageBox.Show("Please enter Password!!");
                return;
            }
            string UserId = txtUserId.Text;
            string Password = txtPassword.Text;
            if (user.SearchUser(UserId,Password))
            {
                frmMain frm = new frmMain();
                this.Hide();
                frm.Show();
            }
            else
                MessageBox.Show("Invalid UserId or Password!!");
        }

        private void btnCancel_Click(object sender, EventArgs e)
        {
            Database.DisConnect();
            Application.Exit();
        }

        private void frmLogin_Load(object sender, EventArgs e)
        {
            Database.Connect();
        }
    }
}
