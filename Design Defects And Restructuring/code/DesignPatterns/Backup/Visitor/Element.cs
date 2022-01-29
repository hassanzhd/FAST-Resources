using System;

namespace Visitor
{
	abstract class Element
	{
		public abstract void Accept(IVisitor visitor);
	}
}
