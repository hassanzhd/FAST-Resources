using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace Example5
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
        public static void WorkThreadFunction()
        {
            try
            {
                bool lockWasTaken = false;
                var temp = _object;
                try
                {
                    Monitor.Enter(temp, ref lockWasTaken);
                    Thread.Sleep(100);
                    Console.WriteLine(Environment.TickCount);
                }
                finally
                {
                    if (lockWasTaken)
                    {
                        Monitor.Exit(temp);
                    }
                }

            }
            catch (Exception ex)
            {
                // log errors
            }
        }
    }
    
}
