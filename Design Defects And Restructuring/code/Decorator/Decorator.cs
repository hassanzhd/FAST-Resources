using System;

namespace Decorator
{
	abstract class Decorator : LibraryItem
	{
		protected LibraryItem libraryItem;

		public Decorator(LibraryItem libraryItem)
		{
			this.libraryItem = libraryItem;
		}

		public override void Display()
		{
			libraryItem.Display();
		}
	}
}
