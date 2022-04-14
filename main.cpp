#include <iostream>
#include "HacknetApplication.h"
#include "Util.h"
#include "MusicUtil.h"
#include <Windows.h>
#include <codecvt>

// 存
// 渲染

using std::cout;
using std::endl;

void AdjustWindowsSize() {
    while (true) {
        Util::clearScreen();
        // 220 x 50
        cout << u8"请将控制台尺寸调整为220 x 50， 然后点击Enter开始游戏" << endl;
        auto size = Util::getScreenSize();

        cout << "当前尺寸: " << size.first << " x " << size.second << endl;

        if (size.first == 220 && size.second == 50) {
            break;
        }

        Util::sleep(10);
    }
}

HacknetApplication* CreateStarterOS() {
    auto app =  new HacknetApplication();

    // Add Servers, Directories, and Files here...

    return app;
}

void PlayIntro() {
    Util::clearScreen();
    Util::setCursorPos(30, 10);
    Util::printOneByOne(L"已过期14天...正在启用FailSafe模式...");
    Util::setCursorPos(30, 11);
    Util::printOneByOne(L"------------------------------------------------------");
    Util::setCursorPos(30, 12);
    Util::printOneByOne(L"你好.");
    Util::setCursorPos(30, 13);
    Util::printOneByOne(L"这件事不对劲......比我想象中的还要奇怪.");
    Util::setCursorPos(30, 14);
    Util::printOneByOne(L"我原以为我应该用过去时来写这段话, 不过恐怕我得承认......这件事还没有画上句号.");
    Util::setCursorPos(30, 15);
    Util::printOneByOne(L"我的名字是Bit, 如果你正在阅读这封邮件, 那意味着我已经死了.");
    Util::setCursorPos(30, 16);

    Util::sleep(3000);
    Util::clearScreen();
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);

#pragma warning (disable: 4996)
    std::locale utf8( std::locale(), new std::codecvt_utf8_utf16<wchar_t> );
    std::wcout.imbue(utf8);
#pragma warning (default: 4996)

    AdjustWindowsSize();

    MusicUtil::playBgm(0);
    // Play the intro
    PlayIntro();

    // create a starter
    auto app = CreateStarterOS();

    // start the event loop
    app->Exec();

    delete app;

    Util::sleep(1000);
    return 0;
}
