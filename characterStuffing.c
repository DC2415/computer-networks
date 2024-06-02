#include <stdio.h>
#include <string.h>

int main() {
    int i, k = 0, n, j = 6;
    char s[100], res[200]="", a[100]="";

    printf("Enter the string: ");
    gets(s);

    strcpy(res, "dlestx");

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == 'd' && s[i + 1] == 'l' && s[i + 2] == 'e') {
            res[j] = 'd';
            res[j + 1] = 'l';
            res[j + 2] = 'e';
            j = j + 3;
           // i = i + 2; // Skip the next two characters in the original string
        } 
            res[j] = s[i];
            j++;
        
    }

    strcat(res, "dleetx");
    printf("Stuffed char: %s\n", res);

    n = strlen(res);

    for (i = 6; i < n - 6; i++) {
        if (res[i] == 'd' && res[i + 1] == 'l' && res[i + 2] == 'e') {
            i = i + 3; // Skip the next two characters in the stuffed string
        }
            a[k] = res[i];
            k++;
        
    }

                                                                                                           *//

    printf("Destuffed char: %s\n", a);

    return 0;
}
