#include <iostream>
#include <fstream>
#include <json.hpp>
using json = nlohmann::json;

int main() {
    std::ifstream f("productos.json", std::ios::binary);
    if (!f.is_open()) { std::cerr << "cannot open file\n"; return 1; }
    try {
        std::string s((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
        if (s.size() >= 3 && (unsigned char)s[0]==0xEF && (unsigned char)s[1]==0xBB && (unsigned char)s[2]==0xBF)
            s.erase(0,3);
        auto data = json::parse(s);
        std::cout << "parsed OK\n";
    } catch (nlohmann::json::parse_error& e) {
        std::cerr << "parse_error: " << e.what() << "\nbyte: " << e.byte << "\n";
    }
    return 0;
}   