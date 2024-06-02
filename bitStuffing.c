#include <stdio.h>
#include <string.h>

int main() {
    int i, j = 8, c = 0, cl = 0;
    char s[100], res[110];

    printf("Enter a string: ");
    scanf("%s", s);

    strcpy(res, "01111110");
    strcat(res, " ");

    for (i = 0; i < strlen(s); i++) {
        res[j] = s[i];
        j++;

        if (s[i] == '1') {
            c++;
            if (c == 5) {
                res[j] = '0';
                j++;
                c = 0;
            }
        } else {
            c = 0;
        }
    }

    strcat(res, "01111110");

    printf("Stuffed string: %s\n", res);

    printf("Destuffed string: ");
    for (i = 8; i < strlen(res) - 8; i++) {
        if (res[i] == '1') {
            cl++;
        } else {
            cl = 0;
        }
        
        printf("%c", res[i]);

        if (cl == 5) {
            i++;
            cl = 0;
        }
    }

    printf("\n");

    return 0;
}
