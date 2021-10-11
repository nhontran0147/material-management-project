#define MAX_CTHD 20
struct MotChiTiet_HD{
	char MaVT[10];
	int SoLuong;
	int DonGia;
	int VAT;
};
struct ChiTietHoaDon{
	MotChiTiet_HD CTHoaDon[MAX_CTHD];
	int NumFact_CTHoaDon=0;
};



