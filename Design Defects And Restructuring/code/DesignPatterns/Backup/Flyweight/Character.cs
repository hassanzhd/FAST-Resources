using System;

namespace Flyweight
{
	abstract class Character
	{
		protected char symbol;
		protected int width;
		protected int height;
		protected int ascent;
		protected int descent;
		protected int pointSize;

		public abstract void Display(int pointSize);
	}
}
