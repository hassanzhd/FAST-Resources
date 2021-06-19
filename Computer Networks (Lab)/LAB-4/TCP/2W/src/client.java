import java.io.*;
import java.net.*;

class client {
	public static void main(String args[])throws IOException {
		Socket s=new Socket("localHost",8000);
		
		DataInputStream messageRecievedStream=new DataInputStream(s.getInputStream());
		
		DataInputStream messageSentStream=new DataInputStream(System.in);
		PrintStream dos=new PrintStream(s.getOutputStream());
		
		
		while(true) {	
			String messageRecieved=messageRecievedStream.readLine();
			System.out.println("Message Received:"+messageRecieved);
	
			System.out.println("enter message to send:");
			String messageSent=messageSentStream.readLine();
			dos.println(messageSent);
			
			if(messageRecieved.equals("end")) {
				s.close();
				break;
			}
			
			
			
		}
	}
}