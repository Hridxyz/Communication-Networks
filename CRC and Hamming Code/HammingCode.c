#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(void) {
    unsigned int m = 0, r = 0, l = 0, x0 = 0;
    char d[1024] = {0};
    int d1[1024] = {0}, d2[1024] = {0};

    printf("Enter the message to be encoded, in binary format: ");
    scanf("%s", d); // Removed & since d is already an address

    // Message Length
    m = strlen(d);

    // Check bits (r)
    for (int i = 0; i < 20; i++) {
        r = i;
        if (m + 1 + i <= pow(2, i))
            break;
    }

    // Codeword length (l)
    l = m + r;

    // Testing the input in binary
    for (int i = 0; i < m; i++) {
        if (!(d[i] == '0' || d[i] == '1')) {
            printf("\nPlease enter the input message in binary only.\n");
            exit(0);
        }
    }

    printf("\nMessage length (m) = %d\n", m);
    printf("Redundancy bits (r) = %d\n", r);
    printf("Codeword length (l) = %d\n", l);

    // Initialization to zero not required as already initialized

    // Copying string array to int array, also shifting start index from 0 to 1
    for (int i = 0; i < m; i++) {
        d1[i + 1] = d[i] - '0';
    }

    // Shifting message bits into non-parity positions
    int j = 1;
    for (int i = 1; i <= l; i++) {
        double x = log(i) / log(2);
        if (x == (int)x) {
            d2[i] = 0; // Parity positions
        } else {
            d2[i] = d1[j++]; // Message positions
        }
    }

    // Finding parity bits
    for (int i = 1; i <= l; i++) {
        int x2t = i;
        for (int j = 0; j < r; j++) {
            int ipow = (int)pow(2, j);
            if (x2t & 1) d2[ipow] = d2[ipow] ^ d2[i];
            x2t = x2t >> 1;
        }
    }

    printf("Code word: ");
    for (int i = 1; i <= l; i++) {
        printf("%d", d2[i]);
    }
    printf("\n\n");

    return 0;
}
