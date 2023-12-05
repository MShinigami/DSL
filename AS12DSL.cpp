#include <iostream>
using namespace std;

const int Size = 10;

class Deque {
private:
    int arr[Size];
    int front, rear;

public:
    Deque() : front(-1), rear(-1) {}

    bool isEmpty() {
        return (front == -1 && rear == -1);
    }

    bool isFull() {
        return (front == 0 && rear == Size - 1) || (front == rear + 1);
    }

    void insertFront(int value) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert at front.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = Size - 1;
        } else {
            front = (front - 1 + Size) % Size;
        }

        arr[front] = value;
        cout << value << " inserted at the front of the deque.\n";
    }

    void insertRear(int value) {
        if (isFull()) {
            cout << "Deque is full. Cannot insert at rear.\n";
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == Size - 1) {
            rear = 0;
        } else {
            rear = (rear + 1) % Size;
        }

        arr[rear] = value;
        cout << value << " inserted at the rear of the deque.\n";
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from front.\n";
            return;
        }

        cout << arr[front] << " deleted from the front of the deque.\n";

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % Size;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete from rear.\n";
            return;
        }

        cout << arr[rear] << " deleted from the rear of the deque.\n";

        if (front == rear) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + Size) % Size;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }

        cout << "Deque elements: ";
        int i = front;
        do {
            cout << arr[i] << " ";
            i = (i + 1) % Size;
        } while (i != (rear + 1) % Size);
        cout << endl;
    }
};

int main() {
    Deque dq;

    int choice, value;

    do {
        cout << "\n1. Insert at Front"
             << "\n2. Insert at Rear"
             << "\n3. Delete from Front"
             << "\n4. Delete from Rear"
             << "\n5. Display"
             << "\n0. Exit"
             << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at the front: ";
            cin >> value;
            dq.insertFront(value);
            break;
        case 2:
            cout << "Enter value to insert at the rear: ";
            cin >> value;
            dq.insertRear(value);
            break;
        case 3:
            dq.deleteFront();
            break;
        case 4:
            dq.deleteRear();
            break;
        case 5:
            dq.display();
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
