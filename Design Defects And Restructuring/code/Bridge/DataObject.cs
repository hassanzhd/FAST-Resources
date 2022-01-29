using System;

namespace Bridge
{
	abstract class DataObject
	{
		public abstract void NextRecord();
		public abstract void PriorRecord();
		public abstract void AddRecord(string name);
		public abstract void DeleteRecord(string name);
		public abstract void ShowRecord();
		public abstract void ShowAllRecords();
	}
}
