#pragma once

#include <memory>

class mainLoop {
public:
    static mainLoop &get();
    void run();

private:
    inline static std::unique_ptr<mainLoop> main = nullptr;
    mainLoop() = default;
    mainLoop(const mainLoop &) = delete;
    mainLoop& operator=(const mainLoop &) = delete;
};