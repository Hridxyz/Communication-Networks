#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int NUM_SLOTS = 10;
const int FRAME_SIZE = 5;
const double PROBABILITY = 0.5;

class Packet {
private:
    int id;
public:
    Packet(int identifier) : id(identifier) {}
    int getID() const { return id; }
};

class SlottedALOHA {
private:
    Packet* slots[NUM_SLOTS];
public:
    SlottedALOHA() {
        for (int i = 0; i < NUM_SLOTS; i++) {
            slots[i] = nullptr;
        }
    }

    bool isSlotEmpty(int slotIndex) const {
        return slots[slotIndex] == nullptr;
    }

    void sendPacket(Packet* packet, int slotIndex) {
        if (isSlotEmpty(slotIndex)) {
            slots[slotIndex] = packet;
            cout << "Packet " << packet->getID() << " sent in slot " << slotIndex << endl;
        } else {
            cout << "Collision occurred in slot " << slotIndex << ", packet " << packet->getID() << " discarded." << endl;
        }
    }

    void simulateTransmission() {
        srand(time(nullptr));
        for (int i = 0; i < FRAME_SIZE; i++) {
            if (rand() < PROBABILITY * RAND_MAX) {
                Packet* newPacket = new Packet(i + 1);
                int slotIndex = rand() % NUM_SLOTS;
                sendPacket(newPacket, slotIndex);
            }
        }
    }

    void displaySlots() const {
        for (int i = 0; i < NUM_SLOTS; i++) {
            if (slots[i] == nullptr) {
                cout << "Slot " << i << ": Empty" << endl;
            } else {
                cout << "Slot " << i << ": Packet " << slots[i]->getID() << endl;
            }
        }
    }
};

int main() {
    SlottedALOHA aloha;
    aloha.simulateTransmission();
    aloha.displaySlots();

    return 0;
}
