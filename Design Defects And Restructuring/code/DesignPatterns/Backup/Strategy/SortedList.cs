using System;
using System.Collections.Generic;

namespace Strategy
{
	class SortedList
	{
		private List<string> _list = new List<string>();
		private SortStrategy _sortstrategy;

		public void SetSortStrategy(SortStrategy sortstrategy)
		{
			this._sortstrategy = sortstrategy;
		}

		public void Add(string name)
		{
			_list.Add(name);
		}

		public void Sort()
		{
			_sortstrategy.Sort(_list);

			foreach (string name in _list)
			{
				Console.WriteLine(" " + name);
			}
			Console.WriteLine();
		}
	}
}
