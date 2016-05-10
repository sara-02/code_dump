import java.io.*;
import java.net.*;

public class sr1
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
			Mydata msc=new Mydata(port+1);
			msc.connect(h,port); //comment for removing connected udp
			for(int i=0;i<=3;i++)//comment for removinf connected udp
			msc.sendmsg(h,port,m);
			m=msc.revmsg();
			System.out.println(m);
			msc.disconnect();
			msc.close();		
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}
