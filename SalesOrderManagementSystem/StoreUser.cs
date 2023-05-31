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
    public class StoreUser
    {
        public bool SearchUser(string UserId,string Password)
        {
            string query = "select* from StoreUser where UserId=@userId and Password=@Password";
            SqlCommand cmd = new SqlCommand();
            cmd.CommandText = query;
            cmd.CommandType = CommandType.Text;
            cmd.Connection = Database.GetConnection();
            cmd.Parameters.AddWithValue("@UserId", UserId);
            cmd.Parameters.AddWithValue("@Password", Password);

            SqlDataAdapter da = new SqlDataAdapter();
            da.SelectCommand = cmd;
            DataTable dt = new DataTable();
            bool found = false;
            try
            {
                da.Fill(dt);
                if(dt.Rows.Count==1)
                    found = true;
            }
            catch(SqlException ex)
            {
                MessageBox.Show(ex.Message);
            }
            return found;
        }
    }
}
