#include <iostream>
using namespace std;

#define MaxIN 10

struct Order 
{
    int OrderNo;
    string itemName;
};

Order Queue[MaxIN];
int front = -1, rear = -1;

void enQueue(int OrderNo, string itemName) 
{
    if ((rear == MaxIN - 1 && front == 0) || (front == rear + 1)) {
        cout << "Sorry, the order list is full. Cannot accept more orders." << endl;
        return;
    }

    if (front == -1) 
    {
        front = 0;
    }

    if (rear == MaxIN - 1 && front != 0)
    {
        rear = -1;
    }

    rear++;
    Queue[rear].OrderNo = OrderNo;
    Queue[rear].itemName = itemName;
    cout << "Order placed successfully!" << endl;
}

void deQueue() 
{
    if (front == -1 && rear == -1) {
        cout << "No orders to serve. The list is empty." << endl;
        return;
    }

    cout << "Order served - Order Number: " << Queue[front].OrderNo << ", Item: " << Queue[front].itemName << endl;

    front++;

    if (front == MaxIN) 
    {
        front = 0;
    }

    if (front - 1 == rear) 
    {
        front = rear = -1;
    }
}

void display() 
{
    if (front == -1) 
    {
        cout << "No orders to pending. The list is empty." << endl;
        return;
    }

    int i = front;

    if (front <= rear) 
    {
        while (i <= rear) 
        {
            cout << "Order Number: " << Queue[i].OrderNo << ", Item: " << Queue[i].itemName << endl;
            i++;
        }
    } 
    else 
    {
        while (i <= MaxIN - 1) 
        {
            cout << "Order Number: " << Queue[i].OrderNo << ", Item: " << Queue[i].itemName << endl;
            i++;
        }

        i = 0;

        while (i <= rear) 
        {
            cout << "Order Number: " << Queue[i].OrderNo << ", Item: " << Queue[i].itemName << endl;
            i++;
        }
    }
}

int main() 
{
    int choice, OrderNo = 1;
    string menu[] = {"Regular Pizza", "Cheese Pizza", "Spicy Pizza", "Creamy Pizza", "Pasta", "Burger"};

    do 
    {
        cout << "\nMenu:\n";
        cout << "1) Select the Order\n";
        cout << "2) Serve Order\n";
        cout << "3) Pending Orders\n";
        cout << "4) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "\nMenu:\n";
                for (int i = 0; i < 6; i++) 
                {
                    cout << i + 1 << ") " << menu[i] << endl;
                }
                int itemChoice;
                cout << "Enter your choice: ";
                cin >> itemChoice;
                if (itemChoice >= 1 && itemChoice <= 6) 
                {
                    enQueue(OrderNo, menu[itemChoice - 1]);
                    OrderNo++;
                } 
                else 
                {
                    cout << "Invalid item choice. Please try again.\n";
                }
                break;

            case 2:
                deQueue();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting pizza parlour. Thank you\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}
