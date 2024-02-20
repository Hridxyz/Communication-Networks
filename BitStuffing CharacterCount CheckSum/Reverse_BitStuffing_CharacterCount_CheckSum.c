#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>


void receiver(int[], int, int);
void bitUnstuffing();
void extractDataUsingCharCount();

int main() {
    char choice;
    printf("\n.....YOUR OPTIONS....\n");
    printf("\n a. Checksum Verification\n b. Bit Unstuffing\n c. Extract Data Using Character Count\n");
    printf("\nEnter your choice:");
    scanf(" %c", &choice);

    switch(choice) {
        case 'a':

            {
                int size, receivedChecksum;
                printf("\nENTER SIZE OF THE ARRAY: ");
                scanf("%d", &size);
                int data[size];
                printf("\nENTER THE ELEMENTS OF THE ARRAY: ");
                for(int i = 0; i < size; i++) {
                    scanf("%d", &data[i]);
                }
                printf("\nENTER RECEIVED CHECKSUM: ");
                scanf("%d", &receivedChecksum);
                receiver(data, size, receivedChecksum);
            }
            break;
        case 'b':

            bitUnstuffing();
            break;
        case 'c':

            extractDataUsingCharCount();
            break;
        default:
            printf("\nYou entered an invalid choice. Please run the program again.\n");
    }
    getch();
    return 0;
}


void receiver(int data[], int size, int receivedChecksum) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += data[i];
    }
    sum = (~sum) & 0xFF;
    if(sum == receivedChecksum) {
        printf("\nChecksum Verification Successful.\n");
    } else {
        printf("\nChecksum Verification Failed!\n");
    }
}

void bitUnstuffing() {
    char stuffedStr[100], unstuffedStr[100];
    printf("\nEnter the bit string for unstuffing: ");
    scanf("%s", stuffedStr);
    int count = 0, j = 0;
    for(int i = 0; stuffedStr[i] != '\0'; i++) {
        if(stuffedStr[i] == '1') {
            count++;
            unstuffedStr[j++] = '1';
        } else {
            unstuffedStr[j++] = '0';
            count = 0;
        }
        if(count == 5) {
            if(stuffedStr[i+1] == '0') {
                i++;
            }
            count = 0;
        }
    }
    unstuffedStr[j] = '\0';
    printf("\nAfter Bit Unstuffing: %s\n", unstuffedStr);
}

void extractDataUsingCharCount() {
    char frame[100];
    printf("\nEnter the frame: ");
    scanf("%s", frame);
    int len = frame[0] - '0';
    char data[100];
    strncpy(data, frame + 1, len - 1);
    data[len] = '\0';
    printf("\nExtracted Data: %s\n", data);
}
