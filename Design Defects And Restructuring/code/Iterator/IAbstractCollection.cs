using System;

namespace Iterator
{
	interface IAbstractCollection
	{
		IAbstractIterator CreateIterator();
	}
}
