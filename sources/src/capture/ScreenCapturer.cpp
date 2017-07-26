#include "capture/ScreenCapturer.hpp"

#include "graphics/Image.hpp"

#include <Windows.h>

namespace cdl
{
    namespace capture
    {
        graphics::Image ScreenCapturer::capture()
        {
            int x1, y1, x2, y2, w, h;

            // get screen dimensions
            x1 = GetSystemMetrics(SM_XVIRTUALSCREEN);
            y1 = GetSystemMetrics(SM_YVIRTUALSCREEN);
            x2 = GetSystemMetrics(SM_CXVIRTUALSCREEN);
            y2 = GetSystemMetrics(SM_CYVIRTUALSCREEN);
            w = x2 - x1;
            h = y2 - y1;

            // copy screen to bitmap
            HDC     hScreen = GetDC(NULL);
            HDC     hDC = CreateCompatibleDC(hScreen);
            HBITMAP hBitmap = CreateCompatibleBitmap(hScreen, w, h);
            HGDIOBJ old_obj = SelectObject(hDC, hBitmap);
            BOOL    bRet = BitBlt(hDC, 0, 0, w, h, hScreen, x1, y1, SRCCOPY);

            BITMAPINFO MyBMInfo = { 0 };
            MyBMInfo.bmiHeader.biSize = sizeof(MyBMInfo.bmiHeader);

            if (0 == GetDIBits(hDC, hBitmap, 0, 0, NULL, &MyBMInfo, DIB_RGB_COLORS))
            {
                // error handling
            }

            MyBMInfo.bmiHeader.biBitCount = 32;
            MyBMInfo.bmiHeader.biCompression = BI_RGB;  // no compression -> easier to use
                                                        // correct the bottom-up ordering of lines (abs is in cstdblib and stdlib.h)
            MyBMInfo.bmiHeader.biHeight = abs(MyBMInfo.bmiHeader.biHeight);

            graphics::Image fullWindow;

            fullWindow.w = w;
            fullWindow.h = h;
            fullWindow.resize();

            if (0 == GetDIBits(hDC, hBitmap, 0, MyBMInfo.bmiHeader.biHeight,
                               fullWindow.pixelsPtr(), &MyBMInfo, DIB_RGB_COLORS))
            {
                // error handling
            }

            // clean up
            SelectObject(hDC, old_obj);
            DeleteDC(hDC);
            ReleaseDC(NULL, hScreen);
            DeleteObject(hBitmap);

            return fullWindow;
        }

        graphics::Image ScreenCapturer::capture(const Rect& rect)
        {
            return capture().getSprite(rect);
        }
    }
}
