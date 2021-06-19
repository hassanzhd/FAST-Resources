import java.io.*;
import java.net.*;
class server {
	public static void main(String a[])throws IOException {
		ServerSocket ss=new ServerSocket(8000);
		Socket s=ss.accept();
		
		DataInputStream messageSentStream=new DataInputStream(System.in);
		PrintStream dos=new PrintStream(s.getOutputStream());
		
		DataInputStream messageRecievedStream=new DataInputStream(s.getInputStream());
		
		
		while(true) {
			System.out.println("enter message to send:");
			String messageSent=messageSentStream.readLine();
			dos.println(messageSent);
			
			String messageRecieved=messageRecievedStream.readLine();
			System.out.println("Message Received:" + messageRecieved);
			
			
			if(messageSent.equals("end")) {
				ss.close();
				break;
			}
			
			
		}
	}
}