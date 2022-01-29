using System;

namespace Mediator
{
	class Program
	{
		static void Main(string[] args)
		{
			Chatroom chatroom = new Chatroom();

			Participant George = new Beatle("George");
			Participant Paul = new Beatle("Paul");
			Participant Ringo = new Beatle("Ringo");
			Participant John = new Beatle("John");
			Participant Yoko = new NonBeatle("Yoko");

			chatroom.Register(George);
			chatroom.Register(Paul);
			chatroom.Register(Ringo);
			chatroom.Register(John);
			chatroom.Register(Yoko);

			Yoko.Send("John", "Hi John!");
			Paul.Send("Ringo", "All you need is love");
			Ringo.Send("George", "My sweet Lord");
			Paul.Send("John", "Can't buy me love");
			John.Send("Yoko", "My sweet love");

			Console.ReadKey();
		}
	}
}
