using System;
using System.Reflection;
using System.Text;

namespace TestJSON
{
    class Program
    {
        static void Main(string[] args)
        {
            Employee T = new Employee();
            T.Name = "Murtaza";
            T.Divison = "Dev";
            Console.WriteLine(T.ToJson());

            Console.Read();
        }
    }

    class Employee
    {
        public string Name;
        public string Divison;

        public string ToJson()
        {
            Employee obj = this;
            StringBuilder sb = new StringBuilder();
            FieldInfo[] properties = typeof(Employee).GetFields();
            foreach (FieldInfo attr in properties)
            {
                if (sb.Length > 0)
                    sb.Append(",");
                sb.Append(String.Format("\"{0}\":\"{1}\"", attr.Name, attr.GetValue(obj)));
            }
            return "{" + sb.ToString() + "}";
        }
    }
}
