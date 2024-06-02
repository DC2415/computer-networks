#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int n, i, c, j, count = 0;

    printf("Enter the String: ");
    scanf("%s", str);

   printf("Enter the number of frames: ");
    scanf("%d", &n);

    int frames[n];

    printf("Enter the size of the frames:\n");

    for (i = 0; i < n; i++) {
        printf("Frame %d: ", i + 1);
        scanf("%d", &frames[i]);
    }

   printf("\nThe number of frames: %d\n", n);

    for (i = 0; i < n; i++) {
        printf("\nThe content of frame %d: ", i + 1);

        j = 0;
        while (str[c] != '\0' && j < frames[i]) {
            printf("%c", str[c]);
            count++;
            c++;
            j++;
        }

        printf("\nSize of frame %d: %d\n", i + 1, count);
        count = 0;
    }

    return 0;
} 
