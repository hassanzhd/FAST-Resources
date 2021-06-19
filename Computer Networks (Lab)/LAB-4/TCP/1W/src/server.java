import java.io.*;
import java.net.*;

class server {
	public static void main(String a[])throws IOException {
		ServerSocket ss=new ServerSocket(8000);
		Socket s=ss.accept();
		
		DataInputStream in=new DataInputStream(System.in);
		PrintStream dos=new PrintStream(s.getOutputStream());
		
		while(true) {
			System.out.println("enter message to send:");
			String str=in.readLine();
			
			dos.println(str);
			
			if(str.equals("end")) {
				ss.close();
				break;
			}
		}
	}
}