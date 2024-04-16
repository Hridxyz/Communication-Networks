#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void pureAloha(int numFrames, float frameArrivalProbability) {
    int successfulFrames = 0;
    srand(time(0));

    for (int i = 0; i < numFrames; i++) {
        if (rand() / static_cast<float>(RAND_MAX) <= frameArrivalProbability) {
            cout << "Frame " << i + 1 << " transmitted.\n";
            if (rand() / static_cast<float>(RAND_MAX) > frameArrivalProbability) {
                cout << "Collision detected for Frame " << i + 1 << ". Retransmitting...\n";
            } else {
                cout << "Frame " << i + 1 << " successfully transmitted.\n";
                successfulFrames++;
            }
        } else {
            cout << "Frame " << i + 1 << " not transmitted (empty slot).\n";
        }
    }

    float throughput = static_cast<float>(successfulFrames) / numFrames * 100;
    cout << "\nPure ALOHA Throughput: " << throughput << "%\n";
}

int main() {
    int numFrames;
    float frameArrivalProbability;

    cout << "Enter the number of frames to transmit: ";
    cin >> numFrames;

    cout << "Enter the frame arrival probability (between 0 and 1): ";
    cin >> frameArrivalProbability;

    if (frameArrivalProbability < 0 || frameArrivalProbability > 1) {
        cout << "Invalid probability. Please enter a value between 0 and 1.\n";
        return 1;
    }

    pureAloha(numFrames, frameArrivalProbability);

    return 0;
}
