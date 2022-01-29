using System;

namespace State
{
	class SilverState : State
	{
		public SilverState(State state) : this(state.Balance, state.Account)
		{
		}

		public SilverState(double balance, Account account)
		{
			this.balance = balance;
			this.account = account;
			Initialize();
		}

		private void Initialize()
		{
			interest = 0.0;
			lowerLimit = 0.0;
			upperLimit = 1000.0;
		}

		public override void Deposit(double amount)
		{
			balance += amount;
			StateChangeCheck();
		}

		public override void Withdraw(double amount)
		{
			balance -= amount;
			StateChangeCheck();
		}

		public override void PayInterest()
		{
			balance += interest * balance;
			StateChangeCheck();
		}

		private void StateChangeCheck()
		{
			if (balance < lowerLimit)
			{
				account.State = new RedState(this);
			}
			else if (balance > upperLimit)
			{
				account.State = new GoldState(this);
			}
		}
	}
}
