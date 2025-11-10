#include <iostream>
using namespace std;

#define MAX 50   // maximum queue size

class CallQueue {
    int customerID[MAX];
    int callTime[MAX];
    int front, rear;

public:
    CallQueue() {
        front = -1;
        rear = -1;
    }

    // Add a call
    void addCall(int id, int time) {
        if (rear == MAX - 1) {
            cout << "Queue is FULL\n";
            return;
        }
        if (front == -1) front = 0;  // first element
        rear++;
        customerID[rear] = id;
        callTime[rear] = time;
        cout << "Call added: Customer " << id << " | Time " << time << " mins\n";
    }

    // Answer the first call
    void answerCall() {
        if (isQueueEmpty()) {
            cout << "No calls to answer.\n";
            return;
        }
        cout << "Answering Call -> Customer " << customerID[front]
             << ", Time: " << callTime[front] << " mins\n";

        front++;
        if (front > rear) { 
            front = rear = -1; // queue becomes empty
        }
    }

    // View all calls
    void viewQueue() {
        if (isQueueEmpty()) {
            cout << "Queue is Empty.\n";
            return;
        }

        cout << "\nCurrent Calls in Queue:\n";
        for (int i = front; i <= rear; i++) {
            cout << "Customer " << customerID[i]
                 << " | Call Time: " << callTime[i] << " mins\n";
        }
        cout << endl;
    }

    // Check if empty
    bool isQueueEmpty() {
        return (front == -1);
    }
};

int main() {
    CallQueue cq;
    int choice, id, time;

    while (true) {
        cout << "\n--- Call Center Menu ---\n";
        cout << "1. Add Call\n";
        cout << "2. Answer Call\n";
        cout << "3. View Queue\n";
        cout << "4. Check if Queue is Empty\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Customer ID: ";
                cin >> id;
                cout << "Enter Call Time (mins): ";
                cin >> time;
                cq.addCall(id, time);
                break;

            case 2:
                cq.answerCall();
                break;

            case 3:
                cq.viewQueue();
                break;

            case 4:
                if (cq.isQueueEmpty())
                    cout << "Queue is Empty\n";
                else
                    cout << "Queue is NOT Empty\n";
                break;

            case 5:
                return 0;

            default:
                cout << "Invalid Choice\n";
        }
    }
}
