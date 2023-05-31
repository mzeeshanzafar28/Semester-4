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
    public partial class frmAddCategory : Form
    {
        public frmAddCategory()
        {
            InitializeComponent();
        }
        Category c = new Category();
        void DisplayRecords()
        {
            dgvCategory.DataSource = c.GetCategoryRecords();
            dgvCategory.ReadOnly = true;
            dgvCategory.Refresh();
        }
        private void btnSave_Click(object sender, EventArgs e)
        {
            if (txtCatId.Text == "")
                MessageBox.Show("Please enter CatId!!");
            if (txtCatName.Text == "")
                MessageBox.Show("Please enter CatName!!");
            int CatId = Convert.ToInt32(txtCatId.Text);
            string CatName=txtCatName.Text;
            if(c.AddCategoryRecord(CatId,CatName))
            {
                DisplayRecords();
                txtCatId.Clear();
                txtCatName.Clear();
                MessageBox.Show("Category Added Successfully!!");
            }
            else

                 MessageBox.Show("Error Adding Category !!");
        }

        private void frmAddCategory_Load(object sender, EventArgs e)
        {
            this.WindowState = FormWindowState.Maximized;
            // TODO: This line of code loads data into the 'chaseupStoreDataSet.StoreUser' table. You can move, or remove it, as needed.
            // this.storeUserTableAdapter.Fill(this.chaseupStoreDataSet.StoreUser);
            Database.Connect();
            DisplayRecords();
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btnEdit_Click(object sender, EventArgs e)
        {
            if(dgvCategory.SelectedRows.Count>0)
            {
                DataGridViewRow row = dgvCategory.SelectedRows[0];
                txtCatId.Text = row.Cells[0].Value.ToString();
                txtCatName.Text = row.Cells[1].Value.ToString();
            }
            DisplayRecords();
        }

        private void btnUpdate_Click(object sender, EventArgs e)
        {
            if (txtCatId.Text == "")
                MessageBox.Show("Please enter CatId!!");
            if (txtCatName.Text == "")
                MessageBox.Show("Please enter CatName!!");
            int CatId = Convert.ToInt32(txtCatId.Text);
            string CatName = txtCatName.Text;
            if (c.UpdateCategoryRecord(CatId, CatName))
            {
                DisplayRecords();
                txtCatId.Clear();
                txtCatName.Clear();
                MessageBox.Show("Category Data Updated Successfully!!");
            }
            else

                MessageBox.Show("Error Updating  Category Data !!");
        }

        private void btnDelete_Click(object sender, EventArgs e)
        {
            if(dgvCategory.SelectedRows.Count>0)
            {
                DialogResult dr = MessageBox.Show("Are you sure to delete this record?", "Record Deletion", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
                if (dr == DialogResult.Yes)
                {
                    DataGridViewRow row = dgvCategory.SelectedRows[0];
                    int CatId = Convert.ToInt32(row.Cells[0].Value.ToString());
                    if (c.DeleteCategoryRecord(CatId))
                    {
                        MessageBox.Show("Category Data Deleted Succesfully!!");
                    }
                    else
                        MessageBox.Show("Error Deleting Category Reocrds!!");
                }
             
        }
            DisplayRecords();
        }
            }
}
