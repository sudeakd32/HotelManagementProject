#include "Room.h"

Room::Room() : roomID(0), isHaveSeaView(false), totalCapacity(0), isAvailable(true) {}

Room::Room(int roomID, bool isHaveSeaView, int totalCapacity)
    : roomID(roomID), isHaveSeaView(isHaveSeaView),
      totalCapacity(totalCapacity), isAvailable(true) {

    if (totalCapacity == 1)
        roomType = "Single Room";
    else if (totalCapacity == 2)
        roomType = "Double Room";
    else
        roomType = "Family Room";
}
