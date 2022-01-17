using System;

namespace Week07_ProxyPattern2
{
    public interface IMath
    {
        double Add(double x, double y);
        double Sub(double x, double y);
        double Mul(double x, double y);
        double Div(double x, double y);
    }

    class Math : IMath
    {
        public double Add(double x, double y) { return x + y; }
        public double Sub(double x, double y) { return x - y; }
        public double Mul(double x, double y) { return x * y; }
        public double Div(double x, double y) { return x / y; }
    }

    class MathProxy : IMath
    {
        private Math _math = new Math();

        public double Add(double x, double y)
        {
            return _math.Add(x, y);
        }
        public double Sub(double x, double y)
        {
            return _math.Sub(x, y);
        }
        public double Mul(double x, double y)
        {
            return _math.Mul(x, y);
        }

        public double Exponent(double x, double y)
        {
            double result = x;
            if (y == 0) return 1;
            for (int i = 1; i < y; i++)
            {
                result = _math.Mul(result, x);
            }
            return result;
        }
        public double Div(double x, double y)
        {
            return _math.Div(x, y);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            MathProxy proxy = new MathProxy();
            // Do the math
            Console.WriteLine("4 + 2 = " + proxy.Add(4, 2));
            Console.WriteLine("4 - 2 = " + proxy.Sub(4, 2));
            Console.WriteLine("4 * 2 = " + proxy.Mul(4, 2));
            Console.WriteLine("4 / 2 = " + proxy.Div(4, 2));
            Console.WriteLine("5 ^ 4 = " + proxy.Exponent(5, 4));
            // Wait for user
            Console.ReadKey();
        }
    }
}
