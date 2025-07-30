#include <iostream>
#include <map>
#include <random>
#include <string>
#include "Customer.h"
#include "Room.h"
#include "HotelManagement.h"
#include "HotelGlobals.h"

using namespace std;
int currentBookedRoomNumber = 0;
Room rooms[totalRoomNumber];

bool isAdminAuthenticated() {

    string password = "admin123";
    hash<string> storedHasher;
    size_t hashValue = storedHasher(password);

    string passwordInput;
    cout << "Enter admin password: ";
    cin >> passwordInput;

    hash<string> hasher;
    size_t passwordHash = hasher(password);

    const size_t storedHash = storedHasher(passwordInput);
    return passwordHash == storedHash;
}

int main() {


    random_device rd;
    mt19937 gen(rd());
    bernoulli_distribution d(0.5);
    uniform_int_distribution<> dist(1, 4); //Room capacity can be between 1 and 4

    //Create random rooms
    for (int i = 0; i < totalRoomNumber; i++) {

        bool randomIsHaveSeaView = d(gen);
        int randomTotalRoomCapacity = dist(gen);
        rooms[i] = Room(i, randomIsHaveSeaView, randomTotalRoomCapacity);

    }

    map <int, Customer> hotelManagerMap;
    HotelManagement hotelManager(hotelManagerMap);
    Customer customer;

    bool isAdmin = false;
    int mainChoice;

    while (true) {
        cout << "\n===== Welcome to the Hotel System =====\n";
        cout << "1. Login as Admin\n";
        cout << "2. Continue as Guest\n";
        cout << "3. Exit\n";
        cout << "Your choice: ";
        cin >> mainChoice;

        if (mainChoice == 1) {
            if (isAdminAuthenticated()) {
                cout << "Admin login successful.\n";
                isAdmin = true;
                break;
            } else {
                cout << "Invalid password. Try again.\n";
            }
        } else if (mainChoice == 2) {
            break;
        } else if (mainChoice == 3) {
            return 0;
        } else {
            cout << "Invalid choice.\n";
        }
    }

    int choice = 0;
    int id;
    while (true) {
        cout << "\n===== Hotel Management System =====\n";
        cout << "1. Check available rooms\n";
        cout << "2. Pay money to book room (Customer)\n";
        cout << "3. Display Booked Rooms\n";
        cout << "4. Check Out (Customer)\n";
        cout << "5. Force customer to check out (Admin Only)\n";
        cout << "6. Show Customer Info (Admin Only)\n";
        cout << "7. Check in room for a customer (Admin Only)\n";
        cout << "8. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hotelManager.checkAvailability();
            break;
            case 2:
                if (isAdmin) {
                    cout << "Please log in as customer.\n"<<endl;
                    continue;
                }
                cout << "Enter room ID of a room you want to check in: ";
                cin >> id;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input! Please enter a valid number.\n";
                    continue;
                }
                if (id < 0 || id >= totalRoomNumber) {
                    cout << "Invalid room ID.\n";
                    continue;
                }
                if (auto result = HotelManagement::checkInNewCustomer(id); result.has_value()) {
                customer = result.value();
                hotelManagerMap.insert({id, customer});
                }
                else
                    continue;
            break;
            case 3:
                hotelManager.displayBookedRooms();
            break;
            case 4:
                if (isAdmin) {
                    cout << "Please log in as customer.\n"<<endl;
                    continue;
                }
                cout << "Enter room ID of a room you want to check out: ";
                cin >> id;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input! Please enter a valid number.\n";
                    continue;
                }
                if (id < 0 || id >= totalRoomNumber) {
                    cout << "Invalid room ID.\n";
                    continue;
                }
                if (rooms[id].isAvailable) {
                    cout << "The room you want to check out is empty!\n";
                    continue;
                }
                hotelManager.checkOut(id);
            break;
            case 5:
                if (isAdmin) {
                    cout << "Enter room ID of a room you want customer to check out: ";
                    cin >> id;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input! Please enter a valid number.\n";
                        continue;
                    }
                    if (id < 0 || id >= totalRoomNumber) {
                        cout << "Invalid room ID.\n";
                        continue;
                    }
                    if (rooms[id].isAvailable) {
                        cout << "The room you want to check out customer is empty!\n";
                        continue;
                    }
                    hotelManager.checkOutForAdmin(id);
                } else {
                    cout << "You are not authorized to perform this action.\n";
                }
                break;
            case 6:
                if (isAdmin) {
                    if (hotelManager.hotelManager.empty()) {
                        cout << "No customers have checked in yet.\n";
                        continue;
                    }
                    cout << "\n--- All Customer Info ---\n";
                    for (const auto& pair : hotelManager.hotelManager) {
                        cout << "Room: " << pair.first << " → ";
                        pair.second.printInfo();
                    }
                } else {
                    cout << "You are not authorized to perform this action.\n";
                }
            break;
            case 7:
                if (isAdmin) {
                    cout << "Enter room ID of a room you want to check in: ";
                    cin >> id;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input! Please enter a valid number.\n";
                        continue;
                    }
                    if (id < 0 || id >= totalRoomNumber) {
                        cout << "Invalid room ID.\n";
                        continue;
                    }
                    if (auto result = HotelManagement::checkInNewCustomerForAdmin(id); result.has_value()) {
                        customer = result.value();
                        hotelManagerMap.insert({id, customer});
                    }
                    else
                        continue;
                } else {
                    cout << "You are not authorized to perform this action.\n";
                }
                break;
            case 8:
                cout << "Exiting... Thank you!\n";
            return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

}
