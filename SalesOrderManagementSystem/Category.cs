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
    public class Category
    {
        public bool UpdateCategoryRecord(int CatId, string CatName)
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
            }
            return Success;
        }


        public bool AddCategoryRecord(int CatId, string CatName)
        {
            string query = "insert into Category(CatId,CatName) Values(@CatId,@CatName)";
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

        public DataTable GetCategoryRecords()
        {
            string query = "select * from Category";
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
