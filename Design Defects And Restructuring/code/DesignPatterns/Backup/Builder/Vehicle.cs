using System;
using System.Collections.Generic;

namespace Builder
{
	class Vehicle
	{
		private string _vehicleType;
		private Dictionary<string, string> _parts = new Dictionary<string, string>();

		public Vehicle(string vehicleType)
		{
			this._vehicleType = vehicleType;
		}

		public string this[string key]
		{
			get { return _parts[key]; }
			set { _parts[key] = value; }
		}

		public void Show()
		{
			Console.WriteLine("\n---------------------------");
			Console.WriteLine("Vehicle Type: {0}", _vehicleType);
			Console.WriteLine(" Frame : {0}", _parts["frame"]);
			Console.WriteLine(" Engine : {0}", _parts["engine"]);
			Console.WriteLine(" #Wheels: {0}", _parts["wheels"]);
			Console.WriteLine(" #Doors : {0}", _parts["doors"]);
		}
	}
}
