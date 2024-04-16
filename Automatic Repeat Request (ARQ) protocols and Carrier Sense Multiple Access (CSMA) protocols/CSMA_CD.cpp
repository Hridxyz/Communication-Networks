#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Node {
private:
    int id;
    bool isTransmitting;

public:
    Node(int nodeId) : id(nodeId), isTransmitting(false) {}

    int getId() const {
        return id;
    }

    bool getIsTransmitting() const {
        return isTransmitting;
    }

    void setIsTransmitting(bool transmitting) {
        isTransmitting = transmitting;
    }

    void sendData(Node& destination) {
        if (!isTransmitting) {
            cout << "Node " << id << " is attempting to send data to Node " << destination.getId() << endl;
            int backoffTime = rand() % 10;
            cout << "Node " << id << " waits for " << backoffTime << " time units..." << endl;
            for (int i = 0; i < backoffTime; ++i) {
                cout << ".";
            }
            cout << endl;
            if (!destination.getIsTransmitting()) {
                cout << "Node " << id << " successfully sent data to Node " << destination.getId() << endl;
                destination.setIsTransmitting(true);
                isTransmitting = true;
            } else {
                cout << "Node " << id << " detected a collision with Node " << destination.getId() << endl;
                isTransmitting = false;
            }
        } else {
            cout << "Node " << id << " is already transmitting data." << endl;
        }
    }

    void receiveData() {
        if (isTransmitting) {
            cout << "Node " << id << " received data." << endl;
            isTransmitting = false;
        } else {
            cout << "Node " << id << " is not currently receiving data." << endl;
        }
    }
};

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    Node node1(1);
    Node node2(2);
    node1.sendData(node2);
    node2.receiveData();
    return 0;
}
