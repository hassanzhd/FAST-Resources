using System;

namespace Bridge
{
	class CustomersBase
	{
		private DataObject _dataObject;
		protected string group;

		public CustomersBase(string group)
		{
			this.group = group;
		}

		public DataObject Data
		{
			set { _dataObject = value; }
			get { return _dataObject; }
		}

		public virtual void Next()
		{
			_dataObject.NextRecord();
		}

		public virtual void Prior()
		{
			_dataObject.PriorRecord();
		}

		public virtual void Add(string customer)
		{
			_dataObject.AddRecord(customer);
		}

		public virtual void Delete(string customer)
		{
			_dataObject.DeleteRecord(customer);
		}

		public virtual void Show()
		{
			_dataObject.ShowRecord();
		}

		public virtual void ShowAll()
		{
			Console.WriteLine("Customer Group: " + group);
			_dataObject.ShowAllRecords();
		}
	}
}
