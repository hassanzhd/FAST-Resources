using System;
using System.Collections.Generic;

namespace Strategy
{
	abstract class SortStrategy
	{
		public abstract void Sort(List<string> list);
	}
}
