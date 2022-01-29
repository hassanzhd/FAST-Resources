using System;

namespace Memento
{
	class Program
	{
		static void Main(string[] args)
		{
			SalesProspect s = new SalesProspect();
			s.Name = "Noel van Halen";
			s.Phone = "(412) 256-0990";
			s.Budget = 25000.0;

			ProspectMemory m = new ProspectMemory();
			m.Memento = s.SaveMemento();

			s.Name = "Leo Welch";
			s.Phone = "(310) 209-7111";
			s.Budget = 1000000.0;

			s.RestoreMemento(m.Memento);

			Console.ReadKey();
		}
	}
}
