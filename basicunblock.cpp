#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main() {
    std::ifstream file("ip_list_2.txt");
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::string command = "netsh advfirewall firewall delete rule name=\"force IP Address\" remoteip=" + line;
            system(command.c_str());
        }
        file.close();
    } else {
        std::cout << "Unable to open file";
    }

    return 0;
}
