using System;

namespace Prototype
{
	class Color : ColorPrototype
	{
		private int _red;
		private int _green;
		private int _blue;

		public Color(int red, int green, int blue)
		{
			this._red = red;
			this._green = green;
			this._blue = blue;
		}

		public override ColorPrototype Clone()
		{
			Console.WriteLine("Cloning color RGB: {0,3},{1,3},{2,3}", _red, _green, _blue);
			return this.MemberwiseClone() as ColorPrototype;
		}
	}
}
