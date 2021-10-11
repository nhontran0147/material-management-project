#include "HoaDon.h"
#define MAX_NhanVien 500
struct NhanVien{
	char MaNV[12];
	char Ho[52];
	char Ten[12];
	char Phai[5];
	Node_DSHoaDon* First_DSHD;
};
struct DanhSachNV{
	NhanVien* DanhSachNhanVien[MAX_NhanVien];
	int NumFact_NV=0;
};
