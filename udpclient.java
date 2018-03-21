// javac udpclient.java; java udpclient
import java.io.*;
import java.net.*;

public class udpclient{
	public static void main(String args[]){
		try{ 
			InetAddress ip = InetAddress.getByName("127.0.0.1");
			DatagramSocket ds = new DatagramSocket();
			System.out.print("Enter message: ");
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String msg = br.readLine();
			DatagramPacket dp = new DatagramPacket(msg.getBytes(),msg.length(),ip,3000);
			ds.send(dp);
			DatagramSocket ds2 = new DatagramSocket(4000);
			byte buf[]=new byte[1024];
			DatagramPacket dp2 = new DatagramPacket(buf,1024);
			ds2.receive(dp2);
			String msg2 = new String(dp2.getData(),0,dp2.getLength());
			System.out.println("Message returned from Server ::"+msg+" "+msg2);
			}

		catch(Exception e){
			System.out.println("Error");
			}
		}
	}	