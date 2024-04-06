#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <vector>

class UserManager {
public:
    void changeLogin(User& u, const std::string& newLogin) {
        std::thread([&u, newLogin]() {
            u.setLogin(newLogin);
        }).detach();
    }

    void changePassword(User& u, const std::string& newPassword) {
        std::thread([&u, newPassword]() {
            u.setPassword(newPassword);
        }).detach();
    }
};