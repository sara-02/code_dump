import java.net.*;
import java.io.*;

public class MyStream extends Socket
{
	private Socket socket;
	private BufferedReader in;
	private PrintWriter ot;
	
	MyStream(String h, int p) throws SocketException,IOException
	{
		socket=new Socket(h,p);
		setstreams();
	}
	MyStream(Socket socket) throws SocketException,IOException
	{
		this.socket=socket;
		setstreams();
	}
	
	private void setstreams() throws IOException
	{
		InputStream ins=socket.getInputStream();
		in=new BufferedReader(new InputStreamReader(ins));
		OutputStream ost=socket.getOutputStream();
		ot=new PrintWriter(new OutputStreamWriter(ost));
	}
	public void sendmsg(String m) throws IOException
	{
		ot.println(m);
		ot.flush();
	}
	public String revmsg() throws IOException
	{
		String ms=in.readLine();
		return ms;
	}
	public void close() throws IOException
	{
		socket.close();
	}
}
