#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

int main(int argc, char *argv[]) {

    if ((argc > 1) /*bigger cuz of null termina-Thor */ && (std::strcmp(argv[1], "echo") == 0)) {
        std::ifstream in("data.json");
        if (!in) { std::cerr << "cannot open data.json\n"; return 1; }

        nlohmann::json json;
        try {
            in >> json;
        } catch (const std::exception &e) {
            std::cerr << "parse error: " << e.what() << '\n';
            return 1;
        }

        if (!(json.is_array())) {
            std::cerr << "expected JSON array\n"; return 1;
        }

        for (const auto &item : json) { //TODO: Replace that slopilot crap with more respectable syntax
            if (!item.contains("word") || !item.contains("type")) {
                std::cerr << "item missing word or type; skipping\n";
                continue; //Also this shit
            }
            std::string name = item.value("word", "");
            std::string type = item.value("type", "");
            if (item.contains("gow") && !item["gow"].is_null()) { //gow basically gender of word
                std::string gow = item.value("gow", "");
                std::cout << "word: " << name << ", type: " << type << ", gow: " << gow << '\n';
            } else {
                std::cout << "word: " << name << ", type: " << type << ", gow: <none>\n"; //This is shit, TODO:move to a string and just cout or puts the whole string
            }
        }
    }
    if ((argc > 1) /*bigger cuz of null termina-Thor */ && (std::strcmp(argv[1], "print") == 0)) { //TODO: replace with switch
        std::ifstream in("data.json");
        if (!in) { std::cerr << "cannot open data.json\n"; return 1; }

        nlohmann::json json;
        try {
            in >> json;
        } catch (const std::exception &e) {
            std::cerr << "parse error: " << e.what() << '\n';
            return 1;
        }

        if (!(json.is_array())) {
            std::cerr << "expected JSON array\n"; return 1;
        }

        for (const auto &item : json) { //TODO: Replace that slopilot crap with more respectable syntax
            if (!item.contains("word") || !item.contains("type")) {
                std::cerr << "item missing word or type; skipping\n";
                continue; //Also this shit
            }
            std::string name = item.value("word", "");
            std::string type = item.value("type", "");
            if (item.contains("gow") && !item["gow"].is_null()) { //gow basically gender of word
                std::string gow = item.value("gow", "");
                std::cout << "word: " << name << ", type: " << type << ", gow: " << gow << '\n';
            } else {
                std::cout << "word: " << name << ", type: " << type << ", gow: <none>\n"; //This is shit, move to a string and just cout or frintf the whole string
            }
        }
    }
    return 0;
}
