using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Services;

namespace WS_Calculator
{
    /// <summary>
    /// Summary description for MyCalculator
    /// </summary>
    [WebService(Namespace = "http://tempuri.org/")]
    [WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
    [System.ComponentModel.ToolboxItem(false)]
    // To allow this Web Service to be called from script, using ASP.NET AJAX, uncomment the following line. 
    // [System.Web.Script.Services.ScriptService]
    public class MyCalculator : System.Web.Services.WebService
    {

        [WebMethod]
        public int Add(int num1, int num2)
        {
            return num1 + num2;
        }

        [WebMethod]
        public int Add2(int num1, int num2, int num3)
        {
            return num1 + num2 + num3;
        }

    [WebMethod]
        public int Subtract(int num1, int num2)
        {
            return num1 - num2;
        }


        public bool Authenticate (string username, string password)
        {
            return true;
        }
        
        public int Multiple(int num1, int num2)
        {
            int localVar = 0;
            localVar = num1 * num2;
            //for (int i = num2; i > 0; i--)
            //    localVar += num1;
            return localVar;
        }

        [WebMethod]
        public int Divide(int num1, int num2)
        {
            return num1 / num2;
        }

        [WebMethod]
        public int Exponent(int num1, int num2)
        {
            return num1 ^ num2;
        }
    }
}
