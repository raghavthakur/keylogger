#include <iostream>
#include <windows.h>
#include "helper.h"
#include "keyconstants.h"
#include "base64.h"
#include "io.h"

using namespace std;

int main()
{
    MSG msg;

    // Hide window
    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
