import java.io.*;
import java.net.*;

class sender {
	public static void main(String args[])throws IOException {
		byte buff[]=new byte[1024];
		String str,str1;
		
		DatagramSocket ds = new DatagramSocket();
		DataInputStream in=new DataInputStream(System.in);
		
		while(true) {			
			System.out.println("Enter the msg:");
			str=in.readLine();
			buff=str.getBytes();
			
			DatagramPacket dp = new DatagramPacket(buff, buff.length, InetAddress.getLocalHost(), 8000);
			ds.send(dp);
			
			System.out.println("do u want to continue:yes or no");
			str1=in.readLine();
			
			if(str1.equals("no")) {
				ds.close();
				break;
			}
		}
	}
}