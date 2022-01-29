using System;

namespace ChainOfResp
{
	class Director : Approver
	{
		public override void ProcessRequest(Purchase purchase)
		{
			if (purchase.Amount < 10000.0)
			{
				Console.WriteLine("{0} approved request# {1}", this.GetType().Name, purchase.Number);
			}
			else if (successor != null)
			{
				successor.ProcessRequest(purchase);
			}
		}
	}
}
