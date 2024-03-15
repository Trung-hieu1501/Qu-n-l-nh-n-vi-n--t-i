#pragma once
#include <stdio.h>
#include <conio.h>
#include "windows.h"
#define KEY_NONE	-1
//dịch con trỏ hiện tại đến điểm có tọa độ (x,y)
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x, y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
//đặt màu cho chữ
void setcolor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
//làm ẩn trỏ chuột
void showcur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

//đổi màu cho chữ 
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

//xóa màn hình tại vị trí xác định
void clearscreen(int x, int y, int width, int height) {
	// Hàm này xóa một vùng hình chữ nhật trên màn hình với tọa độ góc trái trên là (x, y) và kích thước là width x height
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Lấy handle của console
	COORD topLeft = { x, y }; // Tọa độ góc trái trên
	DWORD written; // Số ký tự đã được ghi
	DWORD cells = width * height; // Số ô cần xóa
	FillConsoleOutputCharacter(hConsole, ' ', cells, topLeft, &written); // Ghi khoảng trắng vào các ô cần xóa
	FillConsoleOutputAttribute(hConsole, 0, cells, topLeft, &written); // Đặt màu nền và màu chữ của các ô cần xóa về mặc định
	SetConsoleCursorPosition(hConsole, topLeft); // Đưa con trỏ về vị trí góc trái trên
}
// đặt kích thước console
void setwindowsize(int width, int height) {
	HANDLE output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD buffer_size = { width, height };
	SetConsoleScreenBufferSize(output_handle, buffer_size);
	SMALL_RECT window_size = { 0, 0, width - 1, height - 1 };
	SetConsoleWindowInfo(output_handle, TRUE, &window_size);
}


//kiểm tra ngày tháng 
int checkday(int year, int month) {
	int daysInMonth;
	switch (month) {
	case 2: // Tháng 2
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) daysInMonth = 29;
		else daysInMonth = 28;
		break;
	case 4: // Tháng 4, 6, 9, 11
	case 6:
	case 9:
	case 11:
		daysInMonth = 30;
		break;
	default: // Các tháng còn lại
		daysInMonth = 31;
		break;
	}

	return daysInMonth;
}
