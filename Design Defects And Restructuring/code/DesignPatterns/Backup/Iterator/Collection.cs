using System;
using System.Collections;

namespace Iterator
{
	class Collection : IAbstractCollection
	{
		private ArrayList _items = new ArrayList();

		public IAbstractIterator CreateIterator()
		{
			return new Iterator(this);
		}

		public int Count
		{
			get { return _items.Count; }
		}

		public object this[int index]
		{
			get { return _items[index]; }
			set { _items.Add(value); }
		}
	}
}
