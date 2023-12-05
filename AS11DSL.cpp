#include <iostream>
#include <vector>

#define MAX 10

using namespace std;

class Queue 
{
private:
    vector<string> data;
    int front, rear;

public:
    Queue() : data(MAX), front(-1), rear(-1) {}

    bool isEmpty() const 
    {
        return front == -1;
    }

    bool isFull() const 
    {
        return (rear + 1) % MAX == front;
    }

    void enqueue(const string& job)
    {
        if (!isFull()) 
        {
            rear = (rear + 1) % MAX;
            data[rear] = job;
            if (front == -1) 
            {
                front = rear;
            }
            cout << "Job added: " << job << endl;
        }
        else 
        {
            cout << "Queue is full. Job not added." << endl;
        }
    }

    string dequeue() 
    {
        if (!isEmpty()) 
        {
            string job = data[front];
            if (front == rear) 
            {
                front = rear = -1;
            } 
            else 
            {
                front = (front + 1) % MAX;
            }
            cout << "Job deleted: " << job << endl;
            return job;
        } 
        else 
        {
            cout << "Queue is empty. No job to delete." << endl;
            return NULL;
        }
    }

    void display() const
    {
        if (!isEmpty()) 
        {
            cout << "Current jobs in the queue:";
            int i = front;
            do 
            {
                cout << " " << data[i];
                i = (i + 1) % MAX;
            } while (i != (rear + 1) % MAX);
            cout << endl;
        } 
        else 
        {
            cout << "Job queue is empty." << endl;
        }
    }
};

int main() 
{
    Queue jobQueue;

    int choice;
    string job;
    do 
    {
        cout << "\n1. Insert Job\n2. Delete Job\n3. Display\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "Enter job data: ";
                cin.ignore();
                getline(cin, job);
                jobQueue.enqueue(job);
                break;

            case 2:
                jobQueue.dequeue();
                jobQueue.display();
                break;

            case 3:
                jobQueue.display();
                break;

            case 4:
                cout << "Exiting Program..." << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }

    }
    while (choice != 4);
    return 0;
}