import java.io.*;
import java.net.*;

public class s1
{
	public static void main(String [] args)
	{
		if(args.length!=3)
		{
			System.out.println("Error in args listed");
			System.exit(0);	
		}
		try
		{
			InetAddress h=InetAddress.getByName(args[0]);
			int port=Integer.parseInt(args[1]);
			String m=args[2];
			
			DatagramSocket s= new DatagramSocket();
			DatagramPacket p=new DatagramPacket(m.getBytes(),m.length(),h,port);
			s.send(p);
			s.close();		
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}
