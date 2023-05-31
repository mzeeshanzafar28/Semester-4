using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;
using System.Data;
using System.Windows.Forms;

namespace SalesOrderManagementSystem
{
    public class Product
    {
       public int GetNextProductId()
        {
            string query = "select IsNull(max(ProductId),0)+1 from Product";
            SqlDataAdapter da = new SqlDataAdapter(query, Database.GetConnection());
            DataTable dt = new DataTable();
            try
            {
                da.Fill(dt);
            }
            catch (SqlException ex)
            {
                MessageBox.Show(ex.Message);
            }
            int ProductId = Convert.ToInt32(dt.Rows[0][0].ToString());
            return ProductId;
        }
       /* public bool UpdateProductRecord(int CatId, string CatName)
        {
            string query = "Update Category Set  CatName=@CatName where CatId=@CatId";
            SqlCommand cmd = new SqlCommand();
            cmd.CommandText = query;
            cmd.CommandType = CommandType.Text;
            cmd.Connection = Database.GetConnection();
            cmd.Parameters.AddWithValue("@CatId", CatId);
            cmd.Parameters.AddWithValue("@CatName", CatName);
            bool Success = false;
            try
            {
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
        public bool DeleteCategoryRecord(int CatId)
        {
            string query = "Delete from Category where CatId=@CatId";
            SqlCommand cmd = new SqlCommand();
            cmd.CommandText = query;
            cmd.CommandType = CommandType.Text;
            cmd.Connection = Database.GetConnection();
            cmd.Parameters.AddWithValue("@CatId", CatId);
            bool Success = false;
            try
            {
                int n = cmd.ExecuteNonQuery();
                if (n > 0)
                    Success = true;
                else
                    Success = false;
            }
            catch (SqlException ex)
            {
                MessageBox.Show(ex.Message);
            }0
            return Success;
        }*/


        public bool AddProductRecord(int ProductId, string Description,int Qty,double UnitPrice,string Company,int CatId)
        {
            string query = "insert into Product(ProductId,Description,Qty,UnitPrice,Company,CatId) Values(@ProductId,@Description,@Qty,@UnitPrice,@Company,@CatId)";
            SqlCommand cmd = new SqlCommand();
            cmd.CommandText = query;
            cmd.CommandType = CommandType.Text;
            cmd.Connection = Database.GetConnection();
            cmd.Parameters.AddWithValue("@ProductId", ProductId);
            cmd.Parameters.AddWithValue("@Description", Description);
            cmd.Parameters.AddWithValue("@Qty",Qty);
            cmd.Parameters.AddWithValue("@UnitPrice", UnitPrice);
            cmd.Parameters.AddWithValue("@Company",Company);
            cmd.Parameters.AddWithValue("@CatId",CatId);
            bool Success = false;
            try
            {
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

        public DataTable GetProductRecords()
        {
            string query = "select*from Product";
            SqlDataAdapter da = new SqlDataAdapter(query, Database.GetConnection());
            DataTable dt = new DataTable();
            try
            {
                da.Fill(dt);
            }
            catch (SqlException ex)
            {
                MessageBox.Show(ex.Message);
            }
            return dt;
        }

        public DataTable GetProductRecords(String id)
        {
            string query = "select*from Product where catid = " + id;
            SqlDataAdapter da = new SqlDataAdapter(query, Database.GetConnection());
            DataTable dt = new DataTable();
            try
            {
                da.Fill(dt);
            }
            catch (SqlException ex)
            {
                MessageBox.Show(ex.Message);
            }
            return dt;
        }
    }
}
