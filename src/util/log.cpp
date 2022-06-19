#include <string>
#include <fstream>
#include <regex>

#include "log.hpp"

void util::log::print(
    const std::string &out,
    Level level = Level::DEFAULT,
    const char *_file = __builtin_FILE()
) {
    auto level_name =
        ((std::string[]){ "NORMAL", "WARN", "ERROR", "DEBUG" })[level];

    std::string f = _file;
    f = std::regex_replace(f, std::regex("src/"), "");
    f = std::regex_replace(f, std::regex("\\.(cpp|hpp)"), "");
    std::ofstream log_file;
    log_file.open(f);

    auto res = "[" + level_name + "]"
        + "[" + f
        + "]" + out;

    if (res[res.length() - 1] != '\n') {
        res += '\n';
    }
    log_file << res;
    log_file.close();
}
