using System;

namespace TemplateMethod
{
	class Program
	{
		static void Main(string[] args)
		{
			DataAccessObject daoCategories = new Categories();
			daoCategories.Run();

			DataAccessObject daoProducts = new Products();
			daoProducts.Run();

			Console.ReadKey();
		}
	}
}
