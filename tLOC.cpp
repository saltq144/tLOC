#include <iostream>
#include <string>
#include "wxdisk.hpp"
#include <vector>
#include <filesystem>

typedef std::string string;
using std::cout;
using std::cin;

auto ls_recursive(const std::filesystem::path& path) {
    std::vector<string> ret;
    for (const auto& p : std::filesystem::recursive_directory_iterator(path)) {
        if (!std::filesystem::is_directory(p)) {
           ret.push_back(p.path().string());
        }
    }
    return ret;
}

bool startsWith3F(std::string in, std::string c) {
    if (in.size() < c.size()) return false;
    for (unsigned int i = 0; i < c.size(); i++) {
        if (c[i] != in[i]) return false;
    }
    return true;
}
int main(int argc, char* argv[])
{
    string path;
    if (argc > 1) {
        path = string(argv[1]);
    }
    else {
        cout << "Project path:";
        cin >> path;
    }
    if (path == "$cur") path = std::filesystem::current_path().string();
    std::vector<string> paths;
    int lines = 0;
    for (const auto& a : ls_recursive(path)) {
        if (startsWith3F(std::string(a.rbegin(), a.rend()), "pph.") || startsWith3F(std::string(a.rbegin(), a.rend()), "ppc.") || startsWith3F(std::string(a.rbegin(), a.rend()), "h.") || startsWith3F(std::string(a.rbegin(), a.rend()), "c.")) {
            paths.push_back(a);
        }
    }
    for (const auto& a : paths) {
        auto _a = disk::file::getContent(a);
        for (const auto& b : _a) {
            if (b == '\n') lines++;
        }
    }
    std::cout << lines << " Lines of code!\n";
    std::cout << ((lines - lines % 100)/1000) << " KLines of code!\n";
}