using System;

namespace Singleton
{
	class Program
	{
		static void Main(string[] args)
		{
			LoadBalancer b1 = LoadBalancer.GetLoadBalancer();
			LoadBalancer b2 = LoadBalancer.GetLoadBalancer();
			LoadBalancer b3 = LoadBalancer.GetLoadBalancer();
			LoadBalancer b4 = LoadBalancer.GetLoadBalancer();

			if (b1 == b2 && b2 == b3 && b3 == b4)
			{
				Console.WriteLine("Same instance\n");
			}

			LoadBalancer balancer = LoadBalancer.GetLoadBalancer();
			for (int i = 0; i < 15; i++)
			{
				string server = balancer.Server;
				Console.WriteLine("Dispatch Request to: " + server);
			}

			Console.ReadKey();
		}
	}
}
