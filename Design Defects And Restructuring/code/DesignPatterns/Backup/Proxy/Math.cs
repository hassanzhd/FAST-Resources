using System;

namespace Proxy
{
	class Math : IMath
	{
		public double Add(double x, double y) { return x + y; }
		public double Sub(double x, double y) { return x - y; }
		public double Mul(double x, double y) { return x * y; }
		public double Div(double x, double y) { return x / y; }
	}
}
