using System;

namespace State
{
	abstract class State
	{
		protected Account account;
		protected double balance;
		protected double interest;
		protected double lowerLimit;
		protected double upperLimit;

		public Account Account
		{
			get { return account; }
			set { account = value; }
		}

		public double Balance
		{
			get { return balance; }
			set { balance = value; }
		}

		public abstract void Deposit(double amount);
		public abstract void Withdraw(double amount);
		public abstract void PayInterest();
	}
}
