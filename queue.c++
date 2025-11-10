/*Implement a real-time event processing system using a Queue data structure. The system
should support the following features:
• Add an Event: When a new event occurs, it should be added to the event queue.
• Process the Next Event: The system should process and remove the event that has
been in the queue the longest.
• Display Pending Events: Show all the events currently waiting to be processed.
• Cancel an Event: An event can be canceled if it has not been processed
*/

#include <iostream>
#include<string>
# define SIZE 100
using namespace std;



string queue[SIZE];
int front = -1;
int rear = -1;


void enqueue() {
    
    if (rear == SIZE - 1) {
        cout << "Queue is fulled" << endl;
        return;
    }

    if (front == -1) front = 0; 

    cin.ignore();
    string value;
    cout<<"Enter an event"<<endl;
    getline(cin,value);
    rear++;
    queue[rear] = value;
    cout << "Enqueued: " << value << endl;
}


void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Dequeued: " << queue[front] << endl;
    front++;

    if (front > rear) { 
        front = rear = -1;
    }
}



void cancel() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty" << endl;
        return;
    }

    cin.ignore();
    string event;
    cout << "Enter the event to cancel: ";
    getline(cin, event);

    bool found = false;
    for (int i = front; i <= rear; i++) {
        if (queue[i] == event) {
            for (int j = i; j < rear; j++) {
                queue[j] = queue[j + 1];
            }
            rear--;
            found = true;
            cout << "Event canceled: " << event << endl;
            break;
        }
    }
    if (!found) cout << "Event not found in queue" << endl;
}


void display() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Queue is : ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}


int main() {
  

int choice=0;
string value;

while(choice !=5 ){
    cout<<"----menu----"<<endl;
    cout<<"1: Add an event"<<endl;
    cout<<"2: process the Next Event"<<endl;
    cout<<"3: display "<<endl;
    cout<<"4: cancel event"<<endl;
    cout<<"5: exit"<<endl;

    cout<<"Enter choice";
    cin>>choice;
    
    switch (choice)
    {
        case 1:
        cout<<"selected choice 1 "<<endl;  
        enqueue();    
        break;
        case 2:
        cout<<"selected choice 2 "<<endl;
        dequeue();
        break;
        case 3:
        cout<<"selected choice 3"<<endl;
        display();
        break;
        case 4: 
        cout<<"selected choice 4"<<endl;
        cancel();
        break;
        case 5:
        cout<<"exit";
        break;

        default:
        cout<<"enter a valid choice"<<endl;

    }

    
}
}


