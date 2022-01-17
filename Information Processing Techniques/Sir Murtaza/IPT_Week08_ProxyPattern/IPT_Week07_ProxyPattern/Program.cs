using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IPT_Week07_ProxyPattern
{
    public interface ISubject
    {
        void Request();
    }

    class RealSubject : ISubject
    {
        public void Request()
        {

        }
    }

    class Proxy : ISubject
    {
        private RealSubject _realSubject;

        public Proxy (RealSubject realSubject)
        {
            this._realSubject = realSubject;
        }
        public void Request()
        {
            if (this.CheckAccess())
            {
                this._realSubject = new RealSubject();
                this._realSubject.Request();
                this.LogAccess();
            }
        }

        public bool CheckAccess()
        {
            Console.WriteLine("Proxy: Checking access prior to firing a real request.");
            return true;
        }

        public void LogAccess()
        {
            Console.WriteLine("Proxy: Logging the time of request.");
        }

    }

    public class Client
    {
        public void ClientCode(ISubject subject)
        {
            subject.Request();
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Client client = new Client();

            Console.WriteLine("Client: Executing the client code with a real subject:");
            client.ClientCode();

            Console.WriteLine();

            Console.WriteLine("Client: Executing the same client code with a proxy:");
            client.ClientCode(new Proxy(new RealSubject()));

            Console.ReadKey();
        }
    }
}
