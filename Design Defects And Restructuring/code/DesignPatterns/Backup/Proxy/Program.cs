using System;

namespace Proxy
{
	class Program
	{
		static void Main(string[] args)
		{
			MathProxy proxy = new MathProxy();

			Console.WriteLine("4 + 2 = " + proxy.Add(4, 2));
			Console.WriteLine("4 - 2 = " + proxy.Sub(4, 2));
			Console.WriteLine("4 * 2 = " + proxy.Mul(4, 2));
			Console.WriteLine("4 / 2 = " + proxy.Div(4, 2));

			Console.ReadKey();
		}
	}
}
