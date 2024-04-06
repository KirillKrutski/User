#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <vector>

struct User {
private:
    std::string login;
    std::string password;
    std::mutex mtx;

public:
    // Конструктор
    User(const std::string& login, const std::string& password) : login(login), password(password) {}

    // Методы доступа
    std::string getLogin() const {
        std::lock_guard<std::mutex> lock(mtx);
        return login;
    }

    void setLogin(const std::string& newLogin) {
        std::lock_guard<std::mutex> lock(mtx);
        login = newLogin;
    }

    std::string getPassword() const {
        std::lock_guard<std::mutex> lock(mtx);
        return password;
    }

    void setPassword(const std::string& newPassword) {
        std::lock_guard<std::mutex> lock(mtx);
        password = newPassword;
    }
};
