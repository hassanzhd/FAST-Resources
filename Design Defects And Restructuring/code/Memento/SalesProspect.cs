using System;

namespace Memento
{
	class SalesProspect
	{
		private string _name;
		private string _phone;
		private double _budget;

		public string Name
		{
			get { return _name; }
			set
			{
				_name = value;
				Console.WriteLine("Name:  " + _name);
			}
		}

		public string Phone
		{
			get { return _phone; }
			set
			{
				_phone = value;
				Console.WriteLine("Phone: " + _phone);
			}
		}

		public double Budget
		{
			get { return _budget; }
			set
			{
				_budget = value;
				Console.WriteLine("Budget: " + _budget);
			}
		}

		public Memento SaveMemento()
		{
			Console.WriteLine("\nSaving state --\n");
			return new Memento(_name, _phone, _budget);
		}

		public void RestoreMemento(Memento memento)
		{
			Console.WriteLine("\nRestoring state --\n");
			this.Name = memento.Name;
			this.Phone = memento.Phone;
			this.Budget = memento.Budget;
		}
	}
}
