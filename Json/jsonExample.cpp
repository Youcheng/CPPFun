#include <string>
#include <iostream>
#include "json.hpp"
#include <fstream>
#include <iomanip>

using json = nlohmann::json;

int main() {
    std::string config = "/home/ylin/CLionProjects/CPPFun/Json/config.json";
    json jsonConfig = json::parse(std::ifstream(config));

    try {
        std::cout << std::setw(4) << jsonConfig << std::endl;
        std::cout << jsonConfig.at("sessions")[0].at("threadName") << std::endl;

    } catch(std::exception& e) {
        std::cout << e.what() << std::endl;
    }

}
