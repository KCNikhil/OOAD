#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    const int totalSeats = 40;
    vector<string> seats(totalSeats, "");

    int choice;
    do {
        cout << "\n--- Bus Reservation System Menu ---\n";
        cout << "1. Display available seats\n";
        cout << "2. Book a seat\n";
        cout << "3. Cancel reservation\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                cout << "\nSeat Status:\n";
                for (int i = 0; i < totalSeats; i++) {
                    if (seats[i].empty()) {
                        cout << "Seat " << (i + 1) << ": Available\n";
                    } else {
                        cout << "Seat " << (i + 1) << ": Booked by " << seats[i] << "\n";
                    }
                }
                break;
            }
            case 2: {
                int seatNumber;
                cout << "Enter seat number to book (1-" << totalSeats << "): ";
                cin >> seatNumber;

                if(seatNumber < 1 || seatNumber > totalSeats) {
                    cout << "Invalid seat number! Please try again.\n";
                } else if(!seats[seatNumber - 1].empty()){
                    cout << "Seat " << seatNumber << " is already booked by " << seats[seatNumber - 1] << ".\n";
                } else {
                    string name;
                    cout << "Enter passenger name: ";
                    cin.ignore();
                    getline(cin, name);
                    seats[seatNumber - 1] = name;
                    cout << "Seat " << seatNumber << " successfully booked for " << name << ".\n";
                }
                break;
            }
            case 3: {
                int seatNumber;
                cout << "Enter seat number to cancel reservation (1-" << totalSeats << "): ";
                cin >> seatNumber;

                if(seatNumber < 1 || seatNumber > totalSeats) {
                    cout << "Invalid seat number! Please try again.\n";
                } else if(seats[seatNumber - 1].empty()){
                    cout << "Seat " << seatNumber << " is not booked yet.\n";
                } else {
                    cout << "Reservation for seat " << seatNumber << " (booked by "
                         << seats[seatNumber - 1] << ") has been cancelled.\n";
                    seats[seatNumber - 1].clear();
                }
                break;
            }
            case 4:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 4);

    return 0;
}
