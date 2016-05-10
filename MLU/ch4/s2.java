import java.io.*;
import java.net.*;

public class s2
{
	public static void main(String [] args)
	{
		if(args.length!=1)
		{
			System.out.println("Error in args listed");
			System.exit(0);	
		}
		try
		{
			//InetAddress h=InetAddress.getByName(args[0]);
			int port=Integer.parseInt(args[0]);
			//String m=args[2];
			byte[] buff=new byte[100];
			DatagramSocket s= new DatagramSocket(port);
			DatagramPacket p=new DatagramPacket(buff,100);
			s.receive(p);
			String m=new String(buff);
			System.out.println(m);
			s.close();		
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}
