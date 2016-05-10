import java.io.*;
import java.net.*;

public class Mydata extends DatagramSocket
{
	Mydata(int pn) throws SocketException
	{
		super(pn);
	}

	public void sendmsg(InetAddress h, int pm, String m) throws IOException
	{
		DatagramPacket d=new DatagramPacket(m.getBytes(),m.length(),h,pm);
		this.send(d);
	}
	public String revmsg() throws IOException
	{
		byte[] buff=new byte[100];
		DatagramPacket d=new DatagramPacket(buff,100);
		this.receive(d);
		String msg=new String(buff);
		return msg;
	}
}

