using System;

namespace Visitor
{
	interface IVisitor
	{
		void Visit(Element element);
	}
}
