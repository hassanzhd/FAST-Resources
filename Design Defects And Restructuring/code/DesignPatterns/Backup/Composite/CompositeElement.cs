using System;
using System.Collections.Generic;

namespace Composite
{
	class CompositeElement : DrawingElement
	{
		private List<DrawingElement> elements = new List<DrawingElement>();

		public CompositeElement(string name) : base(name)
		{
		}

		public override void Add(DrawingElement d)
		{
			elements.Add(d);
		}

		public override void Remove(DrawingElement d)
		{
			elements.Remove(d);
		}

		public override void Display(int indent)
		{
			Console.WriteLine(new String('-', indent) + "+ " + _name);

			foreach (DrawingElement d in elements)
			{
				d.Display(indent + 2);
			}
		}
	}
}
