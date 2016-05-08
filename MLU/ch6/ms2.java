import java.io.*;
import java.net.*;

public class ms2
{
	public static void main(String args[]) throws IOException
	{
		MulticastSocket s;
		InetAddress g;
		try
		{
			g=InetAddress.getByName("239.1.2.3");
			s=new MulticastSocket(3456);
			s.joinGroup(g);
			byte[] buff=new byte[100];
			DatagramPacket prc=new DatagramPacket(buff,buff.length);
			s.receive(prc);
			System.out.println(new String(buff));
			s.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}
