#include <iostream>
#include <string>

using namespace std;

struct Node {
    int prn;
    string name;
    Node* next;
};

class Division {
private:
    Node* head;

public:
    Division() {
        head = nullptr;
    }

    void addMember(int prn, string name) {
        Node* newNode = new Node;
        newNode->prn = prn;
        newNode->name = name;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void deleteMember(int prnToDelete) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr && current->prn != prnToDelete) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Member with PRN " << prnToDelete << " not found." << endl;
            return;
        }

        if (prev == nullptr) {
            head = current->next;
        } else {
            prev->next = current->next;
        }

        delete current;
        cout << "Member with PRN " << prnToDelete << " deleted successfully." << endl;
    }

    void displayMembers() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << "PRN: " << temp->prn << ", Name: " << temp->name << endl;
            temp = temp->next;
        }
    }

    void SortMembers() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        bool swapped;
        Node* temp;
        Node* last = nullptr;

        do {
            swapped = false;
            temp = head;

            while (temp->next != last) {
                if (temp->prn > temp->next->prn) {
                    swap(temp->prn, temp->next->prn);
                    swap(temp->name, temp->next->name);
                    swapped = true;
                }
                temp = temp->next;
            }

            last = temp;
        } while (swapped);
    }

    void ReverseOrder() {
        RORecursive(head);
    }

    Node* getHead() {
        return head;
    }

private:
    void RORecursive(Node* current) {
        if (current == nullptr) {
            return;
        }

        RORecursive(current->next);
        cout << "PRN: " << current->prn << ", Name: " << current->name << endl;
    }
};

class MergedDivision {
private:
    Node* head;

public:
    MergedDivision() {
        head = nullptr;
    }

    void NewDivision(Division& division1, Division& division2) {
        Node* temp1 = division1.getHead();
        Node* temp2 = division2.getHead();

        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->prn < temp2->prn) {
                addMember(temp1->prn, temp1->name);
                temp1 = temp1->next;
            } else {
                addMember(temp2->prn, temp2->name);
                temp2 = temp2->next;
            }
        }

        while (temp1 != nullptr) {
            addMember(temp1->prn, temp1->name);
            temp1 = temp1->next;
        }

        while (temp2 != nullptr) {
            addMember(temp2->prn, temp2->name);
            temp2 = temp2->next;
        }
    }

    void displayMembers() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << "PRN: " << temp->prn << ", Name: " << temp->name << endl;
            temp = temp->next;
        }
    }

private:
    void addMember(int prn, string name) {
        Node* newNode = new Node;
        newNode->prn = prn;
        newNode->name = name;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
};

class Club {
private:
    Division division1;
    Division division2;
    MergedDivision mergedDivision;

public:
    Division& getDivision1() {
        return division1;
    }

    Division& getDivision2() {
        return division2;
    }

    void DivDetails(Division& division, const string& divisionName) {
        char choice;
        int prn;
        string name;

        do {
            cout << "\nOptions for " << divisionName << ":\n";
            cout << "1) Add President\n";
            cout << "2) Add Secretary\n";
            cout << "3) Add Members\n";
            cout << "4) Delete Members\n";
            cout << "5) Display Members\n";
            cout << "6) Sort Members by PRN\n";
            cout << "7) Display Members in Reverse Order\n";
            cout << "8) Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case '1':
                    cout << "Enter PRN and Name of " << divisionName << " President: ";
                    cin >> prn >> name;
                    division.addMember(prn, name);
                    break;

                case '2':
                    cout << "Enter PRN and Name of " << divisionName << " Secretary: ";
                    cin >> prn >> name;
                    division.addMember(prn, name);
                    break;

                case '3':
                    cout << "Enter PRN and Name to add a member to " << divisionName << ": ";
                    cin >> prn >> name;
                    division.addMember(prn, name);
                    break;

                case '4':
                    cout << "Enter PRN to delete a member from " << divisionName << ": ";
                    cin >> prn;
                    division.deleteMember(prn);
                    break;

                case '5':
                    cout << divisionName << " Members:\n";
                    division.displayMembers();
                    break;

                case '6':
                    division.SortMembers();
                    cout << divisionName << " Members sorted by PRN.\n";
                    break;

                case '7':
                    cout << divisionName << " Members in Reverse Order:\n";
                    division.ReverseOrder();
                    break;

                case '8':
                    cout << "Exiting " << divisionName << " menu.\n";
                    break;

                default:
                    cout << "Invalid choice. Try again.\n";
            }

        } while (choice != '8');
    }

    void NDDisplay() {
        division1.SortMembers();
        division2.SortMembers();

        mergedDivision.NewDivision(division1, division2);

        cout << "Merged and Sorted Division Members:\n";
        mergedDivision.displayMembers();
    }
};

char GetDivisionOption() {
    char choice;
    cout << "\nOptions:\n";
    cout << "a) Enter the details of Division 1\n";
    cout << "b) Enter the details of Division 2\n";
    cout << "c) Merge and Display Sorted Divisions\n";
    cout << "x) Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

int main() {
    Club club;
    char choice;

    do {
        cout << "\nDo you wish to select a Division? (Y/N): ";
        cin >> choice;

        if (toupper(choice) == 'Y') {
            choice = GetDivisionOption();

            switch (toupper(choice)) {
                case 'A':
                    club.DivDetails(club.getDivision1(), "Division 1");
                    break;

                case 'B':
                    club.DivDetails(club.getDivision2(), "Division 2");
                    break;

                case 'C':
                    club.NDDisplay();
                    break;

                case 'X':
                    cout << "\nThank You\n";
                    break;

                default:
                    cout << "Invalid choice. Try again.\n";
            }
        } else if (toupper(choice) != 'N') {
            cout << "Invalid choice. Please enter 'Y' or 'N'.\n";
        }

    } while (toupper(choice) != 'N' && toupper(choice) != 'X');

    return 0;
}
