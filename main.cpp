#include <iostream>
#include <windows.h>

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
