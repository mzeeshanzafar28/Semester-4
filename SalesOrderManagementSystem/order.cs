using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data;
using System.Data.SqlClient;
using System.Windows.Forms;
namespace SalesOrderManagementSystem
{
    public class order
    {
        public bool addOrder(int order_id, string category, string product, int gross_amount,int discount, int net_amount)
        {
            string query = "INSERT INTO orders values(@order_id,@category,@product,@gross_amount,@discount,@net_amount)";
            SqlCommand cmd = new SqlCommand();
            cmd.CommandText = query;
            cmd.CommandType = CommandType.Text;
            cmd.Connection = Database.GetConnection();
            cmd.Parameters.AddWithValue("@order_id",order_id);
            cmd.Parameters.AddWithValue("@category", category);
            cmd.Parameters.AddWithValue("@product", product);
            cmd.Parameters.AddWithValue("@gross_amount", gross_amount);
            cmd.Parameters.AddWithValue("@discount", discount);
            cmd.Parameters.AddWithValue("@net_amount", net_amount);
            bool Success = false;
            try
            {
                //Database.Connect();
                int n = cmd.ExecuteNonQuery();
                if (n > 0)
                    Success = true;
                else
                    Success = false;
            }
            catch (SqlException ex)
            {
                MessageBox.Show(ex.Message);
            }
            return Success;
        }

        public DataTable getOrder()
        {
            string query = "select * FROM orders";
            SqlDataAdapter da = new SqlDataAdapter(query, Database.GetConnection());
            DataTable dt = new DataTable();
            try
            {
;               da.Fill(dt);
            }
            catch (SqlException ex)
            {
                MessageBox.Show(ex.Message);
            }

            return dt;
        }

    }
}
