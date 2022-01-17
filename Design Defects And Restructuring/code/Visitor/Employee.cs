using System;

namespace Visitor
{
	class Employee : Element
	{
		private string _name;
		private double _income;
		private int _vacationDays;

		public Employee(string name, double income, int vacationDays)
		{
			this._name = name;
			this._income = income;
			this._vacationDays = vacationDays;
		}

		public string Name
		{
			get { return _name; }
			set { _name = value; }
		}

		public double Income
		{
			get { return _income; }
			set { _income = value; }
		}

		public int VacationDays
		{
			get { return _vacationDays; }
			set { _vacationDays = value; }
		}

		public override void Accept(IVisitor visitor)
		{
			visitor.Visit(this);
		}
	}
}
