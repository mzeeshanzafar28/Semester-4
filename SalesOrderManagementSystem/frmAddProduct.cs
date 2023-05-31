using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace SalesOrderManagementSystem
{
    public partial class frmAddProduct : Form
    {
        public frmAddProduct()
        {
            InitializeComponent();
        }
        Product p = new Product();
        Category c = new Category();
        int CatId;
        bool Starting = true;

        void FillCategoryCombo()
        {
            cbCategory.DataSource = c.GetCategoryRecords();
            cbCategory.DisplayMember = "CatName";
            cbCategory.ValueMember = "CatId";
        }

        void DisplayRecords()
        {
            dgvProduct.DataSource = p.GetProductRecords();
            dgvProduct.ReadOnly = true;
            dgvProduct.Refresh();
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            
            if (txtDescription.Text == "")
                MessageBox.Show("Please enter Description!!");
            if (txtQty.Text == "")
                MessageBox.Show("Please enter Qty!!");
            if (txtUnitPrice.Text == "")
                MessageBox.Show("Please enter UnitPrice!!");
            if (txtCompany.Text == "")
                MessageBox.Show("Please enter Company!!");
            int ProductId = Convert.ToInt32(txtProductId.Text);
            string Description = txtDescription.Text;
            Double UnitPrice = Convert.ToDouble(txtUnitPrice.Text);
            string Company = txtCompany.Text;
            int Qty = Convert.ToInt32(txtQty.Text);
             if (p.AddProductRecord(ProductId,Description,Qty,UnitPrice,Company,CatId))
            {
                DisplayRecords();
                txtProductId.Text = p.GetNextProductId().ToString();
                txtDescription.Clear();
                txtUnitPrice.Clear();
                txtCompany.Clear();
                txtQty.Clear();
                
                MessageBox.Show("Product Record  Added Successfully!!");
            }
            else

                MessageBox.Show("Error Adding Product Record !!");
                }

        private void frmAddProduct_Load(object sender, EventArgs e)
        {
            this.WindowState = FormWindowState.Maximized; 
            txtProductId.Text = p.GetNextProductId().ToString();
            FillCategoryCombo();
            Starting = false;
            DisplayRecords();
        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void cbCategory_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (Starting != true)
            {
                CatId = Convert.ToInt32(cbCategory.SelectedValue.ToString());
            }
        }
    }
}
