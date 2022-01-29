using System;

namespace Interpreter
{
	class OneExpression : Expression
	{
		public override string One() { return "I"; }
		public override string Four() { return "IV"; }
		public override string Five() { return "V"; }
		public override string Nine() { return "IX"; }
		public override int Multiplier() { return 1; }
	}
}
