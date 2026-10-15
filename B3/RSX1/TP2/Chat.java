import java.io.*;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;
import java.util.Scanner;

public class Chat {
    public static void main(String[] args) throws IOException {
        if (args.length < 3) {
            System.out.println("Usage: java MulticastChat <adresse_groupe> <port> <nom_symbolique>");
            System.exit(1);
        }

        int dstPort = Integer.parseInt(args[1]);
        MulticastSocket s = new MulticastSocket(dstPort);

        String group_str = args[0];
        InetAddress group = InetAddress.getByName(group_str);
        s.joinGroup(group);
        
        String username = args[2];

        // Fonctionnalité de recevoir, utilisant une expression lambda
        Thread receiver = new Thread(() -> {
            try {
                while (true) {
                    DatagramPacket p = new DatagramPacket(new byte[1024], 1024);
                    s.receive(p);
                    System.out.println(new String(p.getData()));
                }
            }
            catch (IOException e) {
                // terminer thread, fermer socket
                // e.printStackTrace();
            }
        });
        receiver.start();

        // Fonctionnalité d'émettre
        String machineName = InetAddress.getLocalHost().getHostName();
        String fullName = machineName + "@" + username;

        Scanner keyboard = new Scanner(System.in);
        System.out.println("Connecté au groupe " + group_str + " sur le port " + dstPort + ". Terminer en tapant \"exit\" sans apostrophes.");
        
        String line;
        while (!(line = keyboard.nextLine()).trim().equalsIgnoreCase("exit")) {
            if (line.trim().equals("")) continue; // envoyer rien au cas où l'utilisateur ne tape rien
            byte[] buf = (fullName + " | " + line).getBytes();
            DatagramPacket p = new DatagramPacket(buf, buf.length, group, dstPort);
            s.send(p);
        }

        s.leaveGroup(group);
        s.close();
    }
}
