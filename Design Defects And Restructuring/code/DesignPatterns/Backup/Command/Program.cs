using System;

namespace Command
{
	class Program
	{
		static void Main(string[] args)
		{
			User user = new User();

			user.Compute('+', 100);
			user.Compute('-', 50);
			user.Compute('*', 10);
			user.Compute('/', 2);

			user.Undo(4);
			user.Redo(3);
			Console.ReadKey();
		}
	}
}
