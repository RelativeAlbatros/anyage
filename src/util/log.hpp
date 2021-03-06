#pragma once

#include <string>

namespace util::log {
    enum Level {
        NORMAL,
        WARN,
        ERROR,
        DEBUG,
        DEFAULT = DEBUG
    };

    void print(
        const std::string &out,
        Level level,
        const char *_file
    );
}
