# 🏨 Hotel Management System (C++ Project)

This is a fully modular, object-oriented **Hotel Management System** written in C++.

It supports both **admin and guest interactions**, allowing room check-in, check-out, availability checking, and customer info display — all from a terminal interface.

## 📌 Key Highlights

- 🔐 **Admin and Guest roles** with different access levels
- 🛏️ **10 rooms** initialized randomly at startup (with sea view and capacity info)
- ✅ **Room-type validation** based on guest count
- 💳 **Payment simulation** upon booking
- 📋 **Dynamic menu** interface based on user role

## 🎯 Purpose

The project demonstrates:
- Modular OOP design with class separation (`Customer`, `Room`, `HotelManagement`)
- Menu-driven UI for console interaction
- Encapsulation and input validation
- Admin-only operations
- Use of standard libraries like `map`, `optional`, `random`, `hash`

## 🧾 Menu Structure Explained

### 🟢 Initial Menu

| Option | Function |
|--------|----------|
| `1` – Login as Admin | Prompts for password (`admin123`). Grants access to admin-only operations. |
| `2` – Continue as Guest | Skips login. Limits user to general features only. |
| `3` – Exit | Terminates the application. |

## 🔧 Main System Menu

After entering as Admin or Guest, the following menu appears:

| Menu Option | Who Can Use It | Description |
|-------------|----------------|-------------|
| `1. Check available rooms` | All users | Lists all unoccupied rooms. Shows room ID, type (Single/Double/Family), and if it has a sea view. |
| `2. Pay money to book room (Customer)` | **Guest only** | Allows customer to book a room by providing name, phone number, and number of guests. Only works if the number matches room type. |
| `3. Display Booked Rooms` | All users | Shows all currently occupied rooms with their details (ID, type, sea view). Does **not** show customer info. |
| `4. Check Out (Customer)` | **Guest only** | Allows a customer to check out by entering their room ID. Frees the room. |
| `5. Force customer to check out (Admin Only)` | **Admin only** | Admin forcibly checks out a customer from a room. Useful for eviction scenarios. |
| `6. Show Customer Info (Admin Only)` | **Admin only** | Displays detailed information of all booked customers including: name, phone, room number, and payment status. |
| `7. Check in room for a customer (Admin Only)` | **Admin only** | Allows admin to perform booking **on behalf of a customer** (e.g., manual registration). Prompts for all required fields. |
| `8. Exit` | All users | Terminates the program gracefully. |

---

## 📁 Project Structure

hotelManagementProject/
│
├── main.cpp                  → Main menu logic and application loop
├── Customer.h / .cpp         → Customer class: user data, payment, room info
├── Room.h / .cpp             → Room class: capacity, sea view, availability
├── HotelManagement.h / .cpp  → Main hotel manager class: check-in/out logic
├── HotelGlobals.h            → Shared globals: totalRoomNumber, rooms[], currentBookedRoomNumber
├── CMakeLists.txt            → Build configuration
├── screenshots/              → Screenshots for GitHub display
└── README.md                 → This file

---

## 🧱 How to Build and Run on Any Computer

### 🔧 Prerequisites

Make sure the target system has:

- C++20 compatible compiler (e.g., g++, clang++)
- CMake (v3.20 or higher)
- Make or Ninja
- Terminal or IDE (CLion, VS Code, etc.)


### 📦 1. Clone the Repository

```bash
git clone https://github.com/yourusername/hotelManagementProject.git
cd hotelManagementProject
mkdir build
cd build
cmake ..
make
