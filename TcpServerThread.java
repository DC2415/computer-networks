
import java.net.*;
import java.io.*;
import java.util.*;

public class TcpServerThread {
    public static void main(String args[]) {
        try {
            ServerSocket ss = new ServerSocket(1559);
            System.out.println("SERVER PORT CREATED ");

            while (true) {
                Socket sc = ss.accept();
                System.out.println("Connection Established ");

                // Create a new thread to handle the client
                ClientHandler clientHandler = new ClientHandler(sc);
                Thread thread = new Thread(clientHandler);
                thread.start();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

class ClientHandler implements Runnable {
    private Socket socket;

    public ClientHandler(Socket socket) {
        this.socket = socket;
    }

    public void run() {
        try {
            InputStream is = socket.getInputStream();
            OutputStream os = socket.getOutputStream();
            System.out.println("STREAMS CREATED ");
            String reply = null;
            Scanner s = new Scanner(is);
            System.out.println("Reading request");
            String req = s.next();
            System.out.println("NUMBER RECEIVED is: " + req);
            int num = Integer.parseInt(req);
            boolean flag = false;
            for (int i = 2; i <= num / 2; i++) {
                if (num % i == 0) {
                    flag = true;
                    break;
                }
            }
            if (flag == false) {
                reply = "It is a Prime number";
            } else {
                reply = "It is not a Prime Number";
            }
            PrintWriter pw = new PrintWriter(os, true);
            pw.println(reply);

            // Close the socket after processing client request
            socket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
