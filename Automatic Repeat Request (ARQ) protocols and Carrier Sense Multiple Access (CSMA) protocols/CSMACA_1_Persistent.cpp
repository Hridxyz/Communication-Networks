#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class CSMA_CA {
private:
    bool channel_free;

public:
    CSMA_CA() : channel_free(true) {}

    bool isChannelFree() {
        return channel_free;
    }

    void sendPacket(int node_id) {
        if (isChannelFree()) {
            cout << "Node " << node_id << " detects channel is free, transmitting packet." << endl;
            channel_free = false;
            simulateTransmission();
            channel_free = true;
            cout << "Transmission complete." << endl;
        } else {
            cout << "Node " << node_id << " detects channel is busy, waiting for next slot." << endl;
        }
    }

    void simulateTransmission() {
        int delay = rand() % 5 + 1;
        for (int i = 0; i < delay; i++) {
            cout << "Slot " << i + 1 << ": Transmission in progress..." << endl;
        }
    }
};

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    CSMA_CA csma_ca;
    for (int i = 1; i <= 5; i++) {
        csma_ca.sendPacket(i);
    }

    return 0;
}
