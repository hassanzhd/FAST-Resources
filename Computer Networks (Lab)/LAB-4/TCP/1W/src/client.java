import java.io.*;
import java.net.*;

class client {
	public static void main(String args[])throws IOException {
		Socket s=new Socket("localHost", 8000);
		DataInputStream in=new DataInputStream(s.getInputStream());
	
		while(true) {	
			String str=in.readLine();
			System.out.println("Message Received:" + str);
	
			if(str.equals("end")) {
				s.close();
				break;
			}
		}
	}
}