#include <iostream>
using namespace std;

struct Sender {
    int PacketNo;
    int Sent;
    int Acknowledged;
} S[6];

struct Receiver {
    int AcknowledgementNo;
    int Received;
    int AcknowledgementSent;
} R[6];

int main() {
    for (int i = 0; i < 6; i++) {
        S[i].Sent = 0;
        S[i].Acknowledged = 0;
        S[i].PacketNo = i;
    }

    for (int i = 1; i <= 6; i++) {
        R[i].AcknowledgementSent = 0;
        R[i].Received = 0;
        R[i].AcknowledgementNo = i;
    }

    int check4 = 0, check6 = 0;
    for (int i = 0; i < 6; i++) {
        cout << "\n\n Next Transmission";
        cout << "\n Sending PacketNo " << i << " from Sender";
        S[i].Sent = 1;
        cout << "\n Propagation Delay";
        if (i == 4 && check4 == 0) {
            R[i].Received = 0;
            check4 = 1; i--;
            cout << "\n Data PacketNo " << i << " not received.";
        } else {
            R[i].Received = 1;
            R[i].AcknowledgementSent = 1;
            cout << "\n Sending AcknowledgementNo " << i + 1 << " to Sender";
            cout << "\n Propagation Delay";
            if (i == 5 && check6 == 0) {
                S[i].Acknowledged = 0;
                check6 = 1; i--;
                cout << "\n Acknowledgement for DataPacketNo" << i << " not received";
            } else {
                S[i].Acknowledged = 1;
                cout << "\n Acknowledgement for PacketNo " << i << " Received";
            }
        }
    }
    return 0;
}
