import java.io.*;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;

public class MulticastSendUDP {
    public static void main(String[] args) throws IOException {
        if (args.length < 3) {
            System.out.println("Usage: java MulticastSendUDP <adresse_groupe> <port> <message>");
            System.exit(1);
        }

        int dstPort = Integer.parseInt(args[1]);
        MulticastSocket s = new MulticastSocket(dstPort);

        InetAddress group = InetAddress.getByName(args[0]);
        s.joinGroup(group);
        
        String message = args[2];
        byte[] buf = message.getBytes();

        DatagramPacket p = new DatagramPacket(buf, buf.length, group, dstPort);
        s.send(p);

        s.leaveGroup(group);
        s.close();
    }
}