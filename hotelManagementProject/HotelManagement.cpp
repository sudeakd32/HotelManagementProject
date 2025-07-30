#include "HotelManagement.h"
#include "HotelGlobals.h"
#include <iostream>

using namespace std;

HotelManagement::HotelManagement(map<int, Customer> &hotelManager) : hotelManager(hotelManager) {}

void HotelManagement::checkAvailability() {
    for (auto & room : rooms) {
        if (room.isAvailable) {
            cout << "Room " << room.roomID << " is available." << endl;
            cout << "Room type: " << room.roomType << endl;
            cout << "Is have sea view: " << (room.isHaveSeaView ? "Yes\n" : "No\n") << endl;
        }
    }
}

optional<Customer> HotelManagement::checkInNewCustomer(int roomID) {
    string name, phoneNumber;
    int peopleInRoom;

    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your phone number(without blank): ";
    cin >> phoneNumber;
    cout << "Enter how many people will stay in this room: ";
    cin >> peopleInRoom;

    if (peopleInRoom <= 0 || peopleInRoom > 4) {
        cout << "There are no rooms in this hotel for "<<peopleInRoom<<" person" << endl;
        return nullopt;
    }

    if (rooms[roomID].roomType == "Single Room" && peopleInRoom != 1) {
        cout << "You can not check in single room with "<<peopleInRoom<<" person. Please look for another rooms." << endl;
        return nullopt;
    }
    if (rooms[roomID].roomType == "Double Room" && peopleInRoom != 2) {
        cout << "You can not check in double room with "<<peopleInRoom<<" person. Please look for another rooms." << endl;
        return nullopt;
    }
    if (rooms[roomID].roomType == "Family Room" && (peopleInRoom != 3 && peopleInRoom != 4)) {
        cout << "You can not check in family room with "<<peopleInRoom<<" person. Please look for another rooms." << endl;
        return nullopt;
    }

    Customer customer(name, phoneNumber, roomID, true);
    rooms[roomID].isAvailable = false;
    currentBookedRoomNumber++;
    cout << "You checked in successfully" << endl;

    return customer;
}

optional<Customer> HotelManagement::checkInNewCustomerForAdmin(int roomID) {
    string name, phoneNumber;
    int peopleInRoom;

    cout << "Enter customer name: ";
    cin >> name;
    cout << "Enter customer phone number(without blank): ";
    cin >> phoneNumber;
    cout << "Enter how many people will stay in this room: ";
    cin >> peopleInRoom;

    if (peopleInRoom <= 0 || peopleInRoom > 4) {
        cout << "There are no rooms in this hotel for "<<peopleInRoom<<" person" << endl;
        return nullopt;
    }

    if (rooms[roomID].roomType == "Single Room" && peopleInRoom != 1) {
        cout << "You can not check in single room with "<<peopleInRoom<<" person. Please look for another rooms." << endl;
        return nullopt;
    }
    if (rooms[roomID].roomType == "Double Room" && peopleInRoom != 2) {
        cout << "You can not check in double room with "<<peopleInRoom<<" person. Please look for another rooms." << endl;
        return nullopt;
    }
    if (rooms[roomID].roomType == "Family Room" && (peopleInRoom != 3 && peopleInRoom != 4)) {
        cout << "You can not check in family room with "<<peopleInRoom<<" person. Please look for another rooms." << endl;
        return nullopt;
    }

    Customer customer(name, phoneNumber, roomID, true);
    rooms[roomID].isAvailable = false;
    currentBookedRoomNumber++;
    cout << "Customer checked in successfully" << endl;

    return customer;
}

void HotelManagement::displayBookedRooms() {
    if (currentBookedRoomNumber == 0) {
        cout << "There are no booked rooms in this hotel" << endl;
        return;
    }

    for (auto & room : rooms) {
        if (!room.isAvailable) {
            cout << "Room " << room.roomID << " is booked." << endl;
            cout << "Room type: " << room.roomType << endl;
            cout << "Is have sea view: " << (room.isHaveSeaView ? "Yes\n" : "No\n") << endl;
        }
    }
}

void HotelManagement::checkOut(int id) {
    hotelManager.erase(id);
    rooms[id].isAvailable = true;
    currentBookedRoomNumber--;
    cout << "You successfully checked out on room " << id << "." << endl;
}

void HotelManagement::checkOutForAdmin(int id) {
    hotelManager.erase(id);
    rooms[id].isAvailable = true;
    currentBookedRoomNumber--;
    cout << "Customer successfully checked out on room " << id << "." << endl;
}
