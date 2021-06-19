import java.io.*;
import java.net.*;

class sender {
	public void receive() throws IOException {
		DatagramSocket recievingDataGramSocket = new DatagramSocket(8000);
		Boolean continueRecieving = true;

		while (continueRecieving) {
			byte recievingBuffer[] = new byte[1024];
			DatagramPacket recievingDataGramPacket = new DatagramPacket(recievingBuffer, recievingBuffer.length);
			recievingDataGramSocket.receive(recievingDataGramPacket);
			String messageRecieved = new String(recievingDataGramPacket.getData(), 0, 0,
					recievingDataGramPacket.getLength());
			System.out.println(messageRecieved);
			System.out.println("InetAddress:" + recievingDataGramPacket.getAddress());

			if (messageRecieved.equals("exit")) {
				recievingDataGramSocket.close();
				continueRecieving = false;
			}
		}
	}

	public void send() throws IOException {
		Boolean continueSending = true;
		DatagramSocket sendingDataGramSocket = new DatagramSocket();
		DataInputStream messageSendingStream = new DataInputStream(System.in);

		while (continueSending) {
			byte sendingBuffer[] = new byte[1024];
			System.out.println("Enter the msg:");
			String messageToSend = messageSendingStream.readLine();
			sendingBuffer = messageToSend.getBytes();

			DatagramPacket sendingDataGDatagramPacket = new DatagramPacket(sendingBuffer, sendingBuffer.length,
					InetAddress.getLocalHost(), 8001);
			sendingDataGramSocket.send(sendingDataGDatagramPacket);

			if (messageToSend.equals("exit")) {
				sendingDataGramSocket.close();
				continueSending = false;
			}

		}

	}

	public static void main(String args[]) throws Exception {
		sender client = new sender();
		client.send();
		client.receive();
	}
}
