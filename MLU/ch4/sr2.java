import java.io.*;
import java.net.*;

public class sr2
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
			Mydata msc=new Mydata(port);
			msc.connect(h,port+1);
			for(int i=0;i<=3;i++) //comment for connected udp
			//String m=msc.revmsg();// uncomment for normal upd
			System.out.println(msc.revmsg());
			String m=args[2];
			//m=args[2]; uncomment fot normal upd
			msc.sendmsg(h,port+1,m);
			msc.close();		
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}
