
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    std::string name;
    std::string phoneNumber;
    int roomNumber;
    bool isPayed;

public:
    Customer();
    Customer(std::string name, std::string phoneNumber, int roomNumber, bool isPayed);

    std::string getName() const;
    std::string getPhoneNumber() const;
    int getRoomNumber() const;
    bool getIsPayed() const;

    void setName(const std::string& name);
    void setPhoneNumber(const std::string& phone_number);
    void setRoomNumber(int room_number);
    void setIsPayed(bool is_payed);

    void printInfo() const;
};

#endif
