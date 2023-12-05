#include <iostream>
#include <vector>

using namespace std;

void displaySeats(const vector<vector<bool>> &seats) 
{
    for (int i = 0; i < seats.size(); ++i) 
    {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < seats[i].size(); ++j) 
        {
            if (seats[i][j]) 
            {
                cout << "A ";
            } 
            else 
            {
                cout << "B ";
            }
        }
        cout << "\n";
    }
}

void bookSeats(vector<vector<bool>> &seats) 
{
    int Num;
    int SB = 0;

    cout << "Enter the number of seats to book: ";
    cin >> Num;

    cout << "Enter the seats to book (e.g., 35 for Row 3, Seat 5): ";
    for (int i = 0; i < Num; ++i) 
    {
        int sn;
        cin >> sn;

        int row = sn / 10; 
        int col = sn % 10;

        if (row >= 1 && row <= seats.size() && col >= 1 && col <= seats[row - 1].size() && seats[row - 1][col - 1]) 
        {
            seats[row - 1][col - 1] = false;
            cout << "Seat " << row << col << " booked successfully.\n";
            SB++;
        } 
        else 
        {
            cout << "Invalid seat or seat already booked. Please try again.\n";
            --i;
        }
    }

    if (SB == Num) 
    {
        cout << "All seats booked successfully.\n";
    } 
    else 
    {
        cout << "Booking partially successful. Some seats may not be available.\n";
    }
}

void cancelSeats(vector<vector<bool>> &seats) 
{
    int Num;
    int SC = 0;

    cout << "Enter the number of seats to cancel: ";
    cin >> Num;

    cout << "Enter the seats to cancel (e.g., 35 for Row 3, Seat 5): ";
    for (int i = 0; i < Num; ++i) 
    {
        int sn;
        cin >> sn;

        int row = sn / 10;
        int col = sn % 10;

        if (row >= 1 && row <= seats.size() && col >= 1 && col <= seats[row - 1].size() && !seats[row - 1][col - 1]) 
        {
            seats[row - 1][col - 1] = true;
            cout << "Booking canceled successfully for Seat " << row << col << ".\n";
            SC++;
        }
        else 
        {
            cout << "Invalid seat or seat is not booked. Please try again.\n";
            --i;
        }
    }

    if (SC== Num) 
    {
        cout << "All bookings canceled successfully.\n";
    } 
    else
    {
        cout << "Cancellation partially successful. Some seats may not be booked.\n";
    }
}

int main() {
    const int rows = 10;
    const int cols = 7;

    // Initialize the seats array with all seats available
    vector<vector<bool>> seats(rows, vector<bool>(cols, true));

    // Example usage
    int choice;
    do {
        cout << "\n1. Display available seats and seat status\n2. Book seats\n3. Cancel booking\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displaySeats(seats);
                break;

            case 2:
                bookSeats(seats);
                break;

            case 3:
                cancelSeats(seats);
                break;

            case 0:
                cout << "\nThank you.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
