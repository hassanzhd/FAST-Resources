using System;

namespace Interpreter
{
	abstract class Expression
	{
		public void Interpret(Context context)
		{
			if (context.Input.Length == 0)
				return;

			if (context.Input.StartsWith(Nine()))
			{
				context.Output += (9 * Multiplier());
				context.Input = context.Input.Substring(2);
			}
			else if (context.Input.StartsWith(Four()))
			{
				context.Output += (4 * Multiplier());
				context.Input = context.Input.Substring(2);
			}
			else if (context.Input.StartsWith(Five()))
			{
				context.Output += (5 * Multiplier());
				context.Input = context.Input.Substring(1);
			}

			while (context.Input.StartsWith(One()))
			{
				context.Output += (1 * Multiplier());
				context.Input = context.Input.Substring(1);
			}
		}

		public abstract string One();
		public abstract string Four();
		public abstract string Five();
		public abstract string Nine();
		public abstract int Multiplier();
	}
}
