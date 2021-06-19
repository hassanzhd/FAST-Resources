import java.io.*;
import java.net.*;

class reciever{
	public static void main(String args[])throws Exception {
		DatagramSocket ds;
		DatagramPacket dp;
		byte buff[]=new byte[1024];
		String str;
		ds=new DatagramSocket(8000);
		
		while(true) {
			dp=new DatagramPacket(buff,buff.length);
			ds.receive(dp);
			str=new String (dp.getData(),0,0,dp.getLength());
			System.out.println(str);
			System.out.println("InetAddress:"+dp.getAddress());
		}
	}
}
