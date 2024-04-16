#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_BACKOFF = 10;
const int NUM_STATIONS = 5;

int generateRandom(int min, int max) {
    return min + rand() % (max - min + 1);
}

void simulateCSMA_CA_0_Persistent(int stationId) {
    cout << "Station " << stationId << " wants to transmit." << endl;
    bool isChannelBusy = generateRandom(0, 1);
    if (isChannelBusy) {
        cout << "Channel is busy. Station " << stationId << " will wait for the channel to become idle." << endl;
        int backoffTime = generateRandom(0, MAX_BACKOFF);
        cout << "Station " << stationId << " will wait for " << backoffTime << " time units." << endl;
        while (backoffTime > 0) {
            backoffTime--;
            cout << ".";
        }
        cout << endl;
        simulateCSMA_CA_0_Persistent(stationId);
    } else {
        cout << "Channel is idle. Station " << stationId << " starts transmitting." << endl;
        bool ackReceived = generateRandom(0, 1);
        if (ackReceived) {
            cout << "Acknowledgment received. Transmission successful for station " << stationId << "." << endl;
        } else {
            cout << "No acknowledgment received. Collision occurred for station " << stationId << "." << endl;
            int backoffTime = generateRandom(0, MAX_BACKOFF);
            cout << "Station " << stationId << " will wait for " << backoffTime << " time units due to collision." << endl;
            while (backoffTime > 0) {
                backoffTime--;
                cout << ".";
            }
            cout << endl;
            simulateCSMA_CA_0_Persistent(stationId);
        }
    }
}

int main() {
    srand(time(0));
    for (int i = 1; i <= NUM_STATIONS; i++) {
        simulateCSMA_CA_0_Persistent(i);
        cout << endl;
    }

    return 0;
}
