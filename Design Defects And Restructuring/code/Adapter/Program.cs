using System;

namespace Adapter
{
	class Program
	{
		static void Main(string[] args)
		{
			Compound unknown = new Compound("Unknown");
			unknown.Display();

			Compound water = new RichCompound("Water");
			water.Display();

			Compound benzene = new RichCompound("Benzene");
			benzene.Display();

			Compound ethanol = new RichCompound("Ethanol");
			ethanol.Display();

			Console.ReadKey();
		}
	}
}
