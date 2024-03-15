#include <windows.h>

// đổi màu chữ đổi cả màu nền
void textcolor(int x);
// ẩn trỏ chuột
void showcur(bool CursorVisibility);
//đổi màu cho chữ ko đổi màu nền
void setcolor(WORD color);
// go to xy
void gotoxy(int x, int y);
// xóa màn hinh từ vị trí x->x+width, y->y+height
void clearscreen(int x, int y, int width, int height);
// cố định kích thước màn hình console
void setwindowsize(int width, int height);
// kiểm tra số ngầy trong năm
int checkday(int year, int month);
