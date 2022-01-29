using System;
using System.Collections.Generic;

namespace FactoryMethod
{
	abstract class Document
	{
		private List<Page> _pages = new List<Page>();

		public Document()
		{
			this.CreatePages();
		}

		public List<Page> Pages
		{
			get { return _pages; }
		}

		public abstract void CreatePages();
	}
}
