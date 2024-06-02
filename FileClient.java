import java.io.*;
import java.net.*;

public class FileClient {
    public static void main(String[] args) {
        String serverIP = "127.0.0.1";
        int port = 9090;
        String saveFilePath = "received.txt";

        try (Socket socket = new Socket(serverIP, port);
                InputStream inputStream = socket.getInputStream();
                FileOutputStream fileOutputStream = new FileOutputStream(saveFilePath)) {

            byte[] buffer = new byte[4096];
            int bytesRead;

            while ((bytesRead = inputStream.read(buffer)) != -1) {
                fileOutputStream.write(buffer, 0, bytesRead);
            }

            System.out.println("File received and saved as " + saveFilePath);

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}