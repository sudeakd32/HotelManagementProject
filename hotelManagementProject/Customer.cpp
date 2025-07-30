#include "Customer.h"
#include <iostream>

Customer::Customer() : roomNumber(0), isPayed(false) {}

Customer::Customer(std::string name, std::string phoneNumber, int roomNumber, bool isPayed)
    : name(std::move(name)), phoneNumber(std::move(phoneNumber)), roomNumber(roomNumber), isPayed(isPayed) {}

std::string Customer::getName() const {
    return name;
}

std::string Customer::getPhoneNumber() const {
    return phoneNumber;
}

int Customer::getRoomNumber() const {
    return roomNumber;
}

bool Customer::getIsPayed() const {
    return isPayed;
}

void Customer::setName(const std::string& name) {
    this->name = name;
}

void Customer::setPhoneNumber(const std::string& phone_number) {
    phoneNumber = phone_number;
}

void Customer::setRoomNumber(int room_number) {
    roomNumber = room_number;
}

void Customer::setIsPayed(bool is_payed) {
    isPayed = is_payed;
}

void Customer::printInfo() const {
    std::cout << "Name: " << name
              << ", Phone: " << phoneNumber
              << ", Room: " << roomNumber
              << ", Paid: " << (isPayed ? "Yes" : "No") << std::endl;
}
