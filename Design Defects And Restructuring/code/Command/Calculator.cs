using System;

namespace Command
{
	class Calculator
	{
		private int _curr = 0;

		public void Operation(char @operator, int operand)
		{
			switch (@operator)
			{
				case '+': _curr += operand; break;
				case '-': _curr -= operand; break;
				case '*': _curr *= operand; break;
				case '/': _curr /= operand; break;
			}

			Console.WriteLine("Current value = {0,3} (following {1} {2})", _curr, @operator, operand);
		}
	}
}
