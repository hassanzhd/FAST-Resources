using System;

namespace Builder
{
	abstract class VehicleBuilder
	{
		protected Vehicle vehicle;

		public Vehicle Vehicle
		{
			get { return vehicle; }
		}

		public abstract void BuildFrame();
		public abstract void BuildEngine();
		public abstract void BuildWheels();
		public abstract void BuildDoors();
	}
}
