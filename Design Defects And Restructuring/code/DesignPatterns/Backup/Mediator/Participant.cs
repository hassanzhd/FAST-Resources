using System;

namespace Mediator
{
	class Participant
	{
		private Chatroom _chatroom;
		private string _name;

		public Participant(string name)
		{
			this._name = name;
		}

		public string Name
		{
			get { return _name; }
		}

		public Chatroom Chatroom
		{
			set { _chatroom = value; }
			get { return _chatroom; }
		}

		public void Send(string to, string message)
		{
			_chatroom.Send(_name, to, message);
		}

		public virtual void Receive(string from, string message)
		{
			Console.WriteLine("{0} to {1}: '{2}'", from, Name, message);
		}
	}
}
