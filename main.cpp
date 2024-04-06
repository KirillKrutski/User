#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <vector>
#include "user.cpp"
#include "userManager.cpp"


int main() {
    // Векторы для хранения пользователей и их логинов/паролей
    std::vector<User> users;
    std::vector<std::string> logins = {"user1", "user2", "user3"};
    std::vector<std::string> passwords = {"pass1", "pass2", "pass3"};

    // Создаем пользователей и добавляем их в вектор
    for (size_t i = 0; i < logins.size(); ++i) {
        users.emplace_back(logins[i], passwords[i]);
    }

    // Создаем объект класса UserManager
    UserManager userManager;

    // Ввод логинов и паролей асинхронно для каждого пользователя
    for (size_t i = 0; i < users.size(); ++i) {
        std::thread([&users, i, &userManager]() {
            std::string newLogin, newPassword;
            std::cout << "Enter new login for user " << i + 1 << ": ";
            std::cin >> newLogin;
            userManager.changeLogin(users[i], newLogin);
            std::cout << "Enter new password for user " << i + 1 << ": ";
            std::cin >> newPassword;
            userManager.changePassword(users[i], newPassword);
        }).detach();
    }

    // Ждем завершения всех потоков
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Выводим обновленные данные пользователей
    for (size_t i = 0; i < users.size(); ++i) {
        std::cout << "User " << i + 1 << " - Login: " << users[i].getLogin() << ", Password: " << users[i].getPassword() << std::endl;
    }

    return 0;
}
