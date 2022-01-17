using System;

namespace Bridge
{
	class Program
	{
		static void Main(string[] args)
		{
			Customers customers = new Customers("Chicago");
			customers.Data = new CustomersData();

			customers.Show();
			customers.Next();
			customers.Show();
			customers.Next();
			customers.Show();
			customers.Add("Henry Velasquez");
			customers.ShowAll();

			Console.ReadKey();
		}
	}
}
