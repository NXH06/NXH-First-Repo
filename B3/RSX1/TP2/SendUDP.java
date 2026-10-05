import java.io.*;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class SendUDP {
    public static void main(String[] args) throws IOException {
        if (args.length < 3) {
            System.out.println("Usage: java SendUDP <machine> <port> <message>");
            System.exit(1);
        }
        DatagramSocket s = new DatagramSocket();

        InetAddress dst = InetAddress.getByName(args[0]);
        int dstPort = Integer.parseInt(args[1]);
        String message = args[2];
        byte[] buf = message.getBytes();

        DatagramPacket p = new DatagramPacket(buf, buf.length, dst, dstPort);
        s.send(p);

        s.close();
    }
}