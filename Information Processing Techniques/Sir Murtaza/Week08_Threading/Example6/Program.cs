using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Runtime.CompilerServices;

namespace Example6
{
    class Program
    {
        public static object _object = new object();
        static void Main(string[] args)
        {

            Console.WriteLine("From Main Thread");
            for (int i = 0; i < 10; i++)
            {
                Thread myThread = new Thread(new ThreadStart(WorkThreadFunction));
                myThread.Start();
            }
            Console.ReadKey();

        }
        [MethodImpl(MethodImplOptions.Synchronized)]
        public static void WorkThreadFunction()
        {
            try
            {
                try
                {
                    Thread.Sleep(100);
                    Console.WriteLine(Environment.TickCount);
                }
                finally
                {
                }

            }
            catch (Exception ex)
            {
                // log errors
            }
        }
    }
}
