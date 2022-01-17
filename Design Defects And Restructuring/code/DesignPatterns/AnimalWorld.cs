using System;

namespace AbstractFactory
{
	class AnimalWorld
	{
		private Herbivore _herbivore;
		private Carnivore _carnivore;

		public AnimalWorld(ContinentFactory factory)
		{
			_carnivore = factory.CreateCarnivore();
			_herbivore = factory.CreateHerbivore();
		}

		public void RunFoodChain()
		{
			_carnivore.Eat(_herbivore);
		}
	}
}
