using System;

namespace Visitor
{
	class VacationVisitor : IVisitor
	{
		public void Visit(Element element)
		{
			Employee employee = element as Employee;

			Console.WriteLine("{0} {1}'s new vacation days: {2}", employee.GetType().Name, employee.Name, employee.VacationDays);
		}
	}
}
