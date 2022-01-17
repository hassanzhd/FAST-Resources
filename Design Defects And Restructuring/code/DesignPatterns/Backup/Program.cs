using System;

namespace AbstractFactory
{
	class Program
	{
		static void Main()
		{
			ContinentFactory africa = new AfricaFactory();
			AnimalWorld world = new AnimalWorld(africa);
			world.RunFoodChain();

			ContinentFactory america = new AmericaFactory();
			world = new AnimalWorld(america);
			world.RunFoodChain();

			Console.ReadKey();
		}
	}
}
