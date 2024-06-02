#include <stdio.h>
#include <string.h>

char* manchester_encode(const char* data) {
    int len = strlen(data);
    char* encoded_data = malloc(2 * len + 1); 
    encoded_data[2 * len] = '\0';

    for (int i = 0; i < len; i++) {
        if (data[i] == '0') {
            strcat(encoded_data, "01");
        } else {
            strcat(encoded_data, "10");
        }
    }

    return encoded_data;
}

char* manchester_decode(const char* encoded_data) {
    int len = strlen(encoded_data) / 2;
    char* decoded_data = malloc(len + 1);
    decoded_data[len] = '\0';

    for (int i = 0; i < len; i++) {
        if (encoded_data[2 * i] == '0' && encoded_data[2 * i + 1] == '1') {
            decoded_data[i] = '0';
        } else if (encoded_data[2 * i] == '1' && encoded_data[2 * i + 1] == '0') {
            decoded_data[i] = '1';
        } else {
            
            free(decoded_data);
            return NULL;
        }
    }

    return decoded_data;
}

int main() {
    const char* data_to_encode = "1010";
    char* encoded_data = manchester_encode(data_to_encode);
    char* decoded_data = manchester_decode(encoded_data);

    printf("Original data: %s\n", data_to_encode);
    printf("Manchester encoded data: %s\n", encoded_data);
    printf("Decoded data: %s\n", decoded_data);

    free(encoded_data);
    free(decoded_data);

    return 0;
}
