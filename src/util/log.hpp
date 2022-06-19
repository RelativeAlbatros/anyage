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
        Level level = Level::DEFAULT,
        const char *_file = __builtin_FILE()
    );
}
