#include <iostream>
using namespace std;
const int MAX_SIZE = 5;

class CircularQueue {
private:
    int queue[MAX_SIZE];
    int front;
    int rear;
    int size;
    int orderNumber;  // New variable to represent the order number

public:
    CircularQueue() {
        front = rear = -1;
        size = MAX_SIZE;
        orderNumber = 1;  // Start order numbers from 1
    }

    bool isFull() {
        return (front == 0 && rear == size - 1) || (rear == front - 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue() {
        if (isFull()) {
            cout << "Queue is full. Cannot accept more orders." << endl;
            return;
        }
        if (front == -1)
            front = 0;

        rear = (rear + 1) % size;
        queue[rear] = orderNumber;
        cout << "Order #" << orderNumber << " placed successfully." << endl;
        orderNumber++;  // Increment the order number
    }

    void serveOrder() {
        if (isEmpty()) {
            cout << "Queue is empty. No orders to serve." << endl;
            return;
        }
        int servedOrder = queue[front];
        cout << "Serving Order #" << servedOrder << endl;
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % size;
    }

    void displayOrders() {
        if (isEmpty()) {
            cout << "No pending orders." << endl;
            return;
        }

        cout << "Pending Orders: ";
        int i = front;
        do {
            cout << queue[i] << " ";
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);
        cout << endl;
    }
};

int main() {
    CircularQueue queue;
    int choice;
    cout << "\nPizza Parlour Menu:" << endl;
    cout << "1. Place an order" << endl;
    cout << "2. Serve an order" << endl;
    cout << "3. Display pending orders" << endl;
    cout << "4. Quit" << endl;
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (queue.isFull()) {
                    cout << "Maximum order limit reached. Cannot accept more orders." << endl;
                } else {
                    queue.enqueue();
                }
                break;
            case 2:
                queue.serveOrder();
                break;
            case 3:
                queue.displayOrders();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }
    return 0;
}
