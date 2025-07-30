
#ifndef HOTELMANAGEMENT_H
#define HOTELMANAGEMENT_H

#include <map>
#include <string>
#include <optional>
#include "Customer.h"
#include "Room.h"

extern Room rooms[];
extern int currentBookedRoomNumber;

class HotelManagement {
public:
    std::map<int, Customer> &hotelManager;

    explicit HotelManagement(std::map<int, Customer> &hotelManager);

    void checkAvailability();
    static std::optional<Customer> checkInNewCustomer(int roomID);
    static std::optional<Customer> checkInNewCustomerForAdmin(int roomID);
    void displayBookedRooms();
    void checkOut(int id);
    void checkOutForAdmin(int id);
};

#endif //HOTELMANAGEMENT_H
