import java.io.*;
import java.net.*;

public class ms1
{
	public static void main(String args[]) throws IOException
	{
		MulticastSocket s;
		InetAddress g;
		try
		{
			g=InetAddress.getByName("239.1.2.3");
			s=new MulticastSocket(3456);
			s.setTimeToLive(0);
			String m="Hello, I am Sarah.";
			DatagramPacket p=new DatagramPacket(m.getBytes(),m.length(),g,3456);
			s.send(p);
			s.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}
