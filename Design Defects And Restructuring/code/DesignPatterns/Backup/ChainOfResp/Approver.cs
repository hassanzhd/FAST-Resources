using System;

namespace ChainOfResp
{
	abstract class Approver
	{
		protected Approver successor;

		public void SetSuccessor(Approver successor)
		{
			this.successor = successor;
		}

		public abstract void ProcessRequest(Purchase purchase);
	}
}
