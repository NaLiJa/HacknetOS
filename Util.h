//
// Created by epiphyllum on 22/04/09.
//

#ifndef HACKNETOS_UTIL_H
#define HACKNETOS_UTIL_H

#include <utility>
#include <string>

namespace Util {
    void clearScreen();
    void setCursorPos(int x, int y);
    std::pair<int,int> getScreenSize();
    void printOneByOne(std::string str, int breakTime = 50);
    void sleep(int ms);
}

#endif //HACKNETOS_UTIL_H