import java.io.*;
import java.net.*;

public class ServerOneWay {
    public static void main(String[] args) {
        try {
            ServerSocket serverSocket = new ServerSocket(9090); 
            System.out.println("Server listening on port 9090...");

            while (true) {
                Socket clientSocket = serverSocket.accept(); 
                System.out.println("Client connected: " + clientSocket.getInetAddress().getHostAddress());

                // Send response to the client
                PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
                out.println("Hello, Client! This is the server response.");

                // Close the socket and wait for the next client
                clientSocket.close();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
