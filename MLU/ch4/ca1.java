import java.io.*;
import java.net.*;

public class ca1
{
	public static void main(String[] args)
	{
		if(args.length!=2)
		{			
			System.exit(0);
		}
		try
		{
			int p=Integer.parseInt(args[0]);
			String msg=args[1];
			ServerSocket cnk= new ServerSocket(p);
			MyStream ds=new MyStream(cnk.accept());
			ds.sendmsg(msg);
			ds.close();
			cnk.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}
