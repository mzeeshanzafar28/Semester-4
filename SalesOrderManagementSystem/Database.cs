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
    public class Database
    {
        private static SqlConnection cn;
        public static SqlConnection GetConnection()
        {
            return cn;
        }
        public static void Connect()
        {
            string con_str = "Data Source=DESKTOP-7NL5JIL;Initial Catalog=salesDB;Integrated Security=True";
            cn = new SqlConnection(con_str);
            try
            {
                cn.Open();
            }
            catch(SqlException ex)
            {
                MessageBox.Show(ex.Message);
            }

        }
        public static void DisConnect()
        {
            if (cn.State == ConnectionState.Open)
                cn.Close();
        }
    }
}
