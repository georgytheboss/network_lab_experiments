// javac udpserver.java;java udpserver
import java.io.*;
import java.net.*;
import java.util.Scanner;

public class udpserver{
	public static void main(String args[]){
		try{
			DatagramSocket ds = new DatagramSocket(3000);
			byte buf[]=new byte[1024];
			DatagramPacket dp = new DatagramPacket(buf,1024);
			ds.receive(dp);
			String msg = new String(dp.getData(),0,dp.getLength());
			System.out.print("Received message "+msg);
			String  msg2,rev = "";
			int length = msg.length();
			for(int i=length-1;i>=0;i--)
				rev = rev + msg.charAt(i);
			if (msg.equals(rev))
				msg2=" is a palindrome\n";
			else
				msg2=" is not a palindrome\n";
			System.out.print(msg2);
			InetAddress ip = InetAddress.getByName("127.0.0.1");
			DatagramSocket ds2 = new DatagramSocket();
			DatagramPacket dp2 = new DatagramPacket(msg2.getBytes(),msg2.length(),ip,4000);
			ds2.send(dp2);
			}

		catch(Exception e){
			System.out.println("Error");
			}
		}
	}