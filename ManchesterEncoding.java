public class ManchesterEncoding {

    public static String manchesterEncode(String data) {
        StringBuilder encodedData = new StringBuilder();

        for (char bit : data.toCharArray()) {
            if (bit == '0') {
                encodedData.append("01");
            } else {
                encodedData.append("10");
            }
        }

        return encodedData.toString();
    }

    public static String manchesterDecode(String encodedData) {
        StringBuilder decodedData = new StringBuilder();

        for (int i = 0; i < encodedData.length(); i += 2) {
            char firstBit = encodedData.charAt(i);
            char secondBit = encodedData.charAt(i + 1);

            if (firstBit == '0' && secondBit == '1') {
                decodedData.append('0');
            } else if (firstBit == '1' && secondBit == '0') {
                decodedData.append('1');
            } else {
                // Invalid Manchester encoding
                throw new IllegalArgumentException("Invalid Manchester encoding");
            }
        }

        return decodedData.toString();
    }

    public static void main(String[] args) {
        String dataToEncode = "10101010";
        String encodedData = manchesterEncode(dataToEncode);
        String decodedData = manchesterDecode(encodedData);

        System.out.println("Original data: " + dataToEncode);
        System.out.println("Manchester encoded data: " + encodedData);
        System.out.println("Decoded data: " + decodedData);
    }
}
