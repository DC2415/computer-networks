public class DifferentialManchesterEncod {

    public static int[] differentialManchesterEncode(int[] data) {
        int[] encodedData = new int[data.length * 2];
        int currentState = 0;

        for (int i = 0; i < data.length; i++) {
            if (data[i] == 0) {
                encodedData[i * 2] = currentState;
                encodedData[i * 2 + 1] = 1 - currentState;
            } else {
                encodedData[i * 2] = currentState;
                encodedData[i * 2 + 1] = currentState;
            }

            currentState = 1 - currentState;
        }

        return encodedData;
    }

    public static int[] differentialManchesterDecode(int[] encodedData) {
        int[] decodedData = new int[encodedData.length / 2];
        int currentState = 0;

        for (int i = 0; i < encodedData.length; i += 2) {
            if (encodedData[i] != encodedData[i + 1]) {
                decodedData[i / 2] = 0;
            } else {
                decodedData[i / 2] = 1;
            }

            currentState = 1 - currentState;
        }

        return decodedData;
    }

    public static void main(String[] args) {
        int[] dataToEncode = {1, 0, 1, 1, 0, 0, 1, 0};
        int[] encodedData = differentialManchesterEncode(dataToEncode);
        int[] decodedData = differentialManchesterDecode(encodedData);

        System.out.print("Original Data: ");
        for (int bit : dataToEncode) {
            System.out.print(bit + " ");
        }
        System.out.println();

        System.out.print("Encoded Data: ");
        for (int bit : encodedData) {
            System.out.print(bit + " ");
        }
        System.out.println();

        System.out.print("Decoded Data: ");
        for (int bit : decodedData) {
            System.out.print(bit + " ");
        }
        System.out.println();
    }
}
