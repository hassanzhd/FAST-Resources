using System;

namespace Memento
{
	class Memento
	{
		private string _name;
		private string _phone;
		private double _budget;

		public Memento(string name, string phone, double budget)
		{
			this._name = name;
			this._phone = phone;
			this._budget = budget;
		}

		public string Name
		{
			get { return _name; }
			set { _name = value; }
		}

		public string Phone
		{
			get { return _phone; }
			set { _phone = value; }
		}

		public double Budget
		{
			get { return _budget; }
			set { _budget = value; }
		}
	}
}
