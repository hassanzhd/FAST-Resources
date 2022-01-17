using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Runtime.Serialization;
using System.Web.Script.Serialization;

namespace JSonSerialization
{
    class Program
    {
        static void Main(string[] args)
        {
            Employee emp = new Employee();
            emp.Name = "Murtaza";
            emp.Divison = "Dev";

            Console.WriteLine(GetJSONString(emp));

            Console.ReadKey();
        }


        public static string GetJSONString(Object obj)
        {
            JavaScriptSerializer serializer = new JavaScriptSerializer();
            return serializer.Serialize(obj);
        }
    }


    class Employee
    {
        public string Name;
        public string Divison;
    }
}
