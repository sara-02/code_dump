import java.io.*;
import java.net.*;

public class ca2
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
			String ach=args[1];
			//ServerSocket cnk= new ServerSocket(p);
			MyStream ds=new MyStream(ach,p);
			System.out.println(ds.revmsg());
			ds.close();
			//cnk.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
}
