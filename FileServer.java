import java.io.*;
import java.net.*;

public class FileServer {
    public static void main(String[] args) {
        // define the port
        int port = 9090;
        String filename = "Send.txt";

        try (ServerSocket serverSocket = new ServerSocket(port);
             Socket socket = serverSocket.accept();
             FileInputStream fileInputStream = new FileInputStream(filename);
             OutputStream outputStream = socket.getOutputStream()) {

            byte[] buffer = new byte[4096];
            int bytesRead;

            while ((bytesRead = fileInputStream.read(buffer)) != -1) {
                outputStream.write(buffer, 0, bytesRead);
            }

            System.out.println("File " + filename + " sent to client.");

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}