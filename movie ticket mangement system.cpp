#include <iostream>
#include <string>
using namespace std;

class Movie {
private:
    string movieName;
    int ticketPrice;
    int tickets;

public:
    Movie() {
        movieName = "Not Selected";
        ticketPrice = 150;
        tickets = 0;
    }

    void displayMovies() {
        cout << "\n--- AVAILABLE MOVIES ---\n";
        cout << "1. Avengers\n";
        cout << "2. Spider-Man\n";
        cout << "3. Jawan\n";
    }

    void bookTicket() {
        int choice;
        displayMovies();

        cout << "\nSelect Movie (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                movieName = "Avengers";
                break;
            case 2:
                movieName = "Spider-Man";
                break;
            case 3:
                movieName = "Jawan";
                break;
            default:
                cout << "Invalid Movie Selection!\n";
                return;
        }

        cout << "Enter Number of Tickets: ";
        cin >> tickets;

        if (tickets <= 0) {
            cout << "Invalid Ticket Quantity!\n";
            tickets = 0;
            return;
        }

        cout << "\nBooking Successful!\n";
    }

    void displayBill() {
        if (tickets == 0) {
            cout << "\nNo booking available!\n";
            return;
        }

        cout << "\n------ BOOKING DETAILS ------\n";
        cout << "Movie Name: " << movieName << endl;
        cout << "Ticket Price: Rs. " << ticketPrice << endl;
        cout << "Number of Tickets: " << tickets << endl;
        cout << "Total Amount: Rs. " << ticketPrice * tickets << endl;
    }
};

int main() {
    Movie m;
    int choice;

    do {
        cout << "\n===== MOVIE TICKET BOOKING SYSTEM =====\n";
        cout << "1. View Movies\n";
        cout << "2. Book Tickets\n";
        cout << "3. View Booking Details\n";
        cout << "4. Exit\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                m.displayMovies();
                break;
            case 2:
                m.bookTicket();
                break;
            case 3:
                m.displayBill();
                break;
            case 4:
                cout << "\nThank You!\n";
                break;
            default:
                cout << "\nInvalid Choice!\n";
        }
    } while (choice != 4);

    return 0;
}
