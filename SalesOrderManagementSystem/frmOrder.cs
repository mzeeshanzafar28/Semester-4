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
    public partial class frmOrder : Form
    {
        Category c = new Category();
        Product p = new Product();
        order o = new order();
        public frmOrder()
        {
            InitializeComponent();
        }

        static int GenerateRandomId()
        {
            const int minValue = 100000;
            const int maxValue = 999999;
            Random random = new Random();
            return random.Next(minValue, maxValue + 1);
        }

        private void frmOrder_Load(object sender, EventArgs e)
        {
            // TODO: This line of code loads data into the 'salesDBDataSet.Product' table. You can move, or remove it, as needed.
            this.productTableAdapter.Fill(this.salesDBDataSet.Product);
            Database.Connect();
            cbCategory.DataSource = c.GetCategoryRecords();
            cbCategory.DisplayMember = "CatName";
            cbCategory.ValueMember = "CatId";
            int randomId = GenerateRandomId();
            txtOrderId.Text = randomId.ToString();
            if (!string.IsNullOrEmpty(txtGrossAmount.Text))
            {
                decimal gross = Convert.ToDecimal(txtGrossAmount.Text);
                decimal discount = Convert.ToDecimal(numericUpDownDiscount.Value);
                decimal amount = (discount / 100) * gross;
                txtAmount.Text = amount.ToString();
            }

        }

        

        private void cbCategory_SelectedIndexChanged(object sender, EventArgs e)
        {
            int id = Convert.ToInt32(cbCategory.SelectedIndex) + 1;
            cbProduct.DataSource = p.GetProductRecords(id.ToString());
            cbProduct.DisplayMember = "Description";
            cbProduct.ValueMember = "ProductId";

        }

        private void btnClose_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        void DisplayRecords()
        {
            dgvProduct.DataSource = p.GetProductRecords();
            dgvProduct.ReadOnly = true;
            dgvProduct.Refresh();
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            if (txtOrderId.Text == "")
            {
                MessageBox.Show("Do not temper with order id, enter it to continue");
                return;
            }
            if (cbCategory.Text == "")
            {
                MessageBox.Show("Please select a category");
                return;
            }
            if (cbProduct.Text == "")
            {
                MessageBox.Show("Please select a product");
                return;
            }
            if (txtGrossAmount.Text == "")
            {
                MessageBox.Show("Do not temper with gross amount, enter it to continue");
                return;
            }
            if (txtAmount.Text == "")
            {
                MessageBox.Show("Do not temper with net amount, enter it to continue");
                return;
            }
            int order_id = Convert.ToInt32(txtOrderId.Text);
            String category = cbCategory.Text.ToString();
            String product = cbProduct.Text.ToString();
            int gross_amount = Convert.ToInt32(txtGrossAmount.Text);
            int discount = Convert.ToInt32(numericUpDownDiscount.Value);
            int net_amount = Convert.ToInt32(txtAmount.Text);
            

            if (o.addOrder(order_id,category,product,gross_amount,discount,net_amount))
            {
                DisplayRecords();
                //txtOrderId.Text = p.GetNextProductId().ToString();
                txtOrderId.Clear();
                txtGrossAmount.Clear();
                numericUpDownDiscount.Value = 0;
                txtAmount.Clear();
                MessageBox.Show("Order Added Successfully");
            }
            else

                MessageBox.Show("Error Adding Order");
        }

        private void btnTotal_Click(object sender, EventArgs e)
        {
            if (!string.IsNullOrEmpty(txtGrossAmount.Text))
            {
                if (int.TryParse(txtGrossAmount.Text, out int gross))
                {
                    int discount = Convert.ToInt32(numericUpDownDiscount.Value);
                    int amount = (discount * gross) / 100;
                    amount = gross - amount;
                    txtAmount.Text = amount.ToString();
                }
                else
                {
                    txtAmount.Text = "Invalid Gross Amount";
                }
            }
        }
    }
}
