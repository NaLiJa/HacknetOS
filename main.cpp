#include <iostream>
#include "HacknetApplication.h"
#include "Util.h"
#include <Windows.h>

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

        Util::sleep(80);
    }
}

HacknetApplication* CreateStarterOS() {
    auto app =  new HacknetApplication();

    // Add Servers, Directories, and Files here...

    return app;
}

void PlayIntro() {
    Util::clearScreen();
    Util::printOneByOne("已过期14天...正在启用FailSafe模式...");
    cout << endl;
    Util::printOneByOne("------------------------------------------------------");
    cout << endl;
    Util::printOneByOne("你好.");
    cout << endl;
    Util::printOneByOne("这件事不对劲......比我想象中的还要奇怪.");
    cout << endl;
    Util::printOneByOne("我原以为我应该用过去时来写这段话, 不过恐怕我得承认......这件事还没有画上句号.");
    cout << endl;
    Util::printOneByOne("我的名字是Bit, 如果你正在阅读这封邮件, 那意味着我已经死了.");
    cout << endl;

    Util::sleep(3000);
    Util::clearScreen();
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    AdjustWindowsSize();

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