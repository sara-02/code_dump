import java.io.*;
import java.net.*;

public class mst1
{
	public static void main(String args[]) throws IOException
	{
		InetAddress g=null;
		MulticastSocket s=null;
		int port=0;
		String msg;
		
		try
		{
			g=InetAddress.getByName("239.1.2.4");
			port=3457;
			msg="Hey there we are threaded!";
			DatagramPacket ps=new DatagramPacket(msg.getBytes(),msg.length(),g,port);
			Thread tt1=new Thread(new mst2(g,port));
			tt1.start();
			System.out.println("Press Enter to Start:");
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			br.readLine();
			s=new MulticastSocket(port);
			s.setTimeToLive(1);
			s.send(ps);
			s.close();
		}
		catch(Exception se)
		{
			se.printStackTrace();
		}
	}

}
