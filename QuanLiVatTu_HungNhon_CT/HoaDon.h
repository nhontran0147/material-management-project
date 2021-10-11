#include "ChiTiet.h"
struct NgayThangNam{
	int ngay;
	int thang;
	int nam;
};
struct HoaDon{
	char SoHD[20];
	NgayThangNam NgayLap;
	char Loai;
	long long trigia;
	ChiTietHoaDon* CTHD;
	HoaDon(){
		CTHD=new ChiTietHoaDon();
		CTHD->NumFact_CTHoaDon=0;
		trigia=0;
	}
	~HoaDon(){
		delete CTHD;
	}
};
struct Node_DSHoaDon{
	HoaDon HDon;
	Node_DSHoaDon* next;
};

