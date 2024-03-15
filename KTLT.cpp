#include <iostream>
#include<iomanip>
#include<conio.h>
#include<string>
#include<vector>
#include <fstream>
#include "thuvien.h";
#pragma once
using namespace std;

struct NV {
	string id, hoten1, hoten2, sex;
	int ngay, thang, nam;
};
struct DT {
	string id, ten1, ten2;
	int bd, kt;
	double cost;
};
struct NVDT {
	string idnv, iddt;
	string title;
};
vector<NV>nhanvien;
vector<DT>detai;
vector<NVDT>nhanviendetai;
void khung(int x, int y, int w, int h, int mauchu, int maunen, string nd);
void n_khung(int x, int y, int w, int h, int mauchu, int maunen, string nd[], int sl);
int menu(string nd[], int sl, int langoi);
bool checkidnv(string x);
bool checkiddt(string x);
bool checknvdt(string x, string y);
void addnv(NV x);
void nhapnv(int n);
void adddt(DT x);
void nhapdetai(int n);
void addnvdt(NVDT x);
void nhapnvdt(int n);
void editnv(string x);
void editdt(string x);
void editnvdt(string x, string y);		// x= mã nhân viên, y= mã đề tài
void xoanv(string x);	// khi xóa thông tin nhân viên sẽ xóa thông tin cả trong nhân viên đề tài
void xoadt(string x);	// khi xóa thông tin đề tài sẽ xóa thông tin cả trong nhân viên đề tài
void xoanvdt(string x, string y);	// x= mã nhân viên, y= mã đề tài
void list(string x); // danh sách và vai trò của nhân viên trong đề tài
void listdt(int x);		// danh sách đề tài theo năm bắt đầu
void chitietdt(string x);	// thông tin chi tiết đề tài
void chiphi(int x);	// tổng kinh phí đề tài trong năm
void ghiNV(NV x);
void ghiDT(DT x);
void ghiNVDT(NVDT x);
void docNV();
void docDT();
void docNVDT();


int main() {
	docNV();
	docDT();
	docNVDT();
	showcur(0);	// ẩn con trỏ 
	setwindowsize(120, 43);
	khung(10, 0, 100, 2, 42, 75, "");	//khung tên chương trình
	clearscreen(11, 1, 99, 1);
	gotoxy(41, 1);
	setcolor(4);
	cout << "CHUONG TRINH QUAN LY NHAN VIEN DE TAI";
	// khung chú ý
	khung(10, 37, 100, 5, 42, 15, "");
	setcolor(4);
	gotoxy(11, 37); cout << "\t\t\t\t\t\t CHU Y ";
	gotoxy(11, 38); cout << " An phim mui ten de di chuyen thanh sang";
	gotoxy(11, 39); cout << "- An ENTER de chon chuc nang, ESC de thoat chuong trinh";
	gotoxy(11, 40); cout << "- Vai tro nhan vien gom: chu nhiem, thu ky, thanh vien";
	gotoxy(11, 41); cout << "- Ngay sinh nhap theo dinh dang: dd/mm/yyyy (thong tin nhap vao cach nhau boi enter)";
	gotoxy(79, 42); cout << "VU DANH TRUNG HIEU - 20216925";
	gotoxy(15, 42); cout << "KY THUAT LAP TRINH ";
	// menu
	int chon;
	string nd[7] = { "1. Them thong tin","2. Sua thong tin", "3. Xoa thong tin","4. Danh sach de tai va vai tro cua nhan vien tham gia", "5. Danh sach de tai theo nam", "6. Thong tin de tai", "7. Tong kinh phi cho de tai trong nam" };
	while (true) {
		chon = menu(nd, 7, 0);
		if (chon == 0) {
			string nd1[3] = { "1. Them thong tin nhan vien", "2. Them thong tin de tai","3. Them thong tin nhan vien de tai" };
			menu(nd1, 3, 1);
		}
		else if (chon == 1) {
			string nd1[3] = { "1. Sua thong tin nhan vien", "2. Sua thong tin de tai","3. Sua thong tin nhan vien de tai" };
			menu(nd1, 3, 2);
		}
		else if (chon == 2) {
			string nd1[3] = { "1. Xoa thong tin nhan vien", "2. Xoa thong tin de tai","3. Xoa thong tin nhan vien de tai" };
			menu(nd1, 3, 3);
		}
		else if (chon == 3) {
			clearscreen(5, 5, 20, 90);
			string x;
			textcolor(0);
			khung(30, 5, 60, 2, 3, 1, "Nhap ma so nhan vien: ");
			gotoxy(54, 6);
			textcolor(0);
			setcolor(7);
			cin >> x; cin.ignore();
			list(x);
			cin.ignore();
		}
		else if (chon == 4) {
			clearscreen(5, 5, 20, 90);
			int x;
			textcolor(0);
			khung(30, 5, 60, 2, 3, 1, "Nhap nam bat dau de tai: ");
			gotoxy(57, 6);
			textcolor(0);
			setcolor(7);
			cin >> x;
			cin.ignore();
			listdt(x);
			//cin.ignore();
		}
		else if (chon == 5) {
			clearscreen(5, 5, 20, 90);
			string x;
			textcolor(0);
			khung(30, 5, 60, 2, 3, 1, "Nhap ma so de tai: ");
			gotoxy(51, 6);
			textcolor(0);
			setcolor(7);
			cin >> x; cin.ignore();
			chitietdt(x);
			//cin.ignore();
		}
		else if (chon == 6) {
			clearscreen(5, 5, 20, 90);
			int x;
			textcolor(0);
			khung(30, 5, 60, 2, 3, 1, "Nhap nam bat dau de tai: ");
			gotoxy(57, 6);
			textcolor(0);
			setcolor(7);
			cin >> x; cin.ignore();
			chiphi(x);
			//cin.ignore();
		}
		else break;
	}
}
//Thanh sáng dịch chuyển
void thanh_sang(int x, int y, int w, int h, int maunen, string nd)
{

	textcolor(maunen);
	for (int iy = y + 1; iy <= y + h - 1; iy++)
	{
		for (int ix = x + 1; ix <= x + w - 1; ix++)
		{
			gotoxy(ix, iy); cout << " ";

		}
	}
	setcolor(7);
	gotoxy(x + 2, y + 1);
	cout << nd;
}

//vẽ khung
void khung(int x, int y, int w, int h, int mauchu, int maunen, string nd) {
	textcolor(7);
	gotoxy(x + 2, y + 1);
	cout << nd;
	textcolor(1);
	setcolor(mauchu);
	if (h <= 1 || w <= 1)return;
	for (int ix = x; ix <= x + w; ix++) {
		gotoxy(ix, y);
		cout << char(151);
		gotoxy(ix, y + h);
		cout << char(151);
	}
	for (int iy = y; iy <= y + h; iy++) {
		gotoxy(x, iy);
		cout << /*char(179)*/"|";
		gotoxy(x + w, iy);
		cout << /*char(179)*/ "|";
	}
	gotoxy(x, y); cout << /*char(218)*/">";
	gotoxy(x + w, y); cout << /*char(191)*/ "<";
	gotoxy(x, y + h); cout << /*char(192)*/">";
	gotoxy(x + w, y + h); cout << /*char(217)*/ "<";
}
// vẽ n khung gần nhau
void n_khung(int x, int y, int w, int h, int mauchu, int maunen, string nd[], int sl) {
	for (int i = 0; i < sl; i++)
	{
		khung(x, y + (i * h), w, h, mauchu, maunen, nd[i]);//i = 0 => x,y, i = 1: x,y+2
		if (i != 0)
		{
			gotoxy(x, y + (i * h)); cout << /*char(195)*/"|";
			gotoxy(x + w, y + (i * h)); cout << /*char(180)*/"|";
		}
	}
}

//menu
int menu(string nd[], int sl, int goi) {
	clearscreen(5, 5, 20, 175);
	int w = 60;
	int h = 2;
	int t_color = 42;		//màu chữ
	int b_color = 1;		// màu nền
	int b_color_sang = 75;
	int x = 30, y = 5;
	n_khung(x, y, w, h, t_color, b_color, nd, sl);

	int xp = x; int yp = y;//tọa độ thanh sáng
	int xcu = xp; int ycu = yp;	// tọa độ lưu lại ô đằng trước
	bool kt = true;
	int luachon = 0;
	while (true) {
		if (kt == true) {
			xcu = xp; ycu = yp;
			thanh_sang(xp, yp, w, h, b_color_sang, "-> " + nd[luachon]);
			kt = false;
		}
		//điều khiển
		if (_kbhit()) {
			char c = _getch();
			if (c == -32) {
				kt = true;// đã bấm
				c = _getch();
				if (c == 72 || c == 75) {
					if (yp != y) {
						gotoxy(xcu, ycu);
						thanh_sang(xcu, ycu, w, h, b_color, nd[luachon]);	//in lại ô đằng trước
						yp -= h;
						luachon--;
					}
					else {
						gotoxy(xcu, ycu);
						thanh_sang(xcu, ycu, w, h, b_color, nd[luachon]);
						yp = y + h * (sl - 1);
						luachon = sl - 1;
					}
				}
				else if (c == 80 || c == 77) {
					if (yp != y + h * (sl - 1)) {
						gotoxy(xcu, ycu);
						thanh_sang(xcu, ycu, w, h, b_color, nd[luachon]);
						luachon++;
						yp += 2;
					}
					else {
						gotoxy(xcu, ycu);
						thanh_sang(xcu, ycu, w, h, b_color, nd[luachon]);
						yp = y;
						luachon = 0;
					}
				}
			}
			else if (c == 27) {
				return 10;
			}
			else if (c == 13) {
				if (goi == 0) return luachon;
				else if (goi == 1) {
					if (luachon == 0) {
						clearscreen(5, 5, 20, 90);
						int n;
						khung(30, 5, 60, 2, 3, 10, "So luong nhan vien can them: ");
						textcolor(7);
						gotoxy(61, 6);
						cin >> n;
						nhapnv(n);
						break;
					}
					else if (luachon == 1) {
						clearscreen(5, 5, 20, 90);
						int n;
						khung(30, 5, 60, 2, 3, 10, "So luong de tai can them: ");
						textcolor(7);
						gotoxy(58, 6);
						cin >> n;
						nhapdetai(n);
						break;

					}
					else if (luachon == 2) {
						clearscreen(5, 5, 20, 90);
						int n;
						khung(30, 5, 60, 2, 3, 10, "So luong nhan vien de tai can them: ");
						textcolor(7);
						gotoxy(68, 6);
						cin >> n;
						nhapnvdt(n);
						break;

					}
				}
				else if (goi == 2) {
					if (luachon == 0) {
						clearscreen(5, 5, 20, 90);
						string x;
						khung(30, 5, 60, 2, 3, 10, "Nhap ma nhan vien can sua: ");
						textcolor(7);
						gotoxy(59, 6);
						cin >> x; cin.ignore();
						editnv(x);
						break;

					}
					else if (luachon == 1) {
						clearscreen(5, 5, 20, 90);
						string x;
						khung(30, 5, 60, 2, 3, 10, "Nhap ma de tai can sua: ");
						textcolor(7);
						gotoxy(56, 6);
						cin >> x; cin.ignore();
						editdt(x);
						break;

					}
					else if (luachon == 2) {
						clearscreen(5, 5, 20, 90);
						string x, y;	// x: mã nhân viên, y: mã đề tài
						khung(30, 5, 60, 2, 3, 10, "Nhap ma nhan vien: ");
						textcolor(7);
						gotoxy(51, 6);
						cin >> x; cin.ignore();
						khung(30, 7, 60, 2, 3, 10, "Nhap ma de tai: ");
						textcolor(7);
						gotoxy(48, 8);
						cin >> y; cin.ignore();
						editnvdt(x, y);
						break;
					}
				}
				else if (goi == 3) {
					if (luachon == 0) {
						clearscreen(5, 5, 20, 90);
						string x;
						khung(30, 5, 60, 2, 3, 1, "Nhap ma nhan vien can xoa: ");
						textcolor(7);
						gotoxy(59, 6);
						cin >> x; cin.ignore();
						xoanv(x);
						break;

					}
					else if (luachon == 1) {
						clearscreen(5, 5, 20, 90);
						string x;
						khung(30, 5, 60, 2, 3, 10, "Nhap ma de tai can xoa: ");
						textcolor(7);
						gotoxy(56, 6);
						cin >> x; cin.ignore();
						xoadt(x);
						break;

					}
					else if (luachon == 2) {
						clearscreen(5, 5, 20, 90);
						string x, y;	// x: mã nhân viên, y: mã đề tài
						khung(30, 5, 60, 2, 3, 10, "Nhap thong tin nhan vien de tai can xoa");
						khung(30, 8, 60, 2, 3, 10, "Nhap ma nhan vien: ");
						textcolor(7);
						gotoxy(51, 9);
						cin >> x; cin.ignore();
						khung(30, 10, 60, 2, 3, 10, "Nhap ma de tai: ");
						textcolor(7);
						gotoxy(48, 11);
						cin >> y; cin.ignore();
						xoanvdt(x, y);
						break;

					}
				}
			}
		}
	}
}
// chức năng

// kiểm tra nếu mã nhân viên đã tồn tại thì trả về false, ko tồn tại hoặc ko có đề tài nào thì trả về true
bool checkidnv(string x) {
	if (nhanvien.size() != 0) {
		for (int i = 0; i < nhanvien.size(); i++) {
			if (nhanvien[i].id == x) return false;
		}
		return true;
	}
	return true;
}
// kiểm tra nếu mã đề tài đã tồn tại thì trả về false, ko tồn tại hoặc chưa có đề tài trong nào thì trả về true
bool checkiddt(string x) {
	if (detai.size() != 0) {
		for (int i = 0; i < detai.size(); i++) {
			if (detai[i].id == x) return false;
		}
		return true;
	}
	return true;
}
// kiểm tra mã đề tài và mã nhân viên có trong NVDT, trả về false nếu tồn tại, true nếu ko tồn tại
// x = mã nhân viên, y = mã đề tài
bool checknvdt(string x, string y) {
	if (nhanviendetai.size() != 0) {
		for (int i = 0; i < nhanviendetai.size(); i++) {
			if (nhanviendetai[i].idnv == x && nhanviendetai[i].iddt == y) return false;
		}
		return true;
	}
	return true;
}

// thêm nhân viên
void addnv(NV x) {
	if (checkidnv(x.id)) {
		//gotoxy(11, 35); cout << slnv;
		nhanvien.push_back(x);
		khung(20, 21, 80, 2, 3, 1, "\t\t\t\tThem thong tin thanh cong");
		cin.ignore();
		ghiNV(x);
	}
	else {
		khung(20, 21, 80, 2, 3, 1, "\tThem thong tin khong thanh cong do ma nhan vien da ton tai");
		cin.ignore();
	}
}
// nhập thông tin n nhân viên
void nhapnv(int n) {
	for (int i = 0; i < n; i++) {
		clearscreen(20, 10, 80, 24);
		khung(20, 8, 80, 2, 3, 1, "\t\t\t\tNhap thong tin nhan vien");
		NV x;
		khung(20, 10, 80, 2, 3, 1, "Nhap ma nhan vien: "); setcolor(7);
		gotoxy(41, 11);	cin >> x.id; cin.ignore();
		khung(20, 12, 80, 2, 3, 1, "Nhap ho ten nhan vien: "); setcolor(7);
		string temp;
		gotoxy(45, 13); getline(cin, temp);
		x.hoten1 = temp.substr(0, temp.length() / 2); x.hoten2 = temp.substr(temp.length() / 2);
		khung(20, 14, 80, 2, 3, 1, "Nhap gioi tinh nhan vien: "); setcolor(7);
		gotoxy(48, 15); cin >> x.sex; cin.ignore();
		while ((x.sex != "nam" && x.sex != "nu")) {
			clearscreen(20, 15, 80, 2);
			khung(20, 14, 80, 2, 3, 1, "Gioi tinh vua nhap khong dung, vui long nhap lai: "); setcolor(7);
			gotoxy(72, 15); cin >> x.sex; cin.ignore();
		}
		khung(20, 16, 80, 2, 3, 1, "Nhap ngay thang nam sinh: "); setcolor(7);
		gotoxy(48, 17); cin >> x.ngay; cin.ignore(); gotoxy(50, 17); cout << "/";
		gotoxy(51, 17); cin >> x.thang; cin.ignore(); gotoxy(53, 17); cout << "/";
		gotoxy(54, 17); cin >> x.nam; cin.ignore();
		while ((x.thang < 1 || x.thang>12) || (x.nam < 1900 || x.nam>2023) || (x.ngay > checkday(x.nam, x.thang) || x.ngay < 1)) {
			clearscreen(20, 17, 80, 2);
			khung(20, 16, 80, 2, 3, 1, "Ngay thang vua nhap khong dung, vui long nhap lai: "); setcolor(7);
			gotoxy(73, 17); cin >> x.ngay; cin.ignore(); gotoxy(75, 17); cout << "/";
			gotoxy(76, 17); cin >> x.thang; cin.ignore(); gotoxy(78, 17); cout << "/";
			gotoxy(79, 17); cin >> x.nam; cin.ignore();
		}
		while ((x.sex != "nam" && x.sex != "nu")) {
			clearscreen(20, 19, 80, 2);
			khung(20, 18, 80, 2, 3, 1, "Gioi tinh vua nhap khong dung, vui long nhap lai: "); setcolor(7);
			gotoxy(72, 19);
			cin >> x.sex;
			cin.ignore();
		}
		addnv(x);
	}
}
// thêm đề tài
void adddt(DT x) {
	if (checkiddt(x.id)) {
		detai.push_back(x);
		ghiDT(x);
		khung(20, 21, 80, 2, 3, 1, "\t\t\t\tThem thong tin thanh cong");
		//cin.ignore();
	}
	else {
		khung(20, 21, 80, 2, 3, 1, "\tThem thong tin khong thanh cong do ma de tai da ton tai");
		//cin.ignore();
	}
	cin.ignore();
}
// thêm n đề tài
void nhapdetai(int n) {
	for (int i = 0; i < n; i++) {
		clearscreen(20, 10, 78, 22);
		khung(20, 8, 80, 2, 3, 1, "\t\t\t\tNhap thong tin de tai");
		DT x;
		khung(20, 10, 80, 2, 3, 1, "Nhap ma de tai: "); setcolor(7);
		gotoxy(38, 11);	cin >> x.id; cin.ignore();
		khung(20, 12, 80, 2, 3, 1, "Nhap ten de tai: "); setcolor(7);
		string temp; gotoxy(39, 13); getline(cin, temp);
		x.ten1 = temp.substr(0, temp.length() / 2); x.ten2 = temp.substr(temp.length() / 2);
		khung(20, 14, 80, 2, 3, 1, "Nhap nam bat dau: "); setcolor(7);
		gotoxy(40, 15); cin >> x.bd;
		khung(20, 16, 80, 2, 3, 1, "Nhap nam ket thuc: "); setcolor(7);
		gotoxy(41, 17); cin >> x.kt;
		while (x.bd > x.kt) {
			clearscreen(20, 15, 80, 7);
			khung(20, 14, 80, 2, 3, 1, "Thong tin khong dung, nhap lai nam bat dau: "); setcolor(7);
			gotoxy(66, 15); cin >> x.bd;
			cin.ignore();
			khung(20, 16, 80, 2, 3, 1, "Thong tin khong dung, nhap nam ket thuc: "); setcolor(7);
			gotoxy(63, 17); cin >> x.kt;
		}
		khung(20, 18, 80, 2, 3, 1, "Nhap kinh phi thuc hien: "); setcolor(7);
		gotoxy(47, 19); cin >> x.cost;
		adddt(x);
		cin.ignore();
	}
}

// thêm nhân viên đề tài
void addnvdt(NVDT x) {
	if (!checkidnv(x.idnv) && !checkiddt(x.iddt) && checknvdt(x.idnv, x.iddt)) {
		nhanviendetai.push_back(x);
		ghiNVDT(x);
		khung(20, 19, 80, 2, 3, 1, "\t\t\t\tThem thong tin thanh cong");
		cin.ignore();
	}
	else if (!checkidnv(x.idnv) && !checkiddt(x.iddt) && !checknvdt(x.idnv, x.iddt)) {
		khung(20, 19, 80, 2, 3, 1, "\t\t\t\tThong tin da ton tai");
		cin.ignore();
	}
	else if (checkidnv(x.idnv) && !checkiddt(x.iddt)) {
		khung(20, 19, 80, 2, 3, 1, "\t\t\t\tMa nhan vien khong ton tai");
		cin.ignore();
	}
	else if (checkiddt(x.iddt) && !checkidnv(x.idnv)) {
		khung(20, 19, 80, 2, 3, 1, "\t\t\t\tMa de tai khong ton tai");
		cin.ignore();
	}
	else {
		khung(20, 19, 80, 2, 3, 1, "\t\t\tMa nhan vien va ma de tai khong ton tai");
		cin.ignore();
	}
}
// thêm n nhân viên đề tài 
void nhapnvdt(int n) {
	for (int i = 0; i < n; i++) {
		clearscreen(20, 10, 78, 21);
		khung(20, 8, 80, 2, 3, 1, "\t\t\t\t\tNhap thong tin");
		NVDT x;
		khung(20, 10, 80, 2, 3, 1, "Nhap ma de tai: "); setcolor(7);
		gotoxy(38, 11);	cin >> x.iddt; cin.ignore();
		khung(20, 12, 80, 2, 3, 1, "Nhap ma nhan vien: "); setcolor(7);
		gotoxy(41, 13);	cin >> x.idnv; cin.ignore();
		khung(20, 14, 80, 2, 3, 1, "Nhap vai tro nhan vien: "); setcolor(7);
		gotoxy(46, 15);	getline(cin, x.title);
		addnvdt(x);
	}
}

//sửa thông tin nhân viên
void editnv(string x) {
	if (nhanvien.size() != 0) {
		int fl = 0;
		for (int i = 0; i < nhanvien.size(); i++) {
			if (nhanvien[i].id == x) {
				fl = 1;
				khung(20, 8, 80, 2, 3, 1, "Ho ten nhan vien: "); setcolor(7);
				gotoxy(40, 9); cout << nhanvien[i].hoten1 + nhanvien[i].hoten2;
				khung(20, 10, 80, 2, 3, 1, "Nhap lai ho ten nhan vien: "); setcolor(7);
				string temp; gotoxy(49, 11); getline(cin, temp);
				nhanvien[i].hoten1 = temp.substr(0, temp.length() / 2); nhanvien[i].hoten2 = temp.substr(temp.length() / 2);
				khung(20, 12, 80, 2, 3, 1, "Gioi tinh nhan vien: "); setcolor(7);
				gotoxy(43, 13); cout << nhanvien[i].sex;
				khung(20, 14, 80, 2, 3, 1, "Nhap lai gioi tinh nhan vien: "); setcolor(7);
				gotoxy(52, 15); cin >> nhanvien[i].sex;
				cin.ignore();
				while ((nhanvien[i].sex != "nam" && nhanvien[i].sex != "nu")) {
					clearscreen(20, 15, 80, 2);
					khung(20, 14, 80, 2, 3, 1, "Gioi tinh vua nhap khong dung, vui long nhap lai: "); setcolor(7);
					gotoxy(72, 15);
					cin >> nhanvien[i].sex;
					cin.ignore();
				}
				khung(20, 16, 80, 2, 3, 1, "Ngay thang nam sinh: "); setcolor(7);
				gotoxy(43, 17); cout << nhanvien[i].ngay << "/" << nhanvien[i].thang << "/" << nhanvien[i].nam;
				khung(20, 18, 80, 2, 3, 1, "Nhap lai ngay thang nam sinh: "); setcolor(7);
				gotoxy(52, 19); cin >> nhanvien[i].ngay; cin.ignore(); gotoxy(54, 19); cout << "/";
				gotoxy(55, 19); cin >> nhanvien[i].thang; cin.ignore(); gotoxy(57, 19); cout << "/";
				gotoxy(58, 19); cin >> nhanvien[i].nam; cin.ignore();
				while ((nhanvien[i].thang < 1 || nhanvien[i].thang>12) || (nhanvien[i].nam < 1900 || nhanvien[i].nam>2023) || (nhanvien[i].ngay > checkday(nhanvien[i].nam, nhanvien[i].thang) || nhanvien[i].ngay < 1)) {
					clearscreen(20, 19, 80, 2);
					khung(20, 18, 80, 2, 3, 1, "Ngay thang vua nhap khong dung, vui long nhap lai: "); setcolor(7);
					gotoxy(73, 19); cin >> nhanvien[i].ngay; cin.ignore(); gotoxy(75, 19); cout << "/";
					gotoxy(76, 19); cin >> nhanvien[i].thang; cin.ignore(); gotoxy(78, 19); cout << "/";
					gotoxy(79, 19); cin >> nhanvien[i].nam; cin.ignore();
				}
				fstream file("NV.bin", std::ios::in | std::ios::out | std::ios::binary);
				streampos edit = i * sizeof(NV);	//lấy vị trí chỉnh sửa
				file.seekp(edit);
				file.write(reinterpret_cast<const char*>(&nhanvien[i]), sizeof(nhanvien[i]));
				file.close();
				khung(20, 23, 80, 2, 3, 1, "\t\t\t\tSua thong tin thanh cong");
				cin.ignore();
			}
		}
		if (fl == 0) {
			khung(20, 19, 80, 2, 3, 1, "\t\t\t\tKhong tim thay ma nhan vien"); cin.ignore();
		}
	}
	else {
		khung(20, 19, 80, 2, 3, 1, "\t\t\tKhong co thong tin nhan vien trong danh sach"); cin.ignore();
	}
}
// Sửa thông tin đề tài
void editdt(string x) {
	if (detai.size() != 0) {
		int fl = 0;
		for (int i = 0; i < detai.size(); i++) {
			if (detai[i].id == x) {
				fl = 1;
				khung(20, 8, 80, 2, 3, 1, "Ten de tai: "); setcolor(7);
				gotoxy(34, 9); cout << detai[i].ten1+ detai[i].ten2;
				khung(20, 10, 80, 2, 3, 1, "-> Nhap lai ten de tai: "); setcolor(7);
				string temp; gotoxy(46, 11); getline(cin, temp);
				detai[i].ten1 = temp.substr(0, temp.length() / 2); detai[i].ten2 = temp.substr(temp.length() / 2);
				khung(20, 12, 80, 2, 3, 1, "Nam bat dau de tai: "); setcolor(7);
				gotoxy(42, 13); cout << detai[i].bd;
				khung(20, 14, 80, 2, 3, 1, "-> Nhap lai nam bat dau de tai: "); setcolor(7);
				gotoxy(54, 15); cin >> detai[i].bd;
				khung(20, 16, 80, 2, 3, 1, "Nam ket thuc de tai: "); setcolor(7);
				gotoxy(43, 17); cout << detai[i].kt;
				khung(20, 18, 80, 2, 3, 1, "-> Nhap lai nam ket thuc de tai: "); setcolor(7);
				gotoxy(55, 19); cin >> detai[i].kt;
				while (detai[i].bd > detai[i].kt) {
					clearscreen(20, 13, 80, 15);
					khung(20, 12, 80, 2, 3, 1, "Nam bat dau de tai: "); setcolor(7);
					gotoxy(42, 13); cout << detai[i].bd;
					khung(20, 14, 80, 2, 3, 1, "-> Thong tin khong dung, vui long nhap lai nam bat dau de tai: "); setcolor(7);
					gotoxy(85, 15); cin >> detai[i].bd;
					khung(20, 16, 80, 2, 3, 1, "Nam ket thuc de tai: "); setcolor(7);
					gotoxy(43, 17); cout << detai[i].kt;
					khung(20, 18, 80, 2, 3, 1, "-> Nhap lai nam ket thuc de tai: "); setcolor(7);
					gotoxy(55, 19); cin >> detai[i].kt;
				}
				khung(20, 20, 80, 2, 3, 1, "Kinh phi thuc hien de tai: "); setcolor(7);
				gotoxy(49, 21); cout << detai[i].cost;
				khung(20, 22, 80, 2, 3, 1, "-> Nhap lai kinh phi thuc hien de tai: "); setcolor(7);
				gotoxy(61, 23); cin >> detai[i].cost;
				fstream file("DT.bin", std::ios::in | std::ios::out | std::ios::binary);
				streampos edit = i * sizeof(DT);	//lấy vị trí chỉnh sửa
				file.seekp(edit);
				file.write(reinterpret_cast<const char*>(&detai[i]), sizeof(detai[i]));
				file.close();
				khung(20, 25, 80, 2, 3, 1, "\t\t\t\tSua thong tin thanh cong");
				cin.ignore();
			}
		}
		if (fl == 0) {
			khung(20, 19, 80, 2, 3, 1, "\t\t\t\tKhong tim thay ma de tai"); cin.ignore();
		}
	}
	else { khung(20, 19, 80, 2, 3, 1, "\t\t\tKhong co thong tin de tai trong danh sach"); cin.ignore(); }
	cin.ignore();
}
// sửa thông tin nhân viên đề tài
// x= mã nhân viên, y= mã đề tài
void editnvdt(string x, string y) {
	if (nhanviendetai.size() != 0) {
		int fl = 0;
		for (int i = 0; i < nhanviendetai.size(); i++) {
			if (nhanviendetai[i].idnv == x && nhanviendetai[i].iddt == y) {
				NVDT a;
				do {
					clearscreen(20, 11, 80, 2);
					khung(20, 10, 80, 2, 3, 1, "-> Nhap lai ma nhan vien: "); setcolor(7);
					gotoxy(48, 11); cin >> a.idnv; cin.ignore();
				} while (checkidnv(a.idnv));
				do {
					clearscreen(20, 14, 80, 2);
					khung(20, 13, 80, 2, 3, 1, "-> Nhap lai ma de tai: "); setcolor(7);
					gotoxy(45, 14); cin >> a.iddt; cin.ignore();
				} while (checkiddt(a.iddt));
				for (;;) {
					if (checknvdt(a.idnv, a.iddt) || (a.idnv == x && a.iddt == y)) break;
					else {
						clearscreen(20, 11, 80, 10);
						khung(20, 10, 80, 2, 3, 1, "Thong tin da ton tai vui long nhap lai");
						do {
							clearscreen(20, 14, 80, 2);
							khung(20, 13, 80, 2, 3, 1, "-> Nhap lai ma nhan vien: "); setcolor(7);
							gotoxy(48, 14); cin >> a.idnv; cin.ignore();
						} while (checkidnv(a.idnv));
						do {
							clearscreen(20, 16, 80, 2);
							khung(20, 15, 80, 2, 3, 1, "-> Nhap lai ma de tai: "); setcolor(7);
							gotoxy(45, 16); cin >> a.iddt; cin.ignore();
						} while (checkiddt(a.iddt));
					}
				}
				khung(20, 17, 80, 2, 3, 1, "Vai tro cua nhan vien: "); setcolor(7);
				gotoxy(45, 18); cout << nhanviendetai[i].title;
				khung(20, 19, 80, 2, 3, 1, "-> Nhap lai vai tro cua nhan vien: "); setcolor(7);
				gotoxy(57, 20); getline(cin, nhanviendetai[i].title);
				fl = 1;
				fstream file("NVDT.bin", std::ios::in | std::ios::out | std::ios::binary);
				streampos edit = i * sizeof(NVDT);	//lấy vị trí chỉnh sửa
				file.seekp(edit);
				file.write(reinterpret_cast<const char*>(&nhanviendetai[i]), sizeof(nhanviendetai[i]));
				file.close();
				khung(20, 22, 80, 2, 3, 1, "\t\t\t\tSua thong tin thanh cong");
				cin.ignore();
			}
		}
		if (fl == 0) { khung(20, 19, 80, 2, 3, 1, "\t\t\t\tKhong tim thay thong tin"); cin.ignore(); }
	}
	else { khung(20, 19, 80, 2, 3, 1, "\t\t\tKhong co thong tin trong danh sach"); cin.ignore(); }
}
// xóa thông tin nhân viên
void xoanv(string x) {
	if (nhanvien.size() != 0) {
		int k = 0;
		ofstream file("NV.bin", ios::binary | ios::trunc);	file.close();	/*xóa toàn bộ thông tin trong file*/
		ofstream filenvdt("NVDT.bin", ios::binary | ios::trunc); filenvdt.close();
		int slnv = nhanvien.size();
		for (int i = 0; i < slnv; i++) {
			if (nhanvien[i].id == x) {
				nhanvien.erase(nhanvien.begin() + i);
				i--;
				slnv--;
				k = 1;
				khung(20, 13, 80, 2, 3, 1, "\t\t\t\tXoa thong tin thanh cong");
				cin.ignore();
			}
			else {
				
				ghiNV(nhanvien[i]);
			}
		}
		int slnvdt = nhanviendetai.size();
		for (int i = 0; i < slnvdt; i++) {
			if (nhanviendetai[i].idnv == x) {
				nhanviendetai.erase(nhanviendetai.begin() + i);
				i--;
				slnvdt--;
			}
			else {
				ghiNVDT(nhanviendetai[i]);
			}
		}
		if (k == 0) { khung(20, 13, 80, 2, 3, 1, "\t\t\t\tKhong tim thay ma nhan vien"); cin.ignore(); }
		file.close();
	}
	else { khung(20, 13, 80, 2, 3, 1, "\t\t\tKhong co thong tin nhan vien trong danh sach"); cin.ignore(); }
}
// xóa thông tin đề tài
void xoadt(string x) {
	if (detai.size() != 0) {
		int k = 0;
		ofstream filedt("DT.bin", ios::binary | ios::trunc);	//xóa toàn bộ thông tin trong file
		filedt.close();
		ofstream filenvdt("NVDT.bin", ios::binary | ios::trunc); filenvdt.close();
		int sldt = detai.size();
		for (int i = 0; i < sldt; i++) {
			if (detai[i].id == x) {
				detai.erase(detai.begin() + i);
				k = 1;
				sldt--;
				i--;
				khung(20, 13, 80, 2, 3, 1, "\t\t\t\tXoa thong tin thanh cong");
				cin.ignore();
			}
			else {
				ghiDT(detai[i]);
			}
		}
		int slnvdt = nhanviendetai.size();
		for (int i = 0; i < slnvdt; i++) {
			if (nhanviendetai[i].iddt == x) {
				nhanviendetai.erase(nhanviendetai.begin() + i);
				slnvdt--;
				i--;
			}
			else {
				ghiNVDT(nhanviendetai[i]);
			}
		}
		if (k == 0) { khung(20, 13, 80, 2, 3, 1, "\t\t\t\tKhong tim thay ma de tai"); cin.ignore(); }
	}
	else { khung(20, 13, 80, 2, 3, 1, "\t\t\tKhong co thong tin de tai trong danh sach"); cin.ignore(); }
}
// xóa thông tin nhân viên đề tài
// x= mã nhân viên, y= mã đề tài
void xoanvdt(string x, string y) {
	if (nhanviendetai.size() != 0) {
		int k = 0;
		ofstream file("NVDT.bin", ios::binary | ios::trunc); file.close();
		int slnvdt = nhanviendetai.size();
		for (int i = 0; i < slnvdt; i++) {
			if (nhanviendetai[i].idnv == x && nhanviendetai[i].iddt == y) {
				nhanviendetai.erase(nhanviendetai.begin() + i);
				k = 1;
				i--;
				slnvdt--;
				khung(20, 21, 80, 2, 3, 1, "\t\t\t\tXoa thong tin thanh cong");
				cin.ignore();
				
			}
			else {
				ghiNVDT(nhanviendetai[i]);
			}
		}
		if (k == 0) { khung(20, 15, 80, 2, 3, 1, "\t\t\t\tKhong tim thay ma thong tin"); cin.ignore(); }
	}
	else { khung(20, 15, 80, 2, 3, 1, "\t\tKhong co thong tin trong danh sach nhan vien de tai"); cin.ignore(); }
}

// danh sách đề tài và vai trò của nhân viên trong từng đề tài
void list(string x) {
	clearscreen(5, 5, 20, 90);
	if (nhanviendetai.size() != 0) {
		int k = 0;
		int xx = 20, yy = 10;
		khung(20, 5, 80, 2, 3, 1, "\t\t\t  Thong tin de tai cua:");
		for (int i = 0; i < nhanvien.size(); i++) {
			if (nhanvien[i].id == x) {
				gotoxy(64, 6); setcolor(7); cout << nhanvien[i].hoten1+ nhanvien[i].hoten2;
				break;
			}
		}
		khung(xx, 8, 50, 2, 3, 1, "\t\t\tTen de tai");
		khung(xx + 50, 8, 30, 2, 3, 1, "\t   Vai tro");
		for (int i = 0; i < nhanviendetai.size(); i++) {
			if (nhanviendetai[i].idnv == x) {
				// Tìm tên đề tài nhân viên tham gia
				for (int j = 0; j < detai.size(); j++) {
					if (detai[j].id == nhanviendetai[i].iddt) {
						khung(xx, yy + k * 2, 50, 2, 3, 1, detai[j].ten1+detai[j].ten2);
						//cout << detai[i].ten;
						break;
					}
				}
				khung(xx + 50, yy + k * 2, 30, 2, 3, 1, nhanviendetai[i].title);
				k++;
			}
		}
		if (k == 0) {
			khung(xx, 10, 50, 2, 3, 1, "\t\t\t   Trong");
			khung(xx + 50, 10, 30, 2, 3, 1, "\t   Trong");
			cin.ignore();
		}
	}
	else {
		khung(30, 5, 60, 2, 3, 1, "Danh sach trong");
		cin.ignore();

	}
	//cin.ignore();
}

// hiển thị đề tài trong năm bắt đầu
void listdt(int x) {
	clearscreen(5, 5, 20, 90);
	if (detai.size() != 0) {
		int k = 0;
		int xx = 20, yy = 11;
		khung(20, 5, 80, 2, 3, 1, "\t\t\t\tThong tin de tai trong nam: ");
		gotoxy(76, 6); setcolor(7); cout << x;
		khung(xx, 8, 20, 2, 3, 1, "     Ma de tai");
		khung(xx + 20, 8, 40, 2, 3, 1, "\t\tTen de tai");
		khung(xx + 60, 8, 20, 2, 3, 1, "     Chi phi");
		for (int i = 0; i < detai.size(); i++) {
			if (detai[i].bd == x) {
				khung(xx, yy + k * 2, 20, 2, 3, 1, detai[i].id);
				khung(xx + 20, yy + k * 2, 40, 2, 3, 1, detai[i].ten1+ detai[i].ten2);
				khung(xx + 60, yy + k * 2, 20, 2, 3, 1, ""); setcolor(7);
				gotoxy(xx + 61, yy + k * 2 + 1); cout << detai[i].cost;
				k++;
			}
		}
		if (k == 0) khung(30, 12, 60, 2, 3, 1, "\t\tKhong co de tai trong nam");
	}
	else khung(30, 5, 60, 2, 3, 1, "Danh sach trong");
	cin.ignore();
}
// Thông tin chi tiết của để tài
void chitietdt(string x) {
	clearscreen(5, 5, 20, 90);
	if (detai.size() != 0) {
		int k = 0;
		khung(20, 5, 80, 2, 3, 1, "\t\t\t   Thong tin chi tiet de tai:");
		gotoxy(70, 6); setcolor(7); cout << x;
		// tên, năm bắt đầu, kết thúc, chi phí
		for (int i = 0; i < detai.size(); i++) {
			if (detai[i].id == x) {
				k = 1;
				khung(30, 8, 60, 2, 3, 1, "Ten de tai: ");
				setcolor(7); gotoxy(44, 9); cout << detai[i].ten1+ detai[i].ten2;
				khung(30, 10, 60, 2, 3, 1, "Nam bat dau de tai: ");
				setcolor(7); gotoxy(52, 11); cout << detai[i].bd;
				khung(30, 12, 60, 2, 3, 1, "Nam bat dau ket thuc: ");
				setcolor(7); gotoxy(54, 13); cout << detai[i].kt;
				khung(30, 14, 60, 2, 3, 1, "Chi phi de tai: ");
				setcolor(7); gotoxy(48, 15); cout << detai[i].cost;
				break;
			}
		}
		if (k != 0) {
			if (nhanviendetai.size() != 0) {
				int fl = 0;
				int sl = 0;
				// thông tin chủ nhiệm
				khung(30, 16, 60, 2, 3, 1, "Chu nhiem de tai: ");
				setcolor(7);
				for (int i = 0; i < nhanviendetai.size(); i++) {
					if (nhanviendetai[i].title == "chu nhiem" && nhanviendetai[i].iddt == x) {
						
						for (int j = 0; j < nhanvien.size(); j++) {
							if (nhanvien[j].id == nhanviendetai[i].idnv) {
								if (sl == 0) {
									gotoxy(50, 17);  cout << nhanvien[j].hoten1+ nhanvien[j].hoten2;
									fl++;
									sl++;
									break;
								}
								else {
									khung(48, 16 + fl * 2, 41, 2, 3, 1, nhanvien[j].hoten1 + nhanvien[j].hoten2);
									fl++;
									break;
								}
							}
						}
					}
				}
				if (sl == 0) fl++;
				// thông tin thư ký
				sl = 0;
				khung(30, 16 + fl * 2, 60, 2, 3, 1, "Thu ky de tai: ");
				setcolor(7);
				for (int i = 0; i < nhanviendetai.size(); i++) {
					if (nhanviendetai[i].title == "thu ky" && nhanviendetai[i].iddt == x) {
						
						for (int j = 0; j < nhanvien.size(); j++) {
							if (nhanvien[j].id == nhanviendetai[i].idnv) {
								if (sl == 0) {
									gotoxy(47, 16 + fl * 2 + 1); cout << nhanvien[j].hoten1+nhanvien[j].hoten2;
									fl++;
									sl++;
									break;
								}
								else {
									khung(45, 16 + fl * 2, 45, 2, 3, 1, nhanvien[j].hoten1+nhanvien[j].hoten2);
									fl++;
									break;
								}
							}
						}
					}
				}
				if (sl == 0) fl++;
				sl = 0;
				// thông tin thành viên
				khung(30, 16 + fl * 2, 60, 2, 3, 1, "Thanh vien: ");
				setcolor(7);
				for (int i = 0; i < nhanviendetai.size(); i++) {
					if (nhanviendetai[i].title == "thanh vien" && nhanviendetai[i].iddt == x) {
						
						for (int j = 0; j < nhanvien.size(); j++) {
							if (nhanvien[j].id == nhanviendetai[i].idnv) {
								if (sl == 0) {
									gotoxy(44, 16 + fl * 2 + 1); cout << nhanvien[j].hoten1 + nhanvien[j].hoten2;
									fl++;
									sl++;
									break;
								}
								else {
									khung(42, 16 + fl * 2, 48, 2, 3, 1, nhanvien[j].hoten1 + nhanvien[j].hoten2);
									fl++;
									break;
								}
							}
						}
					}
				}
			}
		}
		else if (k == 0) {
			khung(30, 9, 60, 2, 3, 1, "\t\tKhong tim thay ma de tai");
			cin.ignore();
		}

	}
	else {
		khung(30, 5, 60, 2, 3, 1, "Danh sach trong");
		cin.ignore();
	}
	cin.ignore();
}

// tổng kinh phí đề tài bắt đầu trong năm
void chiphi(int x) {
	double chiphi = 0;
	int sl = 0;
	if (detai.size() != 0) {
		for (int i = 0; i < detai.size(); i++) {
			if (detai[i].bd == x) {
				chiphi += detai[i].cost;
				sl++;
			}
		}
		if (sl == 0) { khung(30, 9, 60, 2, 3, 1, "\tKhong co de tai nao trong nam"); cin.ignore(); }
		else {
			khung(30, 9, 60, 2, 3, 1, "Chi phi trong nam la: ");
			setcolor(7);
			gotoxy(54, 10); cout << chiphi;
			cin.ignore();
		}
	}
	else { khung(30, 9, 60, 2, 3, 1, "\t\t     Danh sach trong"); cin.ignore(); }

}
// ghi thông tin nhân viên
void ghiNV(NV x) {
	ofstream file("NV.bin", ios::binary | ios::app);

	if (file) {
		file.write(reinterpret_cast<const char*>(&x), sizeof(NV));
		file.close();
	}
}
vector<NV>nv;
// đọc file nhân viên
void docNV() {
	ifstream file_in("NV.bin", ios::binary);
	if (file_in) {
		// Di chuyển đến cuối file để lấy kích thước
		file_in.seekg(0, ios::end);
		streampos fileSize = file_in.tellg();
		file_in.seekg(0, ios::beg);
		// Tính số lượng đề tài trong file
		size_t sl = fileSize / sizeof(NV);
		// Resize vector để phù hợp với số lượng đề tài
		nv.resize(sl);
		// Đọc thông tin nhân viên từ file vào vector
		file_in.read(reinterpret_cast<char*>(nv.data()), fileSize);
		file_in.close();
		nhanvien = nv;
		nv.shrink_to_fit();
	}
}
// ghi thông tin đề tài
void ghiDT(DT x) {
	ofstream file("DT.bin", ios::binary | ios::app);

	if (file) {
		file.write(reinterpret_cast<const char*>(&x), sizeof(DT));
		file.close();
	}
}
// đọc thông tin đề tài
vector<DT>dt;
void docDT() {
	ifstream file_in("DT.bin", ios::binary);
	if (file_in) {
		// Di chuyển đến cuối file để lấy kích thước
		file_in.seekg(0, ios::end);
		streampos fileSize = file_in.tellg();
		file_in.seekg(0, ios::beg);
		// Tính số lượng đề tài trong file
		size_t sl = fileSize / sizeof(DT);
		// Resize vector để phù hợp với số lượng đề tài
		dt.resize(sl);
		// Đọc thông tin đề tài từ file vào vector
		file_in.read(reinterpret_cast<char*>(dt.data()), fileSize);
		file_in.close();
		detai = dt;
		nv.shrink_to_fit();
	}
}
// ghi thông tin nhân viên đề tài
void ghiNVDT(NVDT x) {
	ofstream file("NVDT.bin", ios::binary | ios::app);

	if (file) {
		file.write(reinterpret_cast<const char*>(&x), sizeof(NVDT));
		file.close();
	}
}
// đọc thông tin nhân viên đề tài
vector<NVDT>nvdt;
void docNVDT() {
	ifstream file_in("NVDT.bin", ios::binary);
	if (file_in) {
		// Di chuyển đến cuối file để lấy kích thước
		file_in.seekg(0, ios::end);
		streampos fileSize = file_in.tellg();
		file_in.seekg(0, ios::beg);
		// Tính số lượng nhan viên đề tài trong file
		size_t sl = fileSize / sizeof(NVDT);
		// Resize vector
		nvdt.resize(sl);
		// Đọc thông tin nhân viên từ file vào vector
		file_in.read(reinterpret_cast<char*>(nvdt.data()), fileSize);
		file_in.close();
		nhanviendetai = nvdt;
		nvdt.shrink_to_fit();
	}
}

