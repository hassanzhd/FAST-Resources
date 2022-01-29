using System;

namespace Iterator
{
	class Item
	{
		private string _name;

		public Item(string name)
		{
			this._name = name;
		}

		public string Name
		{
			get { return _name; }
		}
	}
}
