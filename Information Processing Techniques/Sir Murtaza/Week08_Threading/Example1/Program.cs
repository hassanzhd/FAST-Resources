using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace Example1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("From Main Thread");
            Thread myThread = new Thread(new ThreadStart(WorkThreadFunction));
            myThread.Start();
            
            Console.WriteLine("From Main Thread again");
            Console.ReadKey();
            
        }

        public static void WorkThreadFunction()
        {
            try
            {
                Console.WriteLine("From Worker Function");
                //Thread.Sleep(2000);
                Console.WriteLine("From Worker Function again");
                
                // do any background work
            }
            catch (Exception ex)
            {
                // log errors
            }
        }
    }
}
