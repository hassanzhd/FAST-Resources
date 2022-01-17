using System;

namespace Facade
{
	class Program
	{
		static void Main(string[] args)
		{
			Mortgage mortgage = new Mortgage();

			Customer customer = new Customer("Ann McKinsey");

			bool eligible = mortgage.IsEligible(customer, 125000);

			Console.WriteLine("\n" + customer.Name + " has been " + (eligible ? "Approved" : "Rejected"));

			Console.ReadKey();

		}
	}
}
