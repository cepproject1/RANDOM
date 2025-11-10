#include <iostream>
using namespace std;

struct Node {
    int key, value;
    Node* next;
};

Node* hashTable[10];   // size = 10

// Create new node
Node* createNode(int key, int value) {
    Node* temp = new Node();
    temp->key = key;
    temp->value = value;
    temp->next = NULL;
    return temp;
}

// Hash function
int hashFunc(int key) {
    return key % 10;
}

// Insert key-value pair
void insert(int key, int value) {
    int index = hashFunc(key);

    Node* newNode = createNode(key, value);

    // Insert at beginning of list (chaining)
    newNode->next = hashTable[index];
    hashTable[index] = newNode;

    cout << "Inserted (" << key << ", " << value << ") at index " << index << endl;
}

// Search key
void search(int key) {
    int index = hashFunc(key);
    Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->key == key) {
            cout << "Found! Value = " << temp->value << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Key not found!" << endl;
}

// Delete key
void deleteKey(int key) {
    int index = hashFunc(key);
    Node* temp = hashTable[index];
    Node* prev = NULL;

    while (temp != NULL) {
        if (temp->key == key) {

            if (prev == NULL)
                hashTable[index] = temp->next;  // first element
            else
                prev->next = temp->next;

            delete temp;
            cout << "Key deleted!" << endl;
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    cout << "Key not found!" << endl;
}

// Display hash table
void display() {
    cout << "\nHash Table:\n";
    for (int i = 0; i < 10; i++) {
        cout << i << ": ";
        Node* temp = hashTable[i];
        while (temp != NULL) {
            cout << "(" << temp->key << "," << temp->value << ") -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

int main() {
    int choice, key, value;

    // initialize table
    for (int i = 0; i < 10; i++)
        hashTable[i] = NULL;

    while (true) {
        cout << "\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                insert(key, value);
                break;

            case 2:
                cout << "Enter key to search: ";
                cin >> key;
                search(key);
                break;

            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                deleteKey(key);
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;
        }
    }
}