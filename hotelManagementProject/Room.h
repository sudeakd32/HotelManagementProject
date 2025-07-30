

#ifndef ROOM_H
#define ROOM_H

#include <string>

class Room {
public:
    int roomID;
    bool isHaveSeaView;
    int totalCapacity;
    bool isAvailable;
    std::string roomType;

    Room();
    Room(int roomID, bool isHaveSeaView, int totalCapacity);
};

#endif //ROOM_H
