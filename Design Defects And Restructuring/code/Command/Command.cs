using System;

namespace Command
{
	abstract class Command
	{
		public abstract void Execute();
		public abstract void UnExecute();
	}
}
