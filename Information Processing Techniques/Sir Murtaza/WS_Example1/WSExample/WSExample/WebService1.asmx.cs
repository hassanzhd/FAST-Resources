using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Services;

namespace WSExample
{
    /// <summary>
    /// Summary description for WebService1
    /// </summary>
    [WebService(Namespace = "http://tempuri.org/")]
    [WebServiceBinding(ConformsTo = WsiProfiles.BasicProfile1_1)]
    [System.ComponentModel.ToolboxItem(false)]
    // To allow this Web Service to be called from script, using ASP.NET AJAX, uncomment the following line. 
    // [System.Web.Script.Services.ScriptService]
    public class WebService1 : System.Web.Services.WebService
    {
        [WebMethod]
        private string CourseName()
        {
            return "IPT";
        }
        [WebMethod]
        public string Greetings()
        {
            return "Hello";
        }
        [WebMethod]
        public string HelloWorld(string MethodName, int num1, int num2)
        {
            switch (MethodName)
            {
                case "Subtract":
                    return Subtract(num1, num2).ToString();
                default:
                    return "No Method";
            }
        }

        [WebMethod]
        public string MethodCaller(string MethodName)
        {
            return "";
        }

        [WebMethod]
        public int Add(int a1, int a2)
        {
            return a1 + a2;
        }

        public int Subtract(int a1, int a2)
        {
            return a1 - a2;
        }
    }
}
