import java.io.*;
import java.net.*;

public class mst2 implements Runnable
{
		InetAddress g=null;
		MulticastSocket s=null;
		int port=0;
		String msg;
		
		public mst2(InetAddress g, int port)
		{
			this.g=g;
			this.port=port;
		}
		public void run()
		{	
			try
			{
				//g=InetAddress.getByName("239.1.2.4");
				port=3457;
				s=new MulticastSocket(port);
				s.joinGroup(g);
				while(true)
				{
					byte[] data=new byte[1000];
					DatagramPacket prc=new DatagramPacket(data,data.length,g,port);
					s.receive(prc);
					System.out.println(new String(data));			
				}
				//msg="Hey there we are threaded!";
				
			}
			catch(Exception se)
			{
				se.printStackTrace();
			}
		}

}
