#include <winbgim.h> 
#include "LIB.h"
#include <iostream>
#include <stdio.h>
 int Mapid[MAX_X+1][MAX_Y+1];
void setMapID();
void TaoID(int x1, int y1, int x2, int y2, int id);
void CleanID();
void CleanID2();
int return_click_mouse();
int move_mouse();
void DrawBar(int x1, int y1, int x2, int y2, int maunen);
void WriteText(int x, int y, char text[],  int MauChu, int MauBK,int size);
void setKhung();
void CleanBK();
void DrawRecTangle(int x1, int y1, int x2, int y2,int mau, int size);
void ScanTen(int x, int y, char s[], int lenMax,int mauNen, int id,int &Key);
void ScanTen_NV(int x, int y, char s[], int lenMax,int mauNen, int id,int &Key);
void ScanSo(int x, int y, char *s, int lenMax,int mauNen, int id, int &Key);
void ScanMa(int x, int y, char s[], int lenMax,int mauNen ,int id, int &Key);
void DrawTableVatTu();
void DrawTableVtThem();
void DrawTableVt_Chinh();
void DrawTableVtHieuChinh();
void DrawTableVtInDSVT();
void DrawTableNhanVien();
void DrawTableNvThem();
void DrawTableNvHieuCHinh();
void DrawTableNv_Chinh();
void DrawTableNvInDSNV();
void DrawTableT_Toan();
void DrawTableT_TChiTiet();
void DrawTableT_TLapHoaDon();
void DrawTableT_TSoHD();
void DrawTableT_TInHD();
void DrawTableTke();
void DrawTableTke_Tim();
void DrawTableTke_LietKe();
void DrawTableTke_Top10();
void DrawTableTKe_BangTop10();
void DrawLogIn();
void BaoTrong(int x, int y);
void DrawBegin();
void DrawLoading(int x1, int y1, int x2, int y2);
void DrawWin();
void Xuli();
void LogIn();
void Xuli(){
	
	int Key=0;
	char maVT[50]="";
	char TenVT[50]="";
	char Dvt[50]="";
	char SLT[50]="";
	char MaVtTkiem[50]="";
	char maNV[50]="";
	char HoNV[50]="";
	char TenNV[50]="";
	char Phai[50]="";
	char MaNvTkiem[50]="";
	char soHD[50]="";
	char SoLuong[50]="";
	char DonGia[50]="";
	char VAT[10]="";
	
	char ngay[50]="";
	char thang[50]="";
	char nam[50]="";
	
	char ngay1[50]="";
	char thang1[50]="";
	char nam1[50]="";
	char ngay2[50]="";
	char thang2[50]="";
	char nam2[50]="";
	int TongTrang=0,soTrang=0;
	char charSoTrang[10]="",charTrang[10] ="";
	NgayThangNam start,finish;
	int intNgay1=0, intThang1=0, intNam1=0,intNgay2=0, intThang2=0, intNam2=0;
	bool okNgay1=false,okThang1=false,okNam1=false,okNgay2=false,okThang2=false,okNam2=false;
	
	long long TongHD=0;
	ChiTietHoaDon CTHDon; 
	TODAY(ngay,thang,nam);
	bool okSoHD=false, okMaNV = false, okMaVT=false, okSL = false, okTaoHoaDon = true;
	// kiem tra luu file
	bool GhiDSVT=false,GhiDSNV=false,GhiHD=false;
	int n_HoaDon=0;
	int n_VatTu=0;
	//// doc file 
	PTR_VT Root = NULL;
	InFile_VatTu(Root,n_VatTu);
	DanhSachNV DSNV;
	InFile_NhanVien(DSNV);
	DocFile_HoaDon(DSNV,n_HoaDon);
	bool okNam = false , okNu = false , nhap = false, xuat = false;
	while(true){
		if(kbhit()){
	     	char c= getch();
	    }
		delay(1);
		if (CTHDon.NumFact_CTHoaDon != 0 ) okTaoHoaDon = false ;
		else okTaoHoaDon = true;
		Key= return_click_mouse();
		lable:
		switch (Key){	
			case 1 :
					DrawTableVatTu();
					if (GhiDSVT){
						OutFile_VatTu(Root);
						GhiDSVT= false;
					}
					else if(GhiDSNV){
						OutFile_NhanVien(DSNV);
						GhiDSNV=false;
					}
					else if(GhiHD){
						GhiFile_HoaDon(DSNV);
						GhiHD=false;
					}
					break;
			case 11 : 
					DrawTableVtThem();
					strcpy(maVT,"");
					strcpy(TenVT,"");
					strcpy(Dvt,"");
					strcpy(SLT,"");
					okMaVT = false;
			case 111 : {
				DrawBar(800+5,219,978,260,LWhite);
				ScanMa(420+10,220+5,maVT,10,LWhite,111,Key);
				if (strlen(maVT)==0) {
					okMaVT = false;
					BaoTrong(800,220);
				}
				else if (TimKiem_MaVT(Root,maVT) != NULL){
					okMaVT = false;
					DrawBar(800+5,219,978,260,LWhite);
					WriteText(800+10,220,"MaDaTonTai!",Red,LWhite,sizeChu);
				} else okMaVT = true;
				if (Key!=0 && Key!=-3) goto lable;
				else if (Key!=-3) break;
			}
			case 112 : {
				DrawBar(800+5,269,968,310,LWhite);
				ScanTen(420+10,270+5,TenVT,30,LWhite,112,Key);
				if (strlen(TenVT)==0) {
					BaoTrong(800,270);
				}
				if (Key!=0 && Key!=-3) goto lable;
				else if (Key!=-3) break;
			}
			case 113 : {
				DrawBar(800+5,319,968,360,LWhite);
				ScanTen(420+10,320+5,Dvt,10,LWhite,113,Key);
				if (strlen(Dvt)==0) {
					BaoTrong(800,320);
				}
				if (Key!=0) goto lable;
				else	break;
			}
			case 114 : {
				DrawBar(800+5,369,978,410,LWhite);
				ScanSo(420+10,370+5,SLT,9,LWhite,114,Key);
				if (strlen(SLT)==0) {
					strcpy(SLT,"0");
				}
				if (Key!=0) goto lable;
				else	break;
			}
			case 115 : {
				if (strlen(maVT) != 0 && strlen(TenVT) != 0 && strlen(Dvt) != 0 &&strlen(SLT) != 0 && okMaVT){
					WriteText(450,465,"Them vat tu thanh cong", Green,LWhite,1);
					int temp = CharToInt(SLT);
					themVaoCay(Root,maVT,TenVT,Dvt,temp);
					n_VatTu++;
					strcpy(maVT,"");
					strcpy(TenVT,"");
					strcpy(Dvt,"");
					strcpy(SLT,"");
					okMaVT = false;
					GhiDSVT = true;
					delay(1000);
					DrawTableVtThem();
				}else {
					WriteText(450,465,"Chua dien day du thong tin", Red,LWhite,sizeChu);
					delay(1000);
					DrawBar(440,464,951,485,LWhite);
				}
				break;
			}
			case 12 : {
				DrawTableVtHieuChinh();
				strcpy(MaVtTkiem,"");
				strcpy(maVT,"");
			} 
			case 121 :{
				// nhap ma vat tu tim kiem
				DrawBar(800+5,339,978,380,LWhite);
				ScanMa(500+10,340+5,MaVtTkiem,10,LWhite,121,Key);
				if (strlen(MaVtTkiem)==0){
					BaoTrong(800,340);
				}
				if (Key!=0) goto lable;
				else	break;
			}
			case 122:{
				// nut tim kiem
				DrawBar(800+5,339,978,380,LWhite);
				if (strlen(MaVtTkiem)==0){
					BaoTrong(800,340);
					break;
				}
				PTR_VT p= TimKiem_MaVT(Root,MaVtTkiem);
				if (p==NULL){
					WriteText(420,465,"Vat tu khong ton tai", Red,LWhite,sizeChu);
					delay(1300);
					DrawTableVtHieuChinh();
					strcpy(MaVtTkiem,"");
					break;
				}
				else {
					DrawTableVt_Chinh();
					strcpy(maVT,p->VT.MAVT);
					strcpy(TenVT,p->VT.TENVT);
					strcpy(Dvt,p->VT.DVT);
					int so = p->VT.SLT;
					IntToChar(so,SLT);
					WriteText(420+10,220+5,maVT,LRed,LWhite,1);
					WriteText(420+10,270+5,TenVT,Black,LWhite,1);
					WriteText(420+10,320+5,Dvt,Black,LWhite,1);
					WriteText(420+10,370+5,SLT,LRed,LWhite,1);
	
					TaoID(420,270,800,300,112);
					TaoID(420,320,800,350,113);
					
					TaoID(270,420,600,460,1221);
					TaoID(620,420,950,460,1222);
					break;
				}	
			}
			case 1221 :{
				// nut luu hieu chinh
				PTR_VT p= TimKiem_MaVT(Root,MaVtTkiem);
				if (strlen(TenVT) != 0 && strlen(Dvt) !=0){
					strcpy(p->VT.TENVT,TenVT);
					strcpy(p->VT.DVT,Dvt);
					strcpy(MaVtTkiem,"");
					strcpy(maVT,"");
					strcpy(TenVT,"");
					strcpy(Dvt,"");
					strcpy(SLT,"");
					GhiDSVT= true;
					WriteText(390,465,"Luu thanh cong",Green,LWhite,1);
					delay(1300);
					DrawTableVtHieuChinh();
				}
				break;
			}
			case 1222 : {
				WriteText(390,470,"Ban co chac chan muon xoa khong ?",LRed,LWhite,1);
				
				DrawBar(820,465,880,495,LRed);
				WriteText(820+7,465+5,"NO", Black,LRed,1);
				
				DrawBar(890,465,950,495,LRed);
				WriteText(890+3,465+5,"YES", Black,LRed,1);
				
				TaoID(890,465,950,495,12222);
				TaoID(820,465,880,495,12221);
				// nut xoa hieu chinh
				break;
			}
			case 12221:{
				DrawBar(820,465,880,495,Blue);
				WriteText(820+7,465+5,"NO", Black,Blue,1);
				delay(300);
				DrawBar(380,465,960,496,LWhite);
				break;
			}
			case 12222:{
				DrawBar(890,465,950,495,Blue);
				WriteText(890+3,465+5,"YES", Black,Blue,1);
				GhiDSVT= true;
				Xoa_MotVatTu(Root,maVT);
				n_VatTu--;
				delay(250);
				DrawBar(380,465,960,496,LWhite);
				WriteText(700,470,"Xoa thanh cong",Green,LWhite,1);
				strcpy(MaVtTkiem,"");
				strcpy(maVT,"");
				strcpy(TenVT,"");
				strcpy(Dvt,"");
				strcpy(SLT,"");
				delay(1300);
				DrawTableVtHieuChinh();
				break;
			}
			case 13 : {
					DrawTableVtInDSVT();
					if (n_VatTu == 0) break;
					VatTu *DanhSach_VT= new VatTu[n_VatTu+2];
					int k=0;
					Nap_DanhSachVatTu(Root,DanhSach_VT,k);
					Sort_DanhSachVatTu(DanhSach_VT,0,k-1);
					TongTrang = k/15;
					if (k == 0) TongTrang +=1;
					if (k%15 !=0) TongTrang+=1;
					IntToChar(TongTrang,charTrang);
					soTrang =1;
					WriteText(895,178,"1",Red,Cyan,1);
					WriteText(915,178,"/",Red,Cyan,1);
					WriteText(930,178,charTrang,Red,Cyan,1);
					char temp[50]="";
					int x1=110, y1= 245;
					int soTrang=1;
					for (int i=0; i < 15 && i < n_VatTu ;i++){
						IntToChar(DanhSach_VT[i].SLT,temp);
						WriteText(x1,y1,DanhSach_VT[i].MAVT,Black,LWhite,1);
						WriteText(x1+250,y1,DanhSach_VT[i].TENVT,Black,LWhite,1);
						WriteText(x1+600,y1,DanhSach_VT[i].DVT,Black,LWhite,1);
						WriteText(x1+800,y1,temp,Black,LWhite,1);					
						y1+=22;
					}
					delete []DanhSach_VT;
				break;
			}
			case 132:{ // nut next
				
				if (soTrang+1> TongTrang) break;
				soTrang+=1;
				DrawRecTangle(1020,143,1142,200,Black,2);
				delay(80);
				DrawTableVtInDSVT();
				VatTu *DanhSach_VT= new VatTu[n_VatTu+2];
				int k=0;
				Nap_DanhSachVatTu(Root,DanhSach_VT,k);
				Sort_DanhSachVatTu(DanhSach_VT,0,k-1);
				TongTrang = k/15;
				if (k%15 !=0) TongTrang+=1;
				IntToChar(TongTrang,charTrang);
				IntToChar(soTrang,charSoTrang);
				WriteText(895,178,charSoTrang,Red,Cyan,1);
				WriteText(915,178,"/",Red,Cyan,1);
				WriteText(930,178,charTrang,Red,Cyan,1);
				int x1=110, y1= 245;
				for (int i=0; i<15 && 15*(soTrang-1)+i < k;i++){
					char temp[50];
					IntToChar(DanhSach_VT[15*(soTrang-1)+i].SLT,temp);
					WriteText(x1,y1,DanhSach_VT[15*(soTrang-1)+i].MAVT,Black,LWhite,1);
					WriteText(x1+250,y1,DanhSach_VT[15*(soTrang-1)+i].TENVT,Black,LWhite,1);
					WriteText(x1+600,y1,DanhSach_VT[15*(soTrang-1)+i].DVT,Black,LWhite,1);
					WriteText(x1+800,y1,temp,Black,LWhite,1);					
					y1+=22;
				}
				delete []DanhSach_VT;
				break;
			}
			case 131:{ // nut back
				if (soTrang -1 < 1) break;
				soTrang--;
				DrawRecTangle(110,145-2,230+2,200,Black,2);
				delay(80);
				DrawTableVtInDSVT();
				VatTu *DanhSach_VT= new VatTu[n_VatTu+2];
				int k=0;
				Nap_DanhSachVatTu(Root,DanhSach_VT,k);
				Sort_DanhSachVatTu(DanhSach_VT,0,k-1);
				TongTrang = k/15;
				if (k%15 !=0) TongTrang+=1;
				IntToChar(TongTrang,charTrang);
				IntToChar(soTrang,charSoTrang);
				WriteText(895,178,charSoTrang,Red,Cyan,1);
				WriteText(915,178,"/",Red,Cyan,1);
				WriteText(930,178,charTrang,Red,Cyan,1);
				int x1=110, y1= 245;
				for (int i=0; i<15 && 15*(soTrang-1)+i < k;i++){
					char temp[50];
					IntToChar(DanhSach_VT[15*(soTrang-1)+i].SLT,temp);
					WriteText(x1,y1,DanhSach_VT[15*(soTrang-1)+i].MAVT,Black,LWhite,1);
					WriteText(x1+250,y1,DanhSach_VT[15*(soTrang-1)+i].TENVT,Black,LWhite,1);
					WriteText(x1+600,y1,DanhSach_VT[15*(soTrang-1)+i].DVT,Black,LWhite,1);
					WriteText(x1+800,y1,temp,Black,LWhite,1);					
					y1+=22;
				}
				delete []DanhSach_VT;
				break;
			}		
			case 2 : {
				DrawTableNhanVien();
				if (GhiDSVT){
					OutFile_VatTu(Root);
					GhiDSVT= false;
				}
				else if(GhiDSNV){
					OutFile_NhanVien(DSNV);
					GhiDSNV=false;
				}
				else if(GhiHD){
					GhiFile_HoaDon(DSNV);
					GhiHD=false;
				}
				break;
			}
			case 21 : {
				DrawTableNvThem();
				strcpy(maNV,"");
				strcpy(HoNV,"");
				strcpy(TenNV,"");
				strcpy(Phai,"");
			}
			case 211: {
				DrawBar(800+10,219,968,260,LWhite);
				ScanMa(500+10,220+5,maNV,10,LWhite,111,Key);
				if (strlen(maNV)==0) {
					BaoTrong(800,220);
				}
				else if (TimKiem_MaNV(DSNV,maNV) != -1){
					okMaNV = false;
					DrawBar(800+5,219,978,260,LWhite);
					WriteText(800+10,220,"MaDaTonTai!",Red,LWhite,sizeChu);
				} else okMaNV = true;
				if (Key!=0 && Key!=-3) goto lable;
				else if (Key!=-3) break;
			}
			case 212 :{
				DrawBar(800+5,269,968,310,LWhite);
				ScanTen(500+10,270+5,HoNV,18,LWhite,112,Key);
				if (strlen(HoNV)==0) {
					BaoTrong(800,270);
				}
				if (Key!=0 && Key!=-3) goto lable;
				else if (Key!=-3) break;
			}
			case 213 : {
				DrawBar(800+5,319,968,360,LWhite);
				ScanTen_NV(500+10,320+5,TenNV,18,LWhite,113,Key);
				if (strlen(TenNV)==0) {
					BaoTrong(800,320);
				}
				if (Key!=0) goto lable;
				else	break;
			}		
			case 214 :{
					okNam = true;
					okNu  = false;
					DrawBar(500,370,650,400,Cyan);
					DrawBar(650,370,800,400,LWhite);
					DrawRecTangle(500,370,650,400,Black,1);
					DrawRecTangle(650,370,800,400,Black,1);
					WriteText(500+50,370+7,"NAM",Black,Cyan,sizeChu);
					WriteText(650+55,370+7,"NU",Black,LWhite,sizeChu);
					break;
			}
			case 215: {
					okNam = false;
					okNu  = true;
					DrawBar(500,370,650,400,LWhite);
					DrawBar(650,370,800,400,LMagenta);
					DrawRecTangle(500,370,650,400,Black,1);
					DrawRecTangle(650,370,800,400,Black,1);
					WriteText(500+50,370+7,"NAM",Black,LWhite,sizeChu);
					WriteText(650+55,370+7,"NU",Black,LMagenta,sizeChu);
					break;
			}
			case 216 : {// them
				if (strlen(maNV) != 0 && okMaNV && strlen(TenNV) != 0 && strlen(HoNV) != 0 && (okNam || okNu)){
					if (okNam) strcpy(Phai,"Nam");
					else strcpy(Phai,"Nu");
					ADD_nhanVienMoi(DSNV,maNV,HoNV,TenNV,Phai);
					strcpy(maNV,"");
					strcpy(HoNV,"");
					strcpy(TenNV,"");
					strcpy(Phai,"");
					okMaNV = false;
					okNam = false; okNu = false;
					WriteText(450,465,"Them nhan vien thanh cong", Green,LWhite,sizeChu);
					GhiDSNV = true;
					delay(1300);
					DrawTableNvThem();
				}else {
					WriteText(450,465,"Chua dien day du thong tin", Red,LWhite,sizeChu);
					delay(1000);
					DrawBar(440,464,951,485,LWhite);
				}
				break;
			}
			case 22 :{
				 DrawTableNvHieuCHinh();
			}
			case 221 :{
				DrawBar(800+5,289,968,331,LWhite);
				ScanMa(500+10,290+5,MaNvTkiem,10,LWhite,121,Key);
				if (strlen(MaNvTkiem)==0){
					BaoTrong(800,290);
				}
				if (Key!=0) goto lable;
				else	break;
			}
			case 222:{
				DrawBar(800+5,289,968,331,LWhite);
				if (strlen(MaNvTkiem)==0){
					BaoTrong(800,290);
					break;
				}
				int kq = TimKiem_MaNV(DSNV,MaNvTkiem);
				if (kq == -1){
					WriteText(450,465,"Nhan vien khong ton tai", Red,LWhite,sizeChu);
					delay(1300);
					DrawTableNvHieuCHinh();
					strcpy(MaNvTkiem,"");
					break;
				}
				else {
					DrawTableNv_Chinh();
					strcpy(maNV,DSNV.DanhSachNhanVien[kq]->MaNV);
					strcpy(HoNV,DSNV.DanhSachNhanVien[kq]->Ho);
					strcpy(TenNV,DSNV.DanhSachNhanVien[kq]->Ten);
					strcpy(Phai,DSNV.DanhSachNhanVien[kq]->Phai);
					WriteText(500+10,220+5,maNV,LRed,LWhite,1);
					WriteText(500+10,270+5,HoNV,Black,LWhite,1);
					WriteText(500+10,320+5,TenNV,Black,LWhite,1);
					int gioitinh=strcmp(Phai,"Nam");
					if (gioitinh == 0) {
						okNam = true, okNu = false;
						DrawBar(500,370,650,400,Cyan);
						DrawBar(650,370,800,400,LWhite);
						DrawRecTangle(500,370,650,400,Black,1);
						DrawRecTangle(650,370,800,400,Black,1);
						WriteText(500+50,370+7,"NAM",Black,Cyan,sizeChu);
						WriteText(650+55,370+7,"NU",Black,LWhite,sizeChu);
					}
					else {
						okNam = false, okNu = true;
						DrawBar(500,370,650,400,LWhite);
						DrawBar(650,370,800,400,LMagenta);
						DrawRecTangle(500,370,650,400,Black,1);
						DrawRecTangle(650,370,800,400,Black,1);
						WriteText(500+50,370+7,"NAM",Black,LWhite,sizeChu);
						WriteText(650+55,370+7,"NU",Black,LMagenta,sizeChu);
					}
					// id chinh sua ho & ten
					TaoID(500,270,800,300,212);
					TaoID(500,320,800,350,213);
					// id gioi tinh
					TaoID(500,370,650,400,214);
					TaoID(650,370,800,400,215);
					// id 2 nut luu & xoa
					TaoID(270,420,600,460,2221);
					TaoID(620,420,950,460,2222);
					break;
				}	
				break;
			}
			case 2221 :{
				// nut luu hieu chinh
				int kq = TimKiem_MaNV(DSNV,MaNvTkiem);
				if (strlen(TenNV) != 0 && strlen(HoNV) !=0){
					strcpy(DSNV.DanhSachNhanVien[kq]->Ho,HoNV);
					strcpy(DSNV.DanhSachNhanVien[kq]->Ten,TenNV);
					if (okNam) strcpy(DSNV.DanhSachNhanVien[kq]->Phai,"Nam");
					else strcpy(DSNV.DanhSachNhanVien[kq]->Phai,"Nu");
					
						strcpy(MaNvTkiem,"");
						strcpy(maNV,"");
						strcpy(TenNV,"");
						strcpy(HoNV,"");
						strcpy(Phai,"");
						okNam = false;
						okNu = false;
					GhiDSNV = true;
					WriteText(390,465,"Luu thanh cong",Green,LWhite,1);
					delay(1300);
					DrawTableNvHieuCHinh();	
				}
				break;
			}
			case 2222 : {
				int kq = TimKiem_MaNV(DSNV,MaNvTkiem);
				if (DSNV.DanhSachNhanVien[kq]->First_DSHD != NULL) {
					DrawBar(300-2,465-2,950+2,495+2,LWhite);
					WriteText(390,470,"Nhan vien da lap hoa don, Khong the xoa",LRed,LWhite,1);
					delay(1500);
					DrawTableNvHieuCHinh();
					strcpy(MaNvTkiem,"");
					strcpy(maNV,"");
					strcpy(TenNV,"");
					strcpy(HoNV,"");
					strcpy(Phai,"");
					okNam = false;
					okNu = false;
				}else {
					WriteText(390,470,"Ban co chac chan muon xoa khong ?",LRed,LWhite,1);			
					DrawBar(820,465,880,495,LRed);
					WriteText(820+7,465+5,"NO", Black,LRed,1);
					
					DrawBar(890,465,950,495,LRed);
					WriteText(890+3,465+5,"YES", Black,LRed,1);
					
					TaoID(890,465,950,495,22222);
					TaoID(820,465,880,495,22221);
				}	
				// nut xoa hieu chinh
				break;
			}
			case 22221:{
				DrawBar(820,465,880,495,Blue);
				WriteText(820+7,465+5,"NO", Black,Blue,1);
				delay(300);
				DrawBar(380,465,960,496,LWhite);
				break;
			}
			case 22222:{
				DrawBar(890,465,950,495,Blue);
				WriteText(890+3,465+5,"YES", Black,Blue,1);
				Xoa_MotNhanVien(DSNV,maNV);
				GhiDSNV = true;
				delay(300);
				DrawBar(380,465,960,496,LWhite);
				WriteText(700,470,"Xoa thanh cong",Green,LWhite,1);
					strcpy(MaNvTkiem,"");
					strcpy(maNV,"");
					strcpy(TenNV,"");
					strcpy(HoNV,"");
					strcpy(Phai,"");
					okNam = false;
					okNu = false;
				delay(1300);
				DrawTableNvHieuCHinh();
				break;
			}
			case 23 : {
				DrawTableNvInDSNV();
				Sort_dsNhanVien(DSNV);
				TongTrang = DSNV.NumFact_NV/15;
				if (DSNV.NumFact_NV == 0) TongTrang +=1;
				if (DSNV.NumFact_NV % 15 !=0) TongTrang+=1;
				IntToChar(TongTrang,charTrang);
				soTrang =1;
				WriteText(895,178,"1",Red,Cyan,1);
				WriteText(915,178,"/",Red,Cyan,1);
				WriteText(930,178,charTrang,Red,Cyan,1);
				int x1=110, y1= 245;
				for(int i=0;i<15;++i){
					WriteText(x1,y1,DSNV.DanhSachNhanVien[i]->MaNV,Black,LWhite,1);
					WriteText(x1+250,y1,DSNV.DanhSachNhanVien[i]->Ho,Black,LWhite,1);
					WriteText(x1+600,y1,DSNV.DanhSachNhanVien[i]->Ten,Black,LWhite,1);
					WriteText(x1+850,y1,DSNV.DanhSachNhanVien[i]->Phai,Black,LWhite,1);					
					y1+=22;
				}
				break;
			}
			case 231 : { // nut back
				if (soTrang - 1 < 1 ) break;
				soTrang-=1;
				DrawRecTangle(110,145-2,230+2,200,Black,2);
				delay(80);
				DrawTableNvInDSNV();
				TongTrang = DSNV.NumFact_NV/15;
				if (DSNV.NumFact_NV == 0) TongTrang +=1;
				if (DSNV.NumFact_NV % 15 !=0) TongTrang+=1;
				IntToChar(TongTrang,charTrang);
				IntToChar(soTrang,charSoTrang);
				WriteText(895,178,charSoTrang,Red,Cyan,1);
				WriteText(915,178,"/",Red,Cyan,1);
				WriteText(930,178,charTrang,Red,Cyan,1);
				int x1=110, y1= 245;
				for(int i=0;i<15 && 15*(soTrang-1) +i < DSNV.NumFact_NV;++i){
					WriteText(x1,y1,DSNV.DanhSachNhanVien[15*(soTrang-1)+i]->MaNV,Black,LWhite,1);
					WriteText(x1+250,y1,DSNV.DanhSachNhanVien[15*(soTrang-1)+i]->Ho,Black,LWhite,1);
					WriteText(x1+600,y1,DSNV.DanhSachNhanVien[15*(soTrang-1)+i]->Ten,Black,LWhite,1);
					WriteText(x1+850,y1,DSNV.DanhSachNhanVien[15*(soTrang-1)+i]->Phai,Black,LWhite,1);					
					y1+=22;
				}
				break;
			}
			case 232 : { // nut next
				if (soTrang + 1 > TongTrang) break;
				soTrang+=1;
				DrawRecTangle(1020,145-2,1140+2,200,Black,2);
				delay(80);
				DrawTableNvInDSNV();
				TongTrang = DSNV.NumFact_NV/15;
				if (DSNV.NumFact_NV == 0) TongTrang +=1;
				if (DSNV.NumFact_NV % 15 !=0) TongTrang+=1;
				IntToChar(TongTrang,charTrang);
				IntToChar(soTrang,charSoTrang);
				WriteText(895,178,charSoTrang,Red,Cyan,1);
				WriteText(915,178,"/",Red,Cyan,1);
				WriteText(930,178,charTrang,Red,Cyan,1);
				int x1=110, y1= 245;
				for(int i=0; i < 15 && 15*(soTrang-1)+i < DSNV.NumFact_NV;++i){
					WriteText(x1,y1,DSNV.DanhSachNhanVien[15*(soTrang-1)+i]->MaNV,Black,LWhite,1);
					WriteText(x1+250,y1,DSNV.DanhSachNhanVien[15*(soTrang-1)+i]->Ho,Black,LWhite,1);
					WriteText(x1+600,y1,DSNV.DanhSachNhanVien[15*(soTrang-1)+i]->Ten,Black,LWhite,1);
					WriteText(x1+850,y1,DSNV.DanhSachNhanVien[15*(soTrang-1)+i]->Phai,Black,LWhite,1);					
					y1+=22;
				}
				break;
			}						
			case 3 :{
				 DrawTableT_Toan();	
				if (GhiDSVT){
					OutFile_VatTu(Root);
					GhiDSVT= false;
				}
				else if(GhiDSNV){
					OutFile_NhanVien(DSNV);
					GhiDSNV=false;
				}
				else if(GhiHD){
					GhiFile_HoaDon(DSNV);
					GhiHD=false;
				}
				break;
			}					
			case 31 : {
				DrawTableT_TLapHoaDon();
				strcpy(soHD,"");strcpy(maNV,"");strcpy(maVT,"");strcpy(SoLuong,"");strcpy(DonGia,"");strcpy(VAT,"");
				okSoHD=false; okMaNV = false; okMaVT=false; okSL = false; nhap = false; xuat = false; okTaoHoaDon = true;
				CTHDon.NumFact_CTHoaDon=0;
			}
			case 311 :{
				if (!okTaoHoaDon) break;
				DrawBar(300,130,445,150,LCyan);
				ScanMa(110+10,155+5,soHD,20,LCyan,311,Key);
				if (strlen(soHD)==0) {
					 WriteText(320,130,"  Trong!",Red,LCyan,1);
				}
				else if (TimKiem_SoHoaDon(DSNV,soHD)){
					DrawBar(300,130,445,150,LCyan);
					WriteText(305,130,"DaTonTai!",Red,LCyan,1);
				}
				else {
					DrawBar(300,130,445,150,LCyan);
					WriteText(320,130,"OK",Green,LCyan,1);
					okSoHD = true;
				}
				if (Key!=0) goto lable;
				else	break;
			}
			case 312 :{
				if (!okTaoHoaDon) break;
				DrawBar(525,130,695,150,LCyan);
				ScanMa(455+10,155+5,maNV,10,LCyan,311,Key);
				if (strlen(maNV)==0)  WriteText(550,130,"  Trong!",Red,LCyan,1);
				else if(TimKiem_MaNV(DSNV,maNV) != -1){
					DrawBar(525,130,695,150,LCyan);
					WriteText(550,130,"OK",Green,LCyan,1);
					okMaNV = true;
				}
				else{
					DrawBar(525,130,695,150,LCyan);
					WriteText(525,130,"KhongTonTai!",Red,LCyan,1);
				}
				if (Key!=0) goto lable;
				else	break;
			}
			case 313 :{
				DrawBar(400,84,822,107,LWhite);
				DrawBar(300,200,479,220,LCyan);
				ScanMa(225+10,225+5,maVT,10,LCyan,311,Key);
				if (strlen(maVT)==0){
					 WriteText(320,200,"  Trong!",Red,LCyan,1);
					 okMaVT = false;
				}
				else if (KTraMaVt_CTHD(CTHDon,maVT)){
						DrawBar(300,200,479,220,LCyan);
						WriteText(315,200,"Loi! VT DaCo",Red,LCyan,1);
						okMaVT = false;
					}
				else if (TimKiem_MaVT(Root,maVT) != NULL){
					DrawBar(300,200,479,220,LCyan);
					WriteText(320,200,"OK",Green,LCyan,1);
					okMaVT = true;
				} 
				else {
					DrawBar(300,200,479,220,LCyan);
					WriteText(302,200,"KhongTonTai",Red,LCyan,1);
					okMaVT=false;
				}
				if (Key!=0 && Key!=-3) goto lable;
				else if (Key!=-3) break;
			}
			case 314 :{
				DrawBar(580,200,695,220,LCyan);
				DrawBar(400,84,822,107,LWhite);
				if (!okMaVT || (!nhap && !xuat)){
					DrawBar(400,84,822,107,LWhite);
					WriteText(400+5,85,"Nhap MaVT & LoaiHD (N/X) truoc!", Black,LRed,sizeChu);
					break;				
				}
				ScanSo(485+10,225+5,SoLuong,8,LCyan,311,Key);
				int intSL=CharToInt(SoLuong);
				if (strlen(SoLuong)==0) WriteText(580,200,"  Trong!",Red,LCyan,1);
				else if ((!nhap && xuat) && ( intSL> TimKiem_MaVT(Root,maVT)->VT.SLT)){
					WriteText(450+5,85,"So Luong Ton: ", Black,LRed,sizeChu);
					char charSLT[20]="";
					IntToChar(TimKiem_MaVT(Root,maVT)->VT.SLT,charSLT);
					WriteText(630+5,85,charSLT, Black,LRed,sizeChu);
					DrawBar(600,200,695,220,LCyan);
					WriteText(580,200,"Loi!",Red,LCyan,1);
					okSL=false;
				}
				else{
					DrawBar(600,200,695,220,LCyan);
					WriteText(580,200,"  OK",Green,LCyan,1);
					okSL= true;
				} 
				if (Key!=0 && Key!=-3) goto lable;
				else if (Key!=-3) break;
			}
			case 315 :{
				if (!okMaVT) break;
				DrawBar(830,200,945,220,LCyan);
				ScanSo(705+10,225+5,DonGia,9,LCyan,311,Key);
				if (strlen(DonGia)==0) WriteText(830,200,"  Trong!",Red,LCyan,1);
				else{
					DrawBar(830,200,945,220,LCyan);
					WriteText(830,200,"  OK",Green,LCyan,1);
				} 
				if (Key!=0 && Key!=-3) goto lable;
				else if (Key!=-3) break;
			}
			case 316 :{
				if (!okMaVT) break;
				DrawBar(1010,200,1100,220,LCyan);
				ScanSo(955+10,225+5,VAT,8,LCyan,311,Key);
				if (strlen(VAT)==0) WriteText(1020,200,"Trong!",Red,LCyan,1);
				else{
					DrawBar(1030,200,1100,220,LCyan);
					WriteText(1030,200,"  OK",Green,LCyan,1);
				} 
				if (Key!=0) goto lable;
				else	break;
			}
			case 317 :{
					if (!okTaoHoaDon) break;
					DrawBar(400,84,822,107,LWhite);
					nhap = true;
					xuat  = false;
					DrawBar(20,205,120,265,LRed);
					DrawBar(120,205,215,265,LCyan);
					DrawRecTangle(20,205,120,265,Black,1);
					WriteText(25+40,205+20,"N",Black,LRed,sizeChu);
					DrawRecTangle(120,205,215,265,Black,1);
					WriteText(125+40,205+20,"X",Black,LCyan,sizeChu);
					
				break;
			}
			case 318: {
					if (!okTaoHoaDon) break;
					DrawBar(400,84,822,107,LWhite);
					nhap = false;
					xuat  = true;	
					DrawBar(20,205,120,265,LCyan);
					DrawBar(120,205,215,265,LRed);
					DrawRecTangle(20,205,120,265,Black,1);
					WriteText(25+40,205+20,"N",Black,LCyan,sizeChu);
					DrawRecTangle(120,205,215,265,Black,1);
					WriteText(125+40,205+20,"X",Black,LRed,sizeChu);	
				break;
			}
			case 319 :{ // nut them
				DrawBar(400,84,822,107,LWhite);
				if ( okSoHD && okMaNV && okMaVT &&  okSL && strlen(DonGia)!=0 && strlen(VAT) != 0 && (nhap || xuat)){				
					int intSL = CharToInt(SoLuong);
					int intDG = CharToInt(DonGia);
					int intVAT = CharToInt(VAT);	
					if (CTHDon.NumFact_CTHoaDon > 19 ) {
						DrawBar(400,84,822,107,LWhite);
						WriteText(450+5,85,"Hoa Don Day !", Black,LWhite,sizeChu);
					}
					else {
						Add_MotChiTietHoaDon(CTHDon,maVT,intSL,intDG,intVAT);
						WriteText(450+5,85,"Them Thanh Cong", Black,LGreen,sizeChu);
						int y1= 292;
						TongHD=0;
							for (int i=0; i<CTHDon.NumFact_CTHoaDon;i++){
								IntToChar(CTHDon.CTHoaDon[i].SoLuong,SoLuong);
								IntToChar(CTHDon.CTHoaDon[i].DonGia,DonGia);
								IntToChar(CTHDon.CTHoaDon[i].VAT,VAT);
								
								WriteText(20+5,y1,CTHDon.CTHoaDon[i].MaVT,Black,LWhite,1);
								WriteText(150+5,y1,TimKiem_MaVT(Root,CTHDon.CTHoaDon[i].MaVT)->VT.TENVT,Black,LWhite,1);
								WriteText(450+5,y1,TimKiem_MaVT(Root,CTHDon.CTHoaDon[i].MaVT)->VT.DVT,Black,LWhite,1);
								WriteText(590+5,y1,SoLuong,Black,LWhite,1);
								WriteText(720+5,y1,DonGia,Black,LWhite,1);
								WriteText(900+5,y1,VAT,Black,LWhite,1);
								long long 	num = (long long)CTHDon.CTHoaDon[i].SoLuong * (long long)CTHDon.CTHoaDon[i].DonGia +(long long)CTHDon.CTHoaDon[i].SoLuong* (long long)CTHDon.CTHoaDon[i].DonGia*(long long)CTHDon.CTHoaDon[i].VAT/100;								
								TongHD+= num;								
								DrawBar(950,84,MAX_X-20,107,LWhite);
								WriteText(950+5,85,Long_to_Char(TongHD), Black,LWhite,sizeChu);
								WriteText(970+5, y1,Long_to_Char(num),Black,LWhite,1);
								// nut X
								WriteText(MAX_X-45,y1,"X", Black,LRed,sizeChu);
								DrawRecTangle(MAX_X-45,y1,MAX_X-25,y1+19,Black,2);
								TaoID(MAX_X-45,y1,MAX_X-25,y1+19,1000 + i);
								y1+=20;
							}
						delay(1000);
						DrawBar(400,84,822,107,LWhite);
						}
				
					strcpy(maVT,""); strcpy(SoLuong,""); strcpy(DonGia,"");strcpy(VAT,"");
					// Ve lai o nhap
					DrawBar(225,225,475,260,LCyan);
					DrawBar(485,225,695,260,LCyan);
					DrawBar(705,225,945,260,LCyan);
					DrawBar(955,225,1050,260,LCyan);
					
					DrawRecTangle(225,225,475,260,Black,1);
					DrawRecTangle(485,225,695,260,Black,1);
					DrawRecTangle(705,225,945,260,Black,1);
					DrawRecTangle(955,225,1095,260,Black,1);
					// xoa OK
					DrawBar(1010,200,1100,220,LCyan);
					DrawBar(830,200,945,220,LCyan);
					DrawBar(300,200,465,220,LCyan);
					DrawBar(580,200,695,220,LCyan);
				}
				else {
					DrawBar(400,84,822,107,LWhite);
					WriteText(450+5,85,"Chua Dien Day Du Thong Tin", Black,LRed,sizeChu);
					delay(1000);
					DrawBar(400,84,822,107,LWhite);
				}
			break;
			}
			case 1000:
			case 1001:
			case 1002:
			case 1003:
			case 1004:
			case 1005:
			case 1006:
			case 1007:
			case 1008:
			case 1009:
			case 1010:
			case 1011:
			case 1012:
			case 1013:
			case 1014:
			case 1015:
			case 1016:
			case 1017:
			case 1018:
			case 1019:{
				if (Key%1000 >= CTHDon.NumFact_CTHoaDon) break;
				Delete_MotVatTu(CTHDon,Key % 1000);
				DrawTableT_TChiTiet();
				TongHD=0;
				int y1= 292;
				char SoLuong1[50]="";
				char DonGia1[50]="";
				char VAT1[10]="";
				
				for (int i=0; i<CTHDon.NumFact_CTHoaDon;i++){
					IntToChar(CTHDon.CTHoaDon[i].SoLuong,SoLuong1);
					IntToChar(CTHDon.CTHoaDon[i].DonGia,DonGia1);
					IntToChar(CTHDon.CTHoaDon[i].VAT,VAT1);
					
					WriteText(20+5, y1,CTHDon.CTHoaDon[i].MaVT,Black,LWhite,1);
					WriteText(150+5, y1,TimKiem_MaVT(Root,CTHDon.CTHoaDon[i].MaVT)->VT.TENVT,Black,LWhite,1);
					WriteText(450+5, y1,TimKiem_MaVT(Root,CTHDon.CTHoaDon[i].MaVT)->VT.DVT,Black,LWhite,1);
					WriteText(590+5, y1,SoLuong1,Black,LWhite,1);
					WriteText(720+5, y1,DonGia1,Black,LWhite,1);
					WriteText(900+5, y1,VAT1,Black,LWhite,1);					
					long long 	num = (long long)CTHDon.CTHoaDon[i].SoLuong * (long long)CTHDon.CTHoaDon[i].DonGia +(long long)CTHDon.CTHoaDon[i].SoLuong* (long long)CTHDon.CTHoaDon[i].DonGia*(long long)CTHDon.CTHoaDon[i].VAT/100;								
					TongHD+= num;
				
					WriteText(970+5, y1,Long_to_Char(num),Black,LWhite,1);
					// nut X
					WriteText(MAX_X-45,y1,"X", Black,LRed,sizeChu);
					DrawRecTangle(MAX_X-45,y1,MAX_X-25,y1+19,Black,2);
					TaoID(MAX_X-45,y1,MAX_X-25,y1+19,1000 + i);
					y1+=20;
					}
					DrawBar(950,84,MAX_X-20,107,LWhite);
					WriteText(950+5,85,Long_to_Char(TongHD), Black,LWhite,sizeChu);
					
				break;
			}
			case 3110 : {
				if (CTHDon.NumFact_CTHoaDon == 0) {
					DrawBar(400,84,822,107,LWhite);
					WriteText(450+5,85,"Hoa Don Rong !", Black,LRed,sizeChu);
					delay(2000);
					DrawBar(400,84,822,107,LWhite);
					break;
				}
				char Loai;
				int locaNV = TimKiem_MaNV(DSNV,maNV);
				if (nhap && !xuat) Loai ='N';
				else Loai = 'X';
				okTaoHoaDon= true;
				PTR_VT NodeTam ;
				HoaDon HD = taoHoaDonmoi(soHD,ngay,thang,nam,Loai);
				for (int i=0; i< CTHDon.NumFact_CTHoaDon ; i++){
					HD.CTHD->CTHoaDon[i] = CTHDon.CTHoaDon[i];
					NodeTam = TimKiem_MaVT(Root, HD.CTHD->CTHoaDon[i].MaVT);
					if (Loai == 'N') NodeTam->VT.SLT += HD.CTHD->CTHoaDon[i].SoLuong;
					else NodeTam->VT.SLT -= HD.CTHD->CTHoaDon[i].SoLuong;
				}		
				HD.CTHD->NumFact_CTHoaDon = CTHDon.NumFact_CTHoaDon;
				HD.trigia = TongHD;
				TongHD=0;
				ChenDau_MotHoaDon(*DSNV.DanhSachNhanVien[locaNV],&HD);
				n_HoaDon++;
				CTHDon.NumFact_CTHoaDon=0;	
				strcpy(soHD,"");strcpy(maNV,"");strcpy(maVT,"");strcpy(SoLuong,"");strcpy(DonGia,"");strcpy(VAT,"");
				okSoHD=false; okMaNV = false; okMaVT=false; okSL = false; okTaoHoaDon = true; nhap = false; xuat = false;
				DrawBar(400,84,822,107,LWhite);
				WriteText(450+5,85,"Lap Hoa Don Thanh Cong", Black,LGreen,sizeChu);
				GhiHD = true;
				delay(2000);
				DrawTableT_TLapHoaDon();
				break;
			}
			case 32 : {
				DrawTableT_TSoHD();
				break;
			}
			case 321 :{
				DrawBar(800+5,290,960,330,LWhite);
				ScanMa(500+10,300+5,soHD,10,LWhite,121,Key);
				if (strlen(soHD)==0){
					BaoTrong(800,290);
				}
				if (Key!=0) goto lable;
				else	break;							
			}
			case 322:{
					if (strlen(soHD)==0){
						BaoTrong(800,290);
						break;
					}
					if (TimKiem_NodeHoaDon (DSNV,soHD) == NULL){
						WriteText(450,465,"Sô hóa don không tôn tai", Red,LWhite,sizeChu);
						delay(1000);
						DrawBar(500+1,300+1,800-1,330-1,LWhite);
						DrawBar(440,464,951,485,LWhite);
					}
					else {
						DrawTableT_TInHD();
						Node_DSHoaDon* NodeTam = TimKiem_NodeHoaDon(DSNV,soHD);
						int locaNV_SHD = TimKiem_NhanVien_SoHD(DSNV,soHD);
						char ngay11[10]="";
						char thang11[10]="";
						char nam11[10]="";
						// thong tin hoa don
						IntToChar(NodeTam->HDon.NgayLap.ngay,ngay11);
						IntToChar(NodeTam->HDon.NgayLap.thang,thang11);
						IntToChar(NodeTam->HDon.NgayLap.nam,nam11);
						//
						WriteText(400+10,130+10,soHD,Black,LCyan,1);
						WriteText(780+3,130+10,ngay11,Black,LCyan,1);
						WriteText(910+3,130+10,thang11,Black,LCyan,1);
						WriteText(1010+3,130+10,nam11,Black,LCyan,1);
						//
						WriteText(400+10,180+10,DSNV.DanhSachNhanVien[locaNV_SHD]->MaNV,Black,LCyan,1);
						WriteText(600+10,180+10,DSNV.DanhSachNhanVien[locaNV_SHD]->Ho,Black,LCyan,1);
						WriteText(1030+10,180+10,DSNV.DanhSachNhanVien[locaNV_SHD]->Ten,Black,LCyan,1);
						//
						if (NodeTam->HDon.Loai =='N'){
							DrawBar(1105,125,1167,175,LRed);
							DrawRecTangle(1105,125,1167,175,Black,1);
							WriteText(1105+20,125+20,"N",Black,LRed,sizeChu);
							DrawRecTangle(1167,125,1235,175,Black,1);
							WriteText(1167+20,125+20,"X",Black,LCyan,sizeChu);
						}else {		
							DrawRecTangle(1105,125,1167,175,Black,1);
							WriteText(1105+20,125+20,"N",Black,LCyan,sizeChu);
							DrawBar(1167,125,1235,175,LRed);
							DrawRecTangle(1167,125,1235,175,Black,1);
							WriteText(1167+20,125+20,"X",Black,LRed,sizeChu);
						}
						// chi tiet hoa don
						TongHD=0;
						int y1=260;
						for (int i=0; i<NodeTam->HDon.CTHD->NumFact_CTHoaDon;i++){
							IntToChar(NodeTam->HDon.CTHD->CTHoaDon[i].SoLuong,SoLuong);
							IntToChar(NodeTam->HDon.CTHD->CTHoaDon[i].DonGia,DonGia);
							IntToChar(NodeTam->HDon.CTHD->CTHoaDon[i].VAT,VAT);				
							WriteText(20+7, y1+2,NodeTam->HDon.CTHD->CTHoaDon[i].MaVT,Black,LWhite,1);
							WriteText(400+7, y1+2,SoLuong,Black,LWhite,1);
							WriteText(700+7, y1+2,DonGia,Black,LWhite,1);
							WriteText(900+7, y1+2,VAT,Black,LWhite,1);
							long long num = (long long)NodeTam->HDon.CTHD->CTHoaDon[i].SoLuong * (long long)NodeTam->HDon.CTHD->CTHoaDon[i].DonGia + (long long)NodeTam->HDon.CTHD->CTHoaDon[i].SoLuong * (long long)NodeTam->HDon.CTHD->CTHoaDon[i].DonGia * (long long)NodeTam->HDon.CTHD->CTHoaDon[i].VAT/100;
							WriteText(1000+7, y1+2,Long_to_Char(num),Black,LWhite,1);
							TongHD+=num;
							y1+=20;
						}
						DrawRecTangle(20,230,400,y1,Black,1);
						DrawRecTangle(400,230,700,y1,Black,1);
						DrawRecTangle(700,230,900,y1,Black,1);
						DrawRecTangle(900,230,1000,y1,Black,1);
						DrawRecTangle(1000,230,MAX_X-15,y1,Black,1);
						
						DrawBar(20,y1,MAX_X-15,y1+25,LCyan);
						DrawRecTangle(20,y1,MAX_X-15,y1+25,Black,1);
	
						WriteText(750+7,y1+2,"Tong tien hoa don", Black,LCyan,sizeChu);
						WriteText(1000+7,y1+2,Long_to_Char(TongHD), Black,LCyan,sizeChu);	
						line(1000,y1,1000,y1+25);
						
						strcpy(soHD,""); strcpy(maNV,"");strcpy(maVT,"");strcpy(SoLuong,"");strcpy(DonGia,"");strcpy(VAT,"");
					}
				strcpy(soHD,"");	
				break;
			}
			case 4 :{
				 DrawTableTke();
				if (GhiDSVT){
					OutFile_VatTu(Root);
					GhiDSVT= false;
				}
				else if(GhiDSNV){
					OutFile_NhanVien(DSNV);
					GhiDSNV=false;
				}
				else if(GhiHD){
					GhiFile_HoaDon(DSNV);
					GhiHD=false;
				}
				break;
			}				
			case 41 : {
				DrawTableTke_Tim();
				strcpy(ngay1,"");strcpy(thang1,"");strcpy(nam1,"");strcpy(ngay2,"");strcpy(thang2,"");strcpy(nam2,"");
			}
			case 411:{
				DrawBar(350,470,950,497,LWhite);
				ScanSo(350+40,250,ngay1,2,LWhite,411,Key);
				if (strlen(ngay1) == 0) {
					DrawBar(350,280,490,310,LWhite);
					WriteText(350+10,280+3,"Trong!",Red,LWhite,sizeChu);
				}
				else{
					intNgay1 = CharToInt(ngay1);
					if (intNgay1 <1 || intNgay1>31) {
						okNgay1 = false;
						okThang1= false;
						okNam1 = false;
						DrawBar(350,280,490,310,LWhite);
						WriteText(350+10,280+3,"Loi!",Red,LWhite,sizeChu);
						DrawBar(350,470,950,497,LWhite);
						WriteText(501,475,"Ngày không hop lê !",Red,LWhite,sizeChu);
					}
					else {
						okNgay1 = true;
						DrawBar(350,280,490,310,LWhite);
						WriteText(350+10,280+3,"OK",Green,LWhite,sizeChu);
					}
				}
				if (Key!=0 && Key!=-3) goto lable;
				else if (Key!=-3) break;
			}
			case 412:{
				if (!okNgay1) break; 
				DrawBar(350,470,950,497,LWhite);
				ScanSo(610+40,250,thang1,2,LWhite,412,Key);	
				if (strlen(thang1) == 0) {
					DrawBar(350,280,490,310,LWhite);
					WriteText(610+10,280+3,"Trong!",Red,LWhite,sizeChu);
				}
				else {
					intThang1 = CharToInt(thang1);
					if ((intNgay1 == 31 &&  (intThang1==2 || intThang1==4||intThang1==6||intThang1==9||intThang1==11 )) || intThang1<1 || intThang1 >12 || (intNgay1 == 30 && intThang1 == 2)){
						okThang1 = false;
						okNam1 = false;
						DrawBar(610,280,730,310,LWhite);
						WriteText(610+10,280+3,"Loi!",Red,LWhite,sizeChu);
						
						DrawBar(350,470,950,497,LWhite);
						WriteText(501,475,"Tháng không hop lê !",Red,LWhite,sizeChu);
					}else {
						okThang1 = true;
						DrawBar(610,280,730,310,LWhite);
						WriteText(610+10,280+3,"OK",Green,LWhite,sizeChu);						
					}
				}
				if (Key!=0 && Key!=-3) goto lable;
				else if (Key!=-3) break;
			}
			case 413:{
				if (!okThang1) break; 
				DrawBar(350,470,950,497,LWhite);
				ScanSo(830+20,250,nam1,4,LWhite,413,Key);
				if (strlen(nam1) == 0) {
					DrawBar(830,280,950,310,LWhite);
					WriteText(830+10,280+3,"Trong!",Red,LWhite,sizeChu);
				}else {
					intNam1 = CharToInt(nam1);
					if ((intNgay1==29 && intThang1==2 && !NamNhuan(intNam1)) || intNam1 < 2000){
						okNam1 = false;
						
						DrawBar(830,280,950,310,LWhite);
						WriteText(830+10,280+3,"Loi!",Red,LWhite,sizeChu);

						DrawBar(350,470,950,497,LWhite);
						WriteText(501,475,"Nam không hop lê !",Red,LWhite,sizeChu);
					}
					else {
						okNam1 = true;
						DrawBar(830,280,950,310,LWhite);
						WriteText(830+10,280+3,"OK",Green,LWhite,sizeChu);
					}
				}	
				if (Key!=0 && Key!=-3) goto lable;
				else if (Key!=-3) break;
			}
			case 414:{
				DrawBar(350,470,950,497,LWhite);
				ScanSo(350+40,360,ngay2,2,LWhite,412,Key);
				if (strlen(ngay2) == 0) {
					DrawBar(350,390,490,420,LWhite);
					WriteText(350+10,390+3,"Trong!",Red,LWhite,sizeChu);
				}
				else{
					intNgay2 = CharToInt(ngay2);
					if (intNgay2 <1 || intNgay2>31) {
						okNgay2 = false;
						okThang2 = false;
						okNam2 = false;
						DrawBar(350,390,490,420,LWhite);
						WriteText(350+10,390+3,"Loi!",Red,LWhite,sizeChu);
						
						DrawBar(350,470,950,497,LWhite);
						WriteText(501,475,"Ngày không hop lê !",Red,LWhite,sizeChu);
					}
					else {
						okNgay2 = true;
						DrawBar(350,390,490,420,LWhite);
						WriteText(350+10,390+3,"OK",Green,LWhite,sizeChu);
					}
				}
				
				if (Key!=0 && Key!=-3) goto lable;
				else if (Key!=-3) break;
			}
			case 415:{
				if (!okNgay2) break; 
				DrawBar(350,470,950,497,LWhite);
				ScanSo(610+40,360,thang2,2,LWhite,412,Key);	
				if (strlen(thang2) == 0) {
					DrawBar(350,390,490,420,LWhite);
					WriteText(610+10,390+3,"Trong!",Red,LWhite,sizeChu);
				}
				else {
					intThang2 = CharToInt(thang2);
					if ((intNgay2 == 31 &&  (intThang2==2 || intThang2==4||intThang2==6||intThang2==9||intThang2==11 )) || intThang2<1 || intThang2 >12 || (intNgay2 == 30 && intThang2 == 2)){
						okThang2 = false;
						okNam2 = false;
						DrawBar(610,390,730,420,LWhite);
						WriteText(610+10,390+3,"Loi!",Red,LWhite,sizeChu);
						
						DrawBar(350,470,950,497,LWhite);
						WriteText(501,475,"Tháng không hop lê !",Red,LWhite,sizeChu);
					}else {
						okThang2 = true;
						DrawBar(610,390,730,420,LWhite);
						WriteText(610+10,390+3,"OK",Green,LWhite,sizeChu);						
					}
				}
				if (Key!=0 && Key!=-3) goto lable;
				else if (Key!=-3) break;
			}
			case 416:{
				if (!okThang2 ) break; 
				DrawBar(350,470,950,497,LWhite);
				ScanSo(830+20,360,nam2,4,LWhite,413,Key);
				if (strlen(nam2) == 0) {
					DrawBar(830,390,950,420,LWhite);
					WriteText(830+10,390+3,"Trong!",Red,LWhite,sizeChu);
				}else {
					intNam2 = CharToInt(nam2);
					if ((intNgay2==29 && intThang2==2 && !NamNhuan(intNam2)) || intNam2 < 2000){
						okNam2 = false;
						DrawBar(830,390,950,420,LWhite);
						WriteText(830+10,390+3,"Loi!",Red,LWhite,sizeChu);
						
						DrawBar(350,470,950,497,LWhite);
						WriteText(501,475,"Nam không hop lê !",Red,LWhite,sizeChu);
					}
					else {
						okNam2 = true;
						DrawBar(830,390,950,420,LWhite);
						WriteText(830+10,390+3,"OK",Green,LWhite,sizeChu);
					}
				}	
				if (Key!=0) goto lable;
				else	break;
			}
			case 417:{
				TODAY(ngay,thang,nam);
				DrawBar(350,470,950,497,LWhite);
				if (!okNam1 || !okNam2) {
					DrawBar(350,470,950,497,LWhite);
					WriteText(451,475,"Chua dien day du thong tin!",Red,LWhite,sizeChu);
					break;
				}
				if (SoSanhDMY(intNgay1,intThang1,intNam1,intNgay2,intThang2,intNam2) && SoSanhDMY(intNgay2,intThang2,intNam2,CharToInt(ngay),CharToInt(thang),CharToInt(nam))){
					// ve bang thong ke
					DrawTableTke_LietKe();
					WriteText(250+5,180,ngay1,Black,LCyan,sizeChu);
					WriteText(400+5,180,thang1,Black,LCyan,sizeChu);
					WriteText(520+5,180,nam1,Black,LCyan,sizeChu);
					WriteText(750+5,180,ngay2,Black,LCyan,sizeChu);
					WriteText(900+5,180,thang2,Black,LCyan,sizeChu);
					WriteText(1020+5,180,nam2,Black,LCyan,sizeChu);
					///////////////////////////////////////////////
				
					start.ngay = CharToInt(ngay1);
					start.thang = CharToInt(thang1);
					start.nam = CharToInt(nam1);
					finish.ngay = CharToInt(ngay2);
					finish.thang = CharToInt(thang2);
					finish.nam = CharToInt(nam2);
					int nHD=0;	HoaDon *arrHD=new HoaDon[n_HoaDon+2];
					string *arrHoTen =new string[n_HoaDon+2];
					for(int i=0; i < DSNV.NumFact_NV;++i){
						Node_DSHoaDon* Node_tmp=DSNV.DanhSachNhanVien[i]->First_DSHD;
						while (Node_tmp != NULL && (Node_tmp->HDon.NgayLap.nam>finish.nam || (Node_tmp->HDon.NgayLap.nam==finish.nam && Node_tmp->HDon.NgayLap.thang>finish.thang) || (Node_tmp->HDon.NgayLap.nam==finish.nam && Node_tmp->HDon.NgayLap.thang==finish.thang && Node_tmp->HDon.NgayLap.ngay>finish.ngay)))
							Node_tmp=Node_tmp->next;
						
						while (Node_tmp != NULL && (Node_tmp->HDon.NgayLap.nam>start.nam || (Node_tmp->HDon.NgayLap.nam==start.nam && Node_tmp->HDon.NgayLap.thang>start.thang) || (Node_tmp->HDon.NgayLap.nam==start.nam && Node_tmp->HDon.NgayLap.thang==start.thang && Node_tmp->HDon.NgayLap.ngay>=start.ngay)))
						{
							strcpy(arrHD[nHD].SoHD,Node_tmp->HDon.SoHD);
							arrHD[nHD].NgayLap=Node_tmp->HDon.NgayLap;
							arrHD[nHD].Loai=Node_tmp->HDon.Loai;
							arrHD[nHD].trigia=Node_tmp->HDon.trigia;
							arrHoTen[nHD]=string(DSNV.DanhSachNhanVien[i]->Ho) + " " + string(DSNV.DanhSachNhanVien[i]->Ten);
							nHD++;
							Node_tmp=Node_tmp->next;
						}
					}
					Sort_DanhSachHoaDon(arrHD,arrHoTen,0,nHD-1);///xong
					//xuat
					int y=255;
					TongTrang = nHD /17;
					if (nHD == 0) TongTrang +=1;
					if (nHD % 17 !=0) TongTrang+=1;
					IntToChar(TongTrang,charTrang);
					soTrang =1;
					WriteText(MAX_X - 135,185,"1",Red,LWhite,2);
					WriteText(MAX_X - 115,185,"/",Red,LWhite,2);
					WriteText(MAX_X - 100,185,charTrang,Red,LWhite,2);
					for (int i=0; i<17 && 17*(soTrang-1) +i < nHD; i++){
						char Loai[20]="";
						if (arrHD[i].Loai =='N') strcpy(Loai,"N");
						else strcpy(Loai,"X");
						IntToChar(arrHD[i].NgayLap.ngay,ngay);
						IntToChar(arrHD[i].NgayLap.thang,thang);
						IntToChar(arrHD[i].NgayLap.nam,nam);
						
						WriteText(25+10,y,arrHD[i].SoHD,Black,LWhite,sizeChu);
						string tmp = string(ngay)+"/"+string(thang)+"/"+string(nam);
						WriteText(290,y,(char*) tmp.c_str(),Black,LWhite,sizeChu);
						WriteText(460+30,y,Loai,Black,LWhite,sizeChu);
						WriteText(530+10,y,(char*) arrHoTen[i].c_str(),Black,LWhite,sizeChu);
						WriteText(1000+10,y,Long_to_Char(arrHD[i].trigia),Black,LWhite,sizeChu); // sau nay sua
						y+=25;
					}
					DrawRecTangle(20,220,280,y,Black,1);
					DrawRecTangle(280,220,460,y,Black,1);
					DrawRecTangle(460,220,530,y,Black,1);
					DrawRecTangle(530,220,1000,y,Black,1);
					DrawRecTangle(1000,220,MAX_X-15,y,Black,1);
					delete []arrHoTen;
					delete []arrHD;
					strcpy(ngay1,"");strcpy(thang1,"");strcpy(nam1,"");strcpy(ngay2,"");strcpy(thang2,"");strcpy(nam2,"");
					okNgay1=false,okThang1=false,okNam1=false,okNgay2=false,okThang2=false,okNam2=false;
				//////////////////////----------------------------------------/////////////////////
				}else{
					if (!SoSanhDMY(intNgay1,intThang1,intNam1,intNgay2,intThang2,intNam2)){
						DrawBar(350,470,950,497,LWhite);
						WriteText(451,475,"Ngay/Thang/Nam BEGIN > END",Red,LWhite,sizeChu);
					}
					else if (!SoSanhDMY(intNgay2,intThang2,intNam2,CharToInt(ngay),CharToInt(thang),CharToInt(nam))){
						DrawBar(350,470,950,497,LWhite);
						WriteText(451,475,"Ngay/Thang/Nam END o tuong lai!",Red,LWhite,sizeChu);
					}
				}	
				break;
			}
			case 4171:{ // back
				if (soTrang-1 < 1 ) break;
				soTrang-=1;
				HoaDon *arrHD=new HoaDon[n_HoaDon+2];
				int nHD=0;
				string *arrHoTen =new string[n_HoaDon+2];
				for(int i=0; i < DSNV.NumFact_NV;++i){
					Node_DSHoaDon* Node_tmp=DSNV.DanhSachNhanVien[i]->First_DSHD;
					while (Node_tmp != NULL && (Node_tmp->HDon.NgayLap.nam>finish.nam || (Node_tmp->HDon.NgayLap.nam==finish.nam && Node_tmp->HDon.NgayLap.thang>finish.thang) || (Node_tmp->HDon.NgayLap.nam==finish.nam && Node_tmp->HDon.NgayLap.thang==finish.thang && Node_tmp->HDon.NgayLap.ngay>finish.ngay)))
						Node_tmp=Node_tmp->next;
					while (Node_tmp != NULL && (Node_tmp->HDon.NgayLap.nam>start.nam || (Node_tmp->HDon.NgayLap.nam==start.nam && Node_tmp->HDon.NgayLap.thang>start.thang) || (Node_tmp->HDon.NgayLap.nam==start.nam && Node_tmp->HDon.NgayLap.thang==start.thang && Node_tmp->HDon.NgayLap.ngay>=start.ngay)))
					{
						strcpy(arrHD[nHD].SoHD,Node_tmp->HDon.SoHD);
							arrHD[nHD].NgayLap=Node_tmp->HDon.NgayLap;
							arrHD[nHD].Loai=Node_tmp->HDon.Loai;
							arrHD[nHD].trigia=Node_tmp->HDon.trigia;
						arrHoTen[nHD]=string(DSNV.DanhSachNhanVien[i]->Ho) + " " + string(DSNV.DanhSachNhanVien[i]->Ten);
						nHD++;
						Node_tmp=Node_tmp->next;
					}
				}
				Sort_DanhSachHoaDon(arrHD,arrHoTen,0,nHD-1);///xong
				// ve lai bang 
				DrawBar(19,219,MAX_X-14,MAX_Y-15,LWhite);
				int y1=220;
				DrawBar(20,220,MAX_X-15,250,LCyan);
				WriteText(20+95,y1+5,"SoHD", Black,LCyan,sizeChu);
				WriteText(280+25,y1+5,"Ngay Lap", Black,LCyan,sizeChu);	
				WriteText(460+5,y1+5,"Loai", Black,LCyan,sizeChu);		
				WriteText(530+105,y1+5,"Ho Ten NV Lap", Black,LCyan,sizeChu);
				WriteText(1000+15,y1+5,"Tri Gia Hoa Don", Black,LCyan,sizeChu);
				line(20,y1+30,MAX_X-15,y1+30);	
				//xuat
				
				int y=255;
				TongTrang = nHD / 17;
				if (nHD == 0) TongTrang +=1;
				if (nHD % 17 !=0) TongTrang+=1;
				IntToChar(TongTrang,charTrang);
				IntToChar(soTrang,charSoTrang);
				WriteText(MAX_X - 135,185,charSoTrang,Red,LWhite,1);
				WriteText(MAX_X - 115,185,"/",Red,LWhite,1);
				WriteText(MAX_X - 100,185,charTrang,Red,LWhite,1);
				for (int i=0; i<17 && 17*(soTrang -1)+i < nHD; i++){
					char Loai[20]="";
					if (arrHD[17*(soTrang -1)+i].Loai =='N') strcpy(Loai,"N");
					else strcpy(Loai,"X");
					IntToChar(arrHD[17*(soTrang -1)+i].NgayLap.ngay,ngay);
					IntToChar(arrHD[17*(soTrang -1)+i].NgayLap.thang,thang);
					IntToChar(arrHD[17*(soTrang -1)+i].NgayLap.nam,nam);
					WriteText(25+10,y,arrHD[17*(soTrang -1)+i].SoHD,Black,LWhite,sizeChu);
					string tmp = string(ngay)+"/"+string(thang)+"/"+string(nam);
					WriteText(290,y,(char*) tmp.c_str(),Black,LWhite,sizeChu);
					WriteText(460+30,y,Loai,Black,LWhite,sizeChu);
					WriteText(530+10,y,(char*) arrHoTen[17*(soTrang -1)+i].c_str(),Black,LWhite,sizeChu);
					WriteText(1000+10,y,Long_to_Char(arrHD[17*(soTrang -1)+i].trigia),Black,LWhite,sizeChu); // sau nay sua
					y+=25;
				}
				DrawRecTangle(20,220,280,y,Black,1);
				DrawRecTangle(280,220,460,y,Black,1);
				DrawRecTangle(460,220,530,y,Black,1);
				DrawRecTangle(530,220,1000,y,Black,1);
				DrawRecTangle(1000,220,MAX_X-15,y,Black,1);
				delete []arrHoTen;
				delete []arrHD;
				strcpy(ngay1,"");strcpy(thang1,"");strcpy(nam1,"");strcpy(ngay2,"");strcpy(thang2,"");strcpy(nam2,"");
				okNgay1=false,okThang1=false,okNam1=false,okNgay2=false,okThang2=false,okNam2=false;
				break;
			}
			case 4172:{ // next
				if (soTrang+1 > TongTrang) break;
				soTrang+=1;
				HoaDon *arrHD=new HoaDon[n_HoaDon+2];
				int nHD=0;
				string *arrHoTen =new string[n_HoaDon+2];
				for(int i=0; i < DSNV.NumFact_NV;++i){
					Node_DSHoaDon* Node_tmp=DSNV.DanhSachNhanVien[i]->First_DSHD;
					while (Node_tmp != NULL && (Node_tmp->HDon.NgayLap.nam>finish.nam || (Node_tmp->HDon.NgayLap.nam==finish.nam && Node_tmp->HDon.NgayLap.thang>finish.thang) || (Node_tmp->HDon.NgayLap.nam==finish.nam && Node_tmp->HDon.NgayLap.thang==finish.thang && Node_tmp->HDon.NgayLap.ngay>finish.ngay)))
						Node_tmp=Node_tmp->next;
					while (Node_tmp != NULL && (Node_tmp->HDon.NgayLap.nam>start.nam || (Node_tmp->HDon.NgayLap.nam==start.nam && Node_tmp->HDon.NgayLap.thang>start.thang) || (Node_tmp->HDon.NgayLap.nam==start.nam && Node_tmp->HDon.NgayLap.thang==start.thang && Node_tmp->HDon.NgayLap.ngay>=start.ngay)))
					{
					strcpy(arrHD[nHD].SoHD,Node_tmp->HDon.SoHD);
							arrHD[nHD].NgayLap=Node_tmp->HDon.NgayLap;
							arrHD[nHD].Loai=Node_tmp->HDon.Loai;
							arrHD[nHD].trigia=Node_tmp->HDon.trigia;
						arrHoTen[nHD]=string(DSNV.DanhSachNhanVien[i]->Ho) + " " + string(DSNV.DanhSachNhanVien[i]->Ten);
						nHD++;
						Node_tmp=Node_tmp->next;
					}
				}
				Sort_DanhSachHoaDon(arrHD,arrHoTen,0,nHD-1);///xong
				// ve lai bang 
				DrawBar(19,219,MAX_X-14,MAX_Y-15,LWhite);
				int y1=220;
				DrawBar(20,220,MAX_X-15,250,LCyan);
				WriteText(20+95,y1+5,"SoHD", Black,LCyan,sizeChu);
				WriteText(280+25,y1+5,"Ngay Lap", Black,LCyan,sizeChu);	
				WriteText(460+5,y1+5,"Loai", Black,LCyan,sizeChu);		
				WriteText(530+105,y1+5,"Ho Ten NV Lap", Black,LCyan,sizeChu);
				WriteText(1000+15,y1+5,"Tri Gia Hoa Don", Black,LCyan,sizeChu);
				line(20,y1+30,MAX_X-15,y1+30);	
				//xuat
				
				int y=255;
				TongTrang = nHD / 17;
				if (nHD == 0) TongTrang +=1;
				if (nHD % 17 !=0) TongTrang+=1;
				IntToChar(TongTrang,charTrang);
				IntToChar(soTrang,charSoTrang);
				WriteText(MAX_X - 135,185,charSoTrang,Red,LWhite,1);
				WriteText(MAX_X - 115,185,"/",Red,LWhite,1);
				WriteText(MAX_X - 100,185,charTrang,Red,LWhite,1);
				for (int i=0; i<17 && 17*(soTrang -1)+i < nHD; i++){
					char Loai[20]="";
					if (arrHD[17*(soTrang -1)+i].Loai =='N') strcpy(Loai,"N");
					else strcpy(Loai,"X");
					IntToChar(arrHD[17*(soTrang -1)+i].NgayLap.ngay,ngay);
					IntToChar(arrHD[17*(soTrang -1)+i].NgayLap.thang,thang);
					IntToChar(arrHD[17*(soTrang -1)+i].NgayLap.nam,nam);
					WriteText(25+10,y,arrHD[17*(soTrang -1)+i].SoHD,Black,LWhite,sizeChu);
					string tmp = string(ngay)+"/"+string(thang)+"/"+string(nam);
					WriteText(290,y,(char*) tmp.c_str(),Black,LWhite,sizeChu);
					WriteText(460+30,y,Loai,Black,LWhite,sizeChu);
					WriteText(530+10,y,(char*) arrHoTen[17*(soTrang -1)+i].c_str(),Black,LWhite,sizeChu);
					WriteText(1000+10,y,Long_to_Char(arrHD[17*(soTrang -1)+i].trigia),Black,LWhite,sizeChu); // sau nay sua
					y+=25;
				}
				DrawRecTangle(20,220,280,y,Black,1);
				DrawRecTangle(280,220,460,y,Black,1);
				DrawRecTangle(460,220,530,y,Black,1);
				DrawRecTangle(530,220,1000,y,Black,1);
				DrawRecTangle(1000,220,MAX_X-15,y,Black,1);
				delete []arrHoTen;
				delete []arrHD;
				strcpy(ngay1,"");strcpy(thang1,"");strcpy(nam1,"");strcpy(ngay2,"");strcpy(thang2,"");strcpy(nam2,"");
				okNgay1=false,okThang1=false,okNam1=false,okNgay2=false,okThang2=false,okNam2=false;
				break;
			}
			case 418 : { //today
					TODAY(ngay,thang,nam);
					strcpy(ngay2,ngay);strcpy(thang2,thang);strcpy(nam2,nam);
					intNgay2 = CharToInt(ngay2); 
					intThang2 = CharToInt(thang2);
					intNam2 = CharToInt(nam2);
					
					DrawBar(350+1,358,470-2,384,LWhite);
					WriteText(350+40,360,ngay2,Black,LWhite,sizeChu);
					DrawBar(350,390,490,420,LWhite);
					WriteText(350+10,390+3,"OK",Green,LWhite,sizeChu);
					
					DrawBar(610+1,358,730-1,384,LWhite);
					WriteText(610+40,360,thang2,Black,LWhite,sizeChu);
					DrawBar(610,390,730,420,LWhite);
					WriteText(610+10,390+3,"OK",Green,LWhite,sizeChu);	
					
					DrawBar(830+1,358,950-1,384,LWhite);
					WriteText(830+20,360,nam2,Black,LWhite,sizeChu);
					DrawBar(830,390,950,420,LWhite);
					WriteText(830+10,390+3,"OK",Green,LWhite,sizeChu);
					
					okNam2 = true;
				break;
			}
			case 42 : {
				DrawTableTke_Top10();
				strcpy(ngay1,"");strcpy(thang1,"");strcpy(nam1,"");strcpy(ngay2,"");strcpy(thang2,"");strcpy(nam2,"");
			}
			case 421:{
				DrawBar(350,470,950,497,LWhite);
				ScanSo(350+40,250,ngay1,2,LWhite,411,Key);
				if (strlen(ngay1) == 0) {
					DrawBar(350,280,490,310,LWhite);
					WriteText(350+10,280+3,"Trong!",Red,LWhite,sizeChu);
				}
				else{
					intNgay1 = CharToInt(ngay1);
					if (intNgay1 <1 || intNgay1>31) {
						okNgay1 = false;
						okThang1= false;
						okNam1 = false;
						DrawBar(350,280,490,310,LWhite);
						WriteText(350+10,280+3,"Loi!",Red,LWhite,sizeChu);
						
						DrawBar(350,470,950,497,LWhite);
						WriteText(500,475,"Ngày không hop lê !",Red,LWhite,sizeChu);
					}
					else {
						okNgay1 = true;
						DrawBar(350,280,490,310,LWhite);
						WriteText(350+10,280+3,"OK",Green,LWhite,sizeChu);
					}
				}
				if (Key!=0 && Key!=-3) goto lable;
				else if (Key!=-3) break;
			}
			case 422:{
				if (!okNgay1) break; 
				DrawBar(350,470,950,497,LWhite);
				ScanSo(610+40,250,thang1,2,LWhite,412,Key);	
				if (strlen(thang1) == 0) {
					DrawBar(350,280,490,310,LWhite);
					WriteText(610+10,280+3,"Trong!",Red,LWhite,sizeChu);
				}
				else {
					intThang1 = CharToInt(thang1);
					if ((intNgay1 == 31 &&  (intThang1==2 || intThang1==4||intThang1==6||intThang1==9||intThang1==11 )) || intThang1<1 || intThang1 >12 || (intNgay1 == 30 && intThang1 == 2)){
						okThang1 = false;
						okNam1 = false;
						DrawBar(610,280,730,310,LWhite);
						WriteText(610+10,280+3,"Loi!",Red,LWhite,sizeChu);
						
						DrawBar(350,470,950,497,LWhite);
						WriteText(500,475,"Tháng không hop lê !",Red,LWhite,sizeChu);
					}else {
						okThang1 = true;
						DrawBar(610,280,730,310,LWhite);
						WriteText(610+10,280+3,"OK",Green,LWhite,sizeChu);						
					}
				}
				if (Key!=0 && Key!=-3) goto lable;
				else if (Key!=-3) break;
			}
			case 423:{
				if (!okThang1) break; 
				DrawBar(350,470,950,497,LWhite);
				ScanSo(830+20,250,nam1,4,LWhite,413,Key);
				if (strlen(nam1) == 0) {
					DrawBar(830,280,950,310,LWhite);
					WriteText(830+10,280+3,"Trong!",Red,LWhite,sizeChu);
				}else {
					intNam1 = CharToInt(nam1);
					if ((intNgay1==29 && intThang1==2 && !NamNhuan(intNam1)) || intNam1 < 2000){
						okNam1 = false;
						
						DrawBar(830,280,950,310,LWhite);
						WriteText(830+10,280+3,"Loi!",Red,LWhite,sizeChu);

						DrawBar(350,470,950,497,LWhite);
						WriteText(500,475,"Nam không hop lê !",Red,LWhite,sizeChu);
					}
					else {
						okNam1 = true;
						DrawBar(830,280,950,310,LWhite);
						WriteText(830+10,280+3,"OK",Green,LWhite,sizeChu);
					}
				}	
				if (Key!=0 && Key!=-3) goto lable;
				else if (Key!=-3) break;
			}
			case 424:{
				DrawBar(350,470,950,497,LWhite);
				ScanSo(350+40,360,ngay2,2,LWhite,412,Key);
				if (strlen(ngay2) == 0) {
					DrawBar(350,390,490,420,LWhite);
					WriteText(350+10,390+3,"Trong!",Red,LWhite,sizeChu);
				}
				else{
					intNgay2 = CharToInt(ngay2);
					if (intNgay2 <1 || intNgay2>31) {
						okNgay2 = false;
						okThang2 = false;
						okNam2 = false;
						DrawBar(350,390,490,420,LWhite);
						WriteText(350+10,390+3,"Loi!",Red,LWhite,sizeChu);
						
						DrawBar(350,470,950,497,LWhite);
						WriteText(500,475,"Ngày không hop lê !",Red,LWhite,sizeChu);
					}
					else {
						okNgay2 = true;
						DrawBar(350,390,490,420,LWhite);
						WriteText(350+10,390+3,"OK",Green,LWhite,sizeChu);
					}
				}
				
				if (Key!=0 && Key!=-3) goto lable;
				else if (Key!=-3) break;
			}
			case 425:{
				if (!okNgay2) break; 
				DrawBar(350,470,950,497,LWhite);
				ScanSo(610+40,360,thang2,2,LWhite,412,Key);	
				if (strlen(thang2) == 0) {
					DrawBar(350,390,490,420,LWhite);
					WriteText(610+10,390+3,"Trong!",Red,LWhite,sizeChu);
				}
				else {
					intThang2 = CharToInt(thang2);
					if ((intNgay2 == 31 &&  (intThang2==2 || intThang2==4||intThang2==6||intThang2==9||intThang2==11 )) || intThang2<1 || intThang2 >12 || (intNgay2 == 30 && intThang2 == 2)){
						okThang2 = false;
						okNam2 = false;
						DrawBar(610,390,730,420,LWhite);
						WriteText(610+10,390+3,"Loi!",Red,LWhite,sizeChu);
						
						DrawBar(350,470,950,497,LWhite);
						WriteText(500,475,"Tháng không hop lê !",Red,LWhite,sizeChu);
					}else {
						okThang2 = true;
						DrawBar(610,390,730,420,LWhite);
						WriteText(610+10,390+3,"OK",Green,LWhite,sizeChu);						
					}
				}
				if (Key!=0 && Key!=-3) goto lable;
				else if (Key!=-3) break;
			}
			case 426:{
				if (!okThang2 ) break; 
				DrawBar(350,470,950,497,LWhite);
				ScanSo(830+20,360,nam2,4,LWhite,413,Key);
				if (strlen(nam2) == 0) {
					DrawBar(830,390,950,420,LWhite);
					WriteText(830+10,390+3,"Trong!",Red,LWhite,sizeChu);
				}else {
					intNam2 = CharToInt(nam2);
					if ((intNgay2==29 && intThang2==2 && !NamNhuan(intNam2)) || intNam2 < 2000){
						okNam2 = false;
						DrawBar(830,390,950,420,LWhite);
						WriteText(830+10,390+3,"Loi!",Red,LWhite,sizeChu);
						
						DrawBar(350,470,950,497,LWhite);
						WriteText(500,475,"Nam không hop lê !",Red,LWhite,sizeChu);
					}
					else {
						okNam2 = true;
						DrawBar(830,390,950,420,LWhite);
						WriteText(830+10,390+3,"OK",Green,LWhite,sizeChu);
					}
				}	
				if (Key!=0) goto lable;
				else	break;
			}
			case 427:{
				TODAY(ngay,thang,nam);
				DrawBar(350,470,950,497,LWhite);
				if (!okNam1 || !okNam2) {
					DrawBar(350,470,950,497,LWhite);
					WriteText(360,475,"Chua dien day du thong tin!",Red,LWhite,sizeChu);
					break;
				}
				if (SoSanhDMY(intNgay1,intThang1,intNam1,intNgay2,intThang2,intNam2) && SoSanhDMY(intNgay2,intThang2,intNam2,CharToInt(ngay),CharToInt(thang),CharToInt(nam))){
					DrawBar(350,470,950,497,LWhite);
					WriteText(360,475,"ok",Green,LWhite,sizeChu);
					delay(100);
					DrawTableTKe_BangTop10();
					//////////////////// OUTTEXT ////////// TOP 10 /////////
					start.ngay = CharToInt(ngay1);
					start.thang = CharToInt(thang1);
					start.nam = CharToInt(nam1);
					finish.ngay = CharToInt(ngay2);
					finish.thang = CharToInt(thang2);
					finish.nam = CharToInt(nam2);
					
					// thong ke top 10
					PTR_TK_TOP Top10 = NULL;
					int k=0;
					for(int i=0;i<DSNV.NumFact_NV;++i){
						Node_DSHoaDon* Node_tmp=DSNV.DanhSachNhanVien[i]->First_DSHD;
						while (Node_tmp != NULL && (Node_tmp->HDon.NgayLap.nam>finish.nam || (Node_tmp->HDon.NgayLap.nam==finish.nam && Node_tmp->HDon.NgayLap.thang>finish.thang) || (Node_tmp->HDon.NgayLap.nam==finish.nam && Node_tmp->HDon.NgayLap.thang==finish.thang && Node_tmp->HDon.NgayLap.ngay>finish.ngay)))

							Node_tmp=Node_tmp->next;
						while (Node_tmp != NULL && (Node_tmp->HDon.NgayLap.nam>start.nam || (Node_tmp->HDon.NgayLap.nam==start.nam && Node_tmp->HDon.NgayLap.thang>start.thang) || (Node_tmp->HDon.NgayLap.nam==start.nam && Node_tmp->HDon.NgayLap.thang==start.thang && Node_tmp->HDon.NgayLap.ngay>=start.ngay)))

						{
							if(Node_tmp->HDon.Loai=='X')
								for(int j=0;j<Node_tmp->HDon.CTHD->NumFact_CTHoaDon;++j)
								{	
									string tam=string(Node_tmp->HDon.CTHD->CTHoaDon[j].MaVT);
									long long Res=0;
									Res+= (long long)((long long)Node_tmp->HDon.CTHD->CTHoaDon[j].SoLuong * (long long)Node_tmp->HDon.CTHD->CTHoaDon[j].DonGia + (long long)Node_tmp->HDon.CTHD->CTHoaDon[j].SoLuong * (long long)Node_tmp->HDon.CTHD->CTHoaDon[j].DonGia * (long long)Node_tmp->HDon.CTHD->CTHoaDon[j].VAT/100);	
									PTR_VT Tmp = TimKiem_MaVT(Root,Node_tmp->HDon.CTHD->CTHoaDon[j].MaVT);
									if (Tmp == NULL){
										them_TK_TOP(Top10,tam,Res,NULL,k);
									}else {
										them_TK_TOP(Top10,tam,Res,Tmp,k);
									}
								}
							Node_tmp=Node_tmp->next;
								
						}
					}
					int num = 0;
					PTR_TK_TOP A[k+1];					
					LNR(Top10,A,num);
					Heap_Sort(A,num,10);
						
					int yy=245;
					for(int i=0; i<10 && i<num ;i++){	
						WriteText(155+10,yy,(char*) A[num-1-i]->data.c_str(),Black,LWhite,sizeChu);	
						if (A[num-1-i]->vattu == NULL){
							WriteText(390+10,yy,"VatTuDaXoa",Black,LWhite,sizeChu);
							WriteText(705+10,yy,"N/A",Black,LWhite,sizeChu);
						}
						else {
							WriteText(390+10,yy,A[num-1-i]->vattu->VT.TENVT,Black,LWhite,sizeChu);
							WriteText(705+10,yy,A[num-1-i]->vattu->VT.DVT,Black,LWhite,sizeChu);
						}	
						WriteText(905+10,yy,Long_to_Char(A[num-1-i]->tt),Black,LWhite,sizeChu);
						yy+=30;				
					}
					strcpy(ngay1,"");strcpy(thang1,"");strcpy(nam1,"");strcpy(ngay2,"");strcpy(thang2,"");strcpy(nam2,"");
					okNgay1=false,okThang1=false,okNam1=false,okNgay2=false,okThang2=false,okNam2=false;
					XoaHetCay_Top10(Top10);
				/////////////////////
				}else{
					if (!SoSanhDMY(intNgay1,intThang1,intNam1,intNgay2,intThang2,intNam2)){
						DrawBar(350,470,950,497,LWhite);
						WriteText(360,475,"Ngay/Thang/Nam BEGIN > END",Red,LWhite,sizeChu);
					}
					else if (!SoSanhDMY(intNgay2,intThang2,intNam2,CharToInt(ngay),CharToInt(thang),CharToInt(nam))){
						DrawBar(350,470,950,497,LWhite);
						WriteText(360,475,"Ngay/Thang/Nam END o tuong lai!",Red,LWhite,sizeChu);
					}
				}	
				break;
			}
			case 428 : { //today
					TODAY(ngay,thang,nam);
					strcpy(ngay2,ngay);strcpy(thang2,thang);strcpy(nam2,nam);
					intNgay2 = CharToInt(ngay2); 
					intThang2 = CharToInt(thang2);
					intNam2 = CharToInt(nam2);
					
					DrawBar(350+1,358,470-2,384,LWhite);
					WriteText(350+40,360,ngay2,Black,LWhite,sizeChu);
					DrawBar(350,390,490,420,LWhite);
					WriteText(350+10,390+3,"OK",Green,LWhite,sizeChu);
					
					DrawBar(610+1,358,730-1,384,LWhite);
					WriteText(610+40,360,thang2,Black,LWhite,sizeChu);
					DrawBar(610,390,730,420,LWhite);
					WriteText(610+10,390+3,"OK",Green,LWhite,sizeChu);	
					
					DrawBar(830+1,358,950-1,384,LWhite);
					WriteText(830+20,360,nam2,Black,LWhite,sizeChu);
					DrawBar(830,390,950,420,LWhite);
					WriteText(830+10,390+3,"OK",Green,LWhite,sizeChu);
					
					okNam2 = true;
				break;
			}
			case -1:{	
				OutFile_VatTu(Root);
				OutFile_NhanVien(DSNV);
				GhiFile_HoaDon(DSNV);
				for (int i=0; i< DSNV.NumFact_NV; i++){
					Node_DSHoaDon *first;
					Node_DSHoaDon *NodeChay = DSNV.DanhSachNhanVien[i]->First_DSHD;
					while (NodeChay !=NULL){
						first = NodeChay;
						NodeChay = NodeChay->next;
						delete first;
					}	
				}
				for(int i=0;i<DSNV.NumFact_NV;++i)
					delete DSNV.DanhSachNhanVien[i];
				XoaHetCay(Root);
				DrawBar(1,1,MAX_X,MAX_Y,LWhite);
				DrawBar(350,230,900,470,LRed);
				DrawRecTangle(350,230,900,470,Black,3);
				WriteText(350+130,230+80,"Luu Thanh Cong",Black,LRed,4);
				delay(500);
				WriteText(350+130,380,"Ket Thuc Chuong Trinh",Black,LRed,3);
				delay(1500);
				cout << "Clean Memory";
				exit(0);
				break;
			}
			default: break;
		}
	}	
}
void setMapID(){

	for (int i=0; i<=MAX_X; i++){
		for (int j=0; j<=MAX_Y; j++)
		Mapid[i][j]=0;
	}
}
void TaoID(int x1, int y1, int x2, int y2, int id){
	for (int i=x1; i<=x2; i++){
		for (int j=y1; j<=y2; j++)
		Mapid[i][j]=id;
	}
}
void CleanID(){
	TaoID(0,70,MAX_X,MAX_Y,0);
}
void CleanID2(){
	TaoID(15,115,MAX_X,MAX_Y,0);
}
int return_click_mouse(){
	int x,y;
	if (ismouseclick(WM_LBUTTONDOWN)){
		 getmouseclick(WM_LBUTTONDOWN, x, y);
		 return Mapid[x][y] ;
	}
}
int move_mouse(){
	int x,y;
	if (ismouseclick(WM_MOUSEMOVE)){
		 getmouseclick(WM_MOUSEMOVE, x, y);
		return Mapid[x][y];
	 }
}
void DrawBar(int x1, int y1, int x2, int y2, int maunen){
	setfillstyle(1,maunen);
	bar(x1,y1,x2,y2);
}
void WriteText(int x, int y, char text[],  int MauChu, int MauBK,int size){
	setcolor(MauChu);
	setbkcolor(MauBK);
	settextstyle(6,0,size);
	outtextxy(x,y,text);
}
void setKhung(){
	setfillstyle(1,15);
	bar(0,0,MAX_X,MAX_Y);
	setcolor(Black);
   	setlinestyle(1,1,4);
   	rectangle(2,2,MAX_X,MAX_Y);
}
void CleanBK(){
	DrawBar(14,74,MAX_X-9,MAX_Y-9,LWhite);
}
void DrawRecTangle(int x1, int y1, int x2, int y2,int mau, int size){
	setcolor(mau);
	setlinestyle(0,0,size);
	rectangle(x1,y1,x2,y2);
}
void ScanTen(int x, int y, char s[], int lenMax,int mauNen, int id,int &Key){   
	settextstyle(6,0,1);
	setcolor(0);
	setbkcolor(mauNen);
    int l=strlen(s);
    s[l+1]='\0';   s[l]='|';
    int x1,y1;
     while(1){
		outtextxy(x,y,s);
     	if(kbhit()){
	     	char c= getch();
	     	if ((int)c == 0){
	     		c = getch();
	     		continue;
			}
	     	if (l<lenMax){
	     		if('a'<=c&&c<='z'||'A'<=c&&c<='Z'|| c==' ')	{
	     			if (l==0  && ('a'<=c&&c<='z'))		c=c+'A'-'a'; // thuong thanh hoa
	     			else if (l!=0 && s[l-1] == ' ' && ('a'<=c&&c<='z')) c=c+'A'-'a';
	     			else if (l!=0 && s[l-1] != ' ' && ('A'<=c&&c<='Z')) 	c=c-'A' + 'a'; // hoa thanh thuong
	     			else if (c==' ' && (l==0 || s[l-1] == ' ')) continue;				
			     	s[l]=c;
					l++;
					s[l+1]='\0';
					outtextxy(x,y,s);
				}
				else if(c==8){
					if (l==0) continue;
					s[l-1]=' ';		s[l]=' ';	s[l+1] = ' ';	s[l+2] = ' ';
					outtextxy(x,y,s);		l--;
				}else if (c==13){
					if (s[l-1] ==32) s[l-1] = '\0';
					else s[l] = '\0';
					Key=-2;
					break;
				} else if (c==9){
					if (s[l-1] ==32) s[l-1] = '\0';
					else s[l] = '\0';
					Key=-3;
					break;
				}else continue;	
			} 	
			 else if(c==8){
					s[l-1]=' ';		s[l]=' ';	s[l+1] = ' ';	s[l+2] = ' ';
					outtextxy(x,y,s);
					l--;		
			}else if (c==13){
				if (s[l-1] ==32) s[l-1] = '\0';
				else s[l] = '\0';
				s[l]='\0';
				Key=-2;
				break;
			} else if (c==9){
				if (s[l-1] ==32) s[l-1] = '\0';
				else s[l] = '\0';
				Key=-3;
				break;
			}else continue;	
		}
		else{
			s[l]='|';
			delay(100);
			outtextxy(x,y,s);
			s[l]=' ';
			delay(100);
			outtextxy(x,y,s);
		}
		if (ismouseclick(WM_LBUTTONDOWN)){
			 getmouseclick(WM_LBUTTONDOWN, x1, y1);
			 if (Mapid[x1][y1] != id) {
			 	if (s[l-1] ==32) s[l-1] = '\0';
				else s[l] = '\0';
			 	Key=Mapid[x1][y1];
			 	break;
			 }
		}	
	}	 
}
void ScanTen_NV(int x, int y, char s[], int lenMax,int mauNen, int id,int &Key){   
	settextstyle(6,0,1);
	setcolor(0);
	setbkcolor(mauNen);
    int l=strlen(s);
    s[l+1]='\0';   s[l]='|';
    int x1,y1;
     while(1){
		outtextxy(x,y,s);
     	if(kbhit()){
	     	char c= getch();
	     	if ((int)c == 0){
	     		c = getch();
	     		continue;
			}
	     	if (l<lenMax){
	     		if('a'<=c&&c<='z'||'A'<=c&&c<='Z')	{
	     			if (l==0  && ('a'<=c&&c<='z'))		c=c+'A'-'a'; // thuong thanh hoa
	     			else if (l!=0  && ('A'<=c&&c<='Z')) 	c=c-'A' + 'a'; // hoa thanh thuong				
			     	s[l]=c;
					l++;
					s[l+1]='\0';
					outtextxy(x,y,s);
				}
				else if(c==8){
					if (l==0) continue;
					s[l-1]=' ';		s[l]=' ';	s[l+1] = ' ';	s[l+2] = ' ';
					outtextxy(x,y,s);		l--;
				}else if (c==13){
					if (s[l-1] ==32) s[l-1] = '\0';
					else s[l] = '\0';
					Key=-2;
					break;
				} else if (c==9){
					if (s[l-1] ==32) s[l-1] = '\0';
					else s[l] = '\0';
					Key=-3;
					break;
				}else continue;	
			} 	
			 else if(c==8){
					s[l-1]=' ';		s[l]=' ';	s[l+1] = ' ';	s[l+2] = ' ';
					outtextxy(x,y,s);
					l--;		
			}else if (c==13){
				if (s[l-1] ==32) s[l-1] = '\0';
				else s[l] = '\0';
				s[l]='\0';
				Key=-2;
				break;
			} else if (c==9){
				if (s[l-1] ==32) s[l-1] = '\0';
				else s[l] = '\0';
				Key=-3;
				break;
			}else continue;	
		}
		else{
			s[l]='|';
			delay(100);
			outtextxy(x,y,s);
			s[l]=' ';
			delay(100);
			outtextxy(x,y,s);
		}
		if (ismouseclick(WM_LBUTTONDOWN)){
			 getmouseclick(WM_LBUTTONDOWN, x1, y1);
			 if (Mapid[x1][y1] != id) {
			 	if (s[l-1] ==32) s[l-1] = '\0';
				else s[l] = '\0';
			 	Key=Mapid[x1][y1];
			 	break;
			 }
		}	
	}	 
}
void ScanSo(int x, int y, char *s, int lenMax,int mauNen, int id, int &Key){
	settextstyle(6,0,1);
	setcolor(0);
	setbkcolor(mauNen);
    int l=strlen(s);
    s[l+1]='\0';
    s[l]='|';
    int x1,y1;
     while(1){
		outtextxy(x,y,s);
     	if(kbhit()){
	     	char c= getch();
	     	if ((int)c == 0){
	     		c = getch();
	     		continue;
			}
	     	if (l<lenMax){
	     		if(c >= '0' && c <= '9'){
				 	if (l==0 && c=='0') continue;
					else{
						s[l]=c;
						l++;
						s[l+1]='\0';
						outtextxy(x,y,s);
					}	
				}
				else if(c==8){
					if (l==0) continue;
					s[l-1]='|';
					s[l]=' ';
					l--;
					outtextxy(x,y,s);	
				}else if (c==13){
					s[l]='\0';
					Key=-2;
					break;
				}else if (c==9){
					s[l]='\0';
					Key=-3;
					break;
				}else continue;		
			 } 	
			else if(c==8){
					s[l-1]='|';
					s[l]=' ';
					l--;
					outtextxy(x,y,s);
			}else if (c==13){
					s[l]='\0';
					Key=-2;
					break;
			}else if (c==9){
				s[l]='\0';
				Key=-3;
				break;
			}else continue;	
		}
		else{
			s[l]='|';
			delay(100);
			outtextxy(x,y,s);
			s[l]=' ';
			delay(100);
			outtextxy(x,y,s);
		}
		if (ismouseclick(WM_LBUTTONDOWN)){
			 getmouseclick(WM_LBUTTONDOWN, x1, y1);
			 if (Mapid[x1][y1] != id) {
			 	s[l]='\0';
			 	Key=Mapid[x1][y1];
			 	break;
			 }
		}
	}
}
void ScanMa(int x, int y, char s[], int lenMax,int mauNen ,int id, int &Key){
	settextstyle(6,0,1);
	setcolor(0);
	setbkcolor(mauNen);
    int l=strlen(s);
    s[l+1]='\0';
    s[l]='|';
    int x1,y1;
     while(1){
		outtextxy(x,y,s);
     	if(kbhit()){
	     	char c= getch();
	     	if ((int)c == 0){
	     		c = getch();
	     		continue;
			}
	     	if (l<lenMax){
	     		if(('0' <=c  && c <= '9') || ('a'<=c&&c<='z')||('A'<=c&&c<='Z')){	
	     			if (l==0 && ('0' <=c  && c <= '9')) continue;
	     			if ('a'<=c&&c<='z')	c=c+'A'-'a';
			     	s[l]=c;
					l++;
					s[l+1]='\0';
					outtextxy(x,y,s);
				}
				else if(c==8){
					if (l==0) continue;
					s[l-1]=' ';		s[l]=' ';	s[l+1] = ' ';	s[l+2] = ' ';
					outtextxy(x,y,s);	
					l--;	
				}else if (c==13){
					s[l]='\0';
					Key=-2;
					break;
				}else if (c==9){
					s[l]='\0';
					Key=-3;
					break;
				}else continue;		
			 } 	
			 else if(c==8){
					if (l==0) continue;
					s[l-1]=' ';		s[l]=' ';	s[l+1] = ' ';	s[l+2] = ' ';
					outtextxy(x,y,s);	
					l--;
			}else if (c==13){
				s[l]='\0';
				Key=-2;
				break;
			}else if (c==9){
				s[l]='\0';
				Key=-3;
				break;
			}else continue;	
		}
		else{
			s[l]='|';
			delay(100);
			outtextxy(x,y,s);
			s[l]=' ';
			delay(100);
			outtextxy(x,y,s);
		}
		if (ismouseclick(WM_LBUTTONDOWN)){
			 getmouseclick(WM_LBUTTONDOWN, x1, y1);
			 if (Mapid[x1][y1] != id) {
			 	s[l]='\0';
			 	Key=Mapid[x1][y1];
			 	break;
			 }
		}
	 }
}
void DrawTableVatTu(){
	setKhung();
	// ve nen thanh cong cu
	DrawBar(4,4,MAX_X-45,70,Cyan);
	DrawBar(MAX_X-45,4,MAX_X-2,70,LRed);
	WriteText(MAX_X-35,25,"X",Black,LRed,sizeChu+2);
	DrawRecTangle(2,2,MAX_X,68,Black,4);
	DrawRecTangle(MAX_X-46,2,MAX_X,68,Black,4);
	// ve 4 o cong cu
	// o vat tu
	DrawBar(12,10,302,60,LYellow); 
	WriteText(100,25,"VAT TU",Black,LYellow,sizeChu); // note
	DrawRecTangle(12,10,302,60,Black,2);
	
	DrawBar(310,10,600,60,LGreen);
	WriteText(380,25,"NHAN VIEN",Black,LGreen,sizeChu);	
	DrawBar(608,10,898,60,LGreen);
	WriteText(680,25,"THANH TOAN",Black,LGreen,sizeChu);
	DrawBar(906,10,1198,60,LGreen);
	WriteText(1000,25,"THONG KE",Black,LGreen,sizeChu);
	//khung muc luc
	DrawRecTangle(15,75,MAX_X-10,115,Black,2);
	// 3 o muc luc
	DrawBar(20,80,220,110,LYellow);
	WriteText(25,85,"Them Vat Tu",Black,LYellow,sizeChu);
	DrawBar(230,80,400,110,LYellow);
	WriteText(235,85,"Hieu Chinh",Black,LYellow,sizeChu);
	DrawBar(410,80,620,110,LYellow);
	WriteText(415,85,"In Danh Sach",Black,LYellow,sizeChu);
	CleanID();
	TaoID(20,80,220,110,11);
	TaoID(230,80,400,110,12);
	TaoID(410,80,620,110,13);	
}
void DrawTableVtThem(){
	//ve lai bk Lwhite
	CleanBK();
	DrawRecTangle(15,75,MAX_X-10,115,Black,2);
	// 3 o muc luc
	DrawBar(20,80,220,110,LGreen);
	WriteText(25,85,"Them Vat Tu",Black,LGreen,sizeChu);
	DrawRecTangle(20,80,220,110,Black,2);
	
	DrawBar(230,80,400,110,LYellow);
	WriteText(235,85,"Hieu Chinh",Black,LYellow,sizeChu);
	DrawBar(410,80,620,110,LYellow);
	WriteText(415,85,"In Danh Sach",Black,LYellow,sizeChu);
	//
	DrawBar(390,150,820,190,Cyan);
	DrawRecTangle(390,150,820,190,Black,2);
	WriteText(400+55,150+15,"Nhap Thong Tin Vat Tu",Black,Cyan,sizeChu);
	DrawBar(250,190,970,400,LWhite);
	DrawRecTangle(230,190,980,501,Black,2);
	
	WriteText(260,230,"Ma Vat Tu: ",Black,LWhite,sizeChu);
	DrawRecTangle(420,220,800,250,Black,1);
		
	WriteText(260,280,"Ten Vat Tu: ",Black,LWhite,2);
	DrawRecTangle(420,270,800,300,Black,1);
	
	
	WriteText(260,330,"Don Vi Tinh: ",Black,LWhite,sizeChu);
	DrawRecTangle(420,320,800,350,Black,1);	
	
	WriteText(260,380,"So Luong: ",Black,LWhite,sizeChu);
	DrawRecTangle(420,370,800,400,Black,1);

	DrawBar(260,420,950,460,LYellow);
	WriteText(570,435,"THEM",Black,LYellow,sizeChu);
	DrawRecTangle(260,420,950,460,Black,2);
	
	WriteText(290, 530,"( Neu SoLuong = 0, Xin hay bo trong, Khong can nhap )",Red,LWhite,1);
	CleanID2();
	TaoID(420,220,800,250,111);
	TaoID(420,270,800,300,112);
	TaoID(420,320,800,350,113);
	TaoID(420,370,800,400,114);
	TaoID(260,420,950,460,115);
}
void DrawTableVt_Chinh(){
	CleanBK();
	DrawRecTangle(15,75,MAX_X-10,115,Black,2);
	// 3 o muc luc
	DrawBar(20,80,220,110,LYellow);
	WriteText(25,85,"Them Vat Tu",Black,LYellow,sizeChu);
	DrawBar(230,80,400,110,LGreen);
	WriteText(235,85,"Hieu Chinh",Black,LGreen,sizeChu);
	DrawRecTangle(230,80,400,110,Black,2);
	DrawBar(410,80,620,110,LYellow);
	WriteText(415,85,"In Danh Sach",Black,LYellow,sizeChu);
	//
	DrawBar(400,150,820,190,Cyan);
	DrawRecTangle(400,150,820,190,Black,2);
	WriteText(400+60,150+15,"Thong Tin Vat Tu",Black,Cyan,sizeChu);
	DrawBar(250,190,970,400,LWhite);
	DrawRecTangle(230,190,980,501,Black,2);
	
	WriteText(260,230,"Ma Vat Tu: ",Black,LWhite,sizeChu);
	DrawRecTangle(420,220,800,250,Black,1);
	
	WriteText(260,280,"Ten Vat Tu: ",Black,LWhite,sizeChu);
	DrawRecTangle(420,270,800,300,Black,1);
	
	WriteText(260,330,"Don Vi Tinh: ",Black,LWhite,sizeChu);
	DrawRecTangle(420,320,800,350,Black,1);	
	
	WriteText(260,380,"So Luong: ",Black,LWhite,sizeChu);
	DrawRecTangle(420,370,800,400,Black,1);
	
	DrawBar(260,420,600,460,LYellow);
	WriteText(410,430,"LUU",Black,LYellow,sizeChu);
	DrawRecTangle(260,420,600,460,Black,2);

	DrawBar(620,420,950,460,LYellow);
	WriteText(760,430,"XOA",Black,LYellow,sizeChu);
	DrawRecTangle(620,420,950,460,Black,2);

	CleanID2();
	TaoID(420,220,800,250,1211);
	TaoID(420,270,800,300,1212);
	TaoID(420,320,800,350,1213);
	TaoID(420,370,800,400,1214);
	TaoID(260,420,600,460,1215);
	TaoID(620,420,950,460,1216);
}
void DrawTableVtHieuChinh(){
	CleanBK();
	
	DrawRecTangle(15,75,MAX_X-10,115,Black,2);
	// 3 o muc luc
	DrawBar(20,80,220,110,LYellow);
	WriteText(25,85,"Them Vat Tu",Black,LYellow,sizeChu);
	DrawBar(230,80,400,110,LGreen);
	WriteText(235,85,"Hieu Chinh",Black,LGreen,sizeChu);
	DrawRecTangle(230,80,400,110,Black,2);
	
	DrawBar(410,80,620,110,LYellow);
	WriteText(415,85,"In Danh Sach",Black,LYellow,sizeChu);
	// chinh
	DrawBar(400,150,820,190,Cyan);
	DrawRecTangle(400,150,820,190,Black,2);
	WriteText(400+70,150+15,"Nhap Vao Ma Vat Tu",Black,Cyan,sizeChu);
	DrawBar(250,190,970,400,LWhite);
	DrawRecTangle(250,190,980,500,Black,2);
	
	WriteText(300,350,"Ma Vat Tu: ",Black,LWhite,sizeChu);
	DrawRecTangle(500,340,800,370,Black,1);
	
	DrawBar(270,420,950,460,LYellow);
	WriteText(530,435,"Tim vat tu",Black,LYellow,sizeChu);
	DrawRecTangle(270,420,950,460,Black,2);	
	
	CleanID2();
	TaoID(500,340,800,370,121);
	TaoID(270,420,950,460,122);
}
void DrawTableVtInDSVT(){
	//
	CleanBK();
	//
	DrawRecTangle(15,75,MAX_X-10,115,Black,2);
	// 3 o muc luc
	DrawBar(20,80,220,110,LYellow);
	WriteText(25,85,"Them Vat Tu",Black,LYellow,sizeChu);
	DrawBar(230,80,400,110,LYellow);
	WriteText(235,85,"Hieu Chinh",Black,LYellow,sizeChu);
	DrawBar(410,80,620,110,LGreen);
	WriteText(415,85,"In Danh Sach",Black,LGreen,sizeChu);
	DrawRecTangle(410,80,620,110,Black,2);
	//
	DrawBar(300,145,950,200,Cyan);
	WriteText(300+200,145+20,"Danh Sach Vat Tu",Black,Cyan,sizeChu);
	DrawRecTangle(100,135,1150,590,Black,2);
	// back next
	DrawBar(110,145,230,200,Blue);
	DrawRecTangle(110,145,230,200,Black,2);
	WriteText(110+5,145+20," << Prev",LWhite,Blue,sizeChu);
	
	DrawBar(1020,145,1140,200,Blue);
	DrawRecTangle(1020,145,1140,200,Black,2);
	WriteText(1020+5,145+20," Next >>",LWhite,Blue,sizeChu);
	
	//table
	DrawRecTangle(105,210,355,585,Black,1);
	WriteText(105+70,210+6,"Ma VT",Black,Cyan,sizeChu);
	
	DrawRecTangle(355,210,705,585,Black,1);
	WriteText(355+90,210+6,"Ten Vat Tu", Black,Cyan,sizeChu);
	
	DrawRecTangle(705,210,905,585,Black,1);
	WriteText(705+15,210+6,"Don vi tinh",Black,Cyan,sizeChu);
	
	DrawRecTangle(905,210,1145,585,Black,1);
	WriteText(905+25,210+6,"So luong ton", Black,Cyan,sizeChu);
	
	line(105,240,1145,240);
	
		//	 15 dong/lan
//		int x1=110, y1= 245;
//	for (int i=0; i<15;i++){
//		WriteText(x1,y1,"ok",Black,LRed,sizeChu);
//		y1+=22;
//	}
	CleanID2();
	TaoID(110,145,230,200,131);
	TaoID(1020,145,1140,200,132);	
}
void DrawTableNhanVien(){
	setKhung();
	// ve nen thanh cong cu
	DrawBar(4,4,MAX_X-45,70,Cyan);
	DrawBar(MAX_X-45,4,MAX_X-2,70,LRed);
	WriteText(MAX_X-35,25,"X",Black,LRed,3);
	DrawRecTangle(2,2,MAX_X,68,Black,4);
	DrawRecTangle(MAX_X-46,2,MAX_X,68,Black,4);
	 // 	
	DrawBar(12,10,302,60,LGreen);
	WriteText(100,25,"VAT TU",Black,LGreen,sizeChu);
	
	DrawBar(310,10,600,60,LYellow);
	WriteText(380,25,"NHAN VIEN",Black,LYellow,sizeChu); // note
	DrawRecTangle(310,10,600,60,Black,2);

	DrawBar(608,10,898,60,LGreen);
	WriteText(680,25,"THANH TOAN",Black,LGreen,sizeChu);
	DrawBar(906,10,1198,60,LGreen);
	WriteText(1000,25,"THONG KE",Black,LGreen,sizeChu);
	//khung muc luc
	DrawRecTangle(15,75,MAX_X-10,115,Black,2);
	// 3 o muc luc
	DrawBar(20,80,260,110,LYellow);
	WriteText(25,85,"Them Nhan Vien",Black,LYellow,sizeChu);
	DrawBar(270,80,440,110,LYellow);
	WriteText(275,85,"Hieu Chinh",Black,LYellow,sizeChu);
	DrawBar(450,80,650,110,LYellow);
	WriteText(455,85,"In Danh Sach",Black,LYellow,sizeChu);
	CleanID();
	TaoID(20,80,260,110,21);
	TaoID(270,80,440,110,22);
	TaoID(450,80,650,110,23);	
}
void DrawTableNvThem(){
	// ve lai man hinh LWhite
	CleanBK();
	//
	DrawRecTangle(15,75,MAX_X-10,115,Black,2);
	// 3 o muc luc
	DrawBar(20,80,260,110,LGreen);
	WriteText(25,85,"Them Nhan Vien",Black,LGreen,sizeChu);
	DrawRecTangle(20,80,260,110,Black,2);
	
	DrawBar(270,80,440,110,LYellow);
	WriteText(275,85,"Hieu Chinh",Black,LYellow,sizeChu);
	DrawBar(450,80,650,110,LYellow);
	WriteText(455,85,"In Danh Sach",Black,LYellow,sizeChu);
	//
	DrawBar(400,150,820,190,Cyan);
	DrawRecTangle(400,150,820,190,Black,2);
	WriteText(400+30,150+15,"Nhap Thong Tin Nhan Vien",Black,Cyan,2);
	DrawBar(250,190,970,400,LWhite);
	DrawRecTangle(250,190,980,500,Black,2);
	// MaNV
	WriteText(280,230,"Ma Nhan Vien: ",Black,LWhite,sizeChu);
	DrawRecTangle(500,220,800,250,Black,1);
	//ho
	WriteText(280,280,"Ho: ",Black,LWhite,sizeChu);
	DrawRecTangle(500,270,800,300,Black,1);
	//ten
	WriteText(280,330,"Ten: ",Black,LWhite,sizeChu);
	DrawRecTangle(500,320,800,350,Black,1);
	//phai
	WriteText(280,380,"Phai: ",Black,LWhite,sizeChu);
	DrawBar(500,370,650,400,LWhite);
	DrawBar(650,370,800,400,LWhite);
	DrawRecTangle(500,370,650,400,Black,1);
	DrawRecTangle(650,370,800,400,Black,1);
	WriteText(500+50,370+7,"NAM",Black,LWhite,sizeChu);
	WriteText(650+55,370+7,"NU",Black,LWhite,sizeChu);
	
	DrawBar(270,420,950,460,LYellow);
	WriteText(570,435,"THEM",Black,LYellow,sizeChu);
	
	DrawRecTangle(270,420,950,460,Black,2);	
	
	CleanID2();
	TaoID(500,220,800,250,211);
	TaoID(500,270,800,300,212);
	TaoID(500,320,800,350,213);
	TaoID(500,370,650,400,214);
	TaoID(650,370,800,400,215);
	TaoID(270,420,950,460,216);
} 
void DrawTableNvHieuCHinh(){
	//ve lai man hinh Lwhite
	CleanBK();
	//
	DrawRecTangle(15,75,MAX_X-10,115,Black,2);
	// 3 o muc luc
	DrawBar(20,80,260,110,LYellow);
	WriteText(25,85,"Them Nhan Vien",Black,LYellow,sizeChu);
	DrawBar(270,80,440,110,LGreen);
	WriteText(275,85,"Hieu Chinh",Black,LGreen,sizeChu);
	DrawRecTangle(270,80,440,110,Black,2);
	
	DrawBar(450,80,650,110,LYellow);
	WriteText(455,85,"In Danh Sach",Black,LYellow,sizeChu);
	//
	DrawBar(400,150,820,190,Cyan);
	DrawRecTangle(400,150,820,190,Black,2);
	WriteText(400+70,150+15,"Nhap Vao Ma Nhan Vien",Black,Cyan,sizeChu);
	DrawBar(250,190,970,400,LWhite);
	DrawRecTangle(250,190,970,500,Black,2);
	
	WriteText(280,300,"Ma Nhan Vien: ",Black,LWhite,sizeChu);
	DrawRecTangle(500,290,800,320,Black,1);

	DrawBar(270,420,950,460,LYellow);
	WriteText(530,435,"Tim Nhan Vien",Black,LYellow,sizeChu);
	DrawRecTangle(270,420,950,460,Black,2);	
	
	CleanID2();
	TaoID(500,290,800,320,221);
	TaoID(270,420,950,460,222);
}
void DrawTableNv_Chinh(){
	CleanBK();
	//
	DrawRecTangle(15,75,MAX_X-10,115,Black,2);
	// 3 o muc luc
	DrawBar(20,80,260,110,LYellow);
	WriteText(25,85,"Them Nhan Vien",Black,LYellow,sizeChu);
	DrawBar(270,80,440,110,LGreen);
	WriteText(275,85,"Hieu Chinh",Black,LGreen,sizeChu);
	DrawRecTangle(270,80,440,110,Black,2);
	
	DrawBar(450,80,650,110,LYellow);
	WriteText(455,85,"In Danh Sach",Black,LYellow,sizeChu);
	//
	DrawBar(400,150,820,190,Cyan);
	DrawRecTangle(400,150,820,190,Black,2);
	WriteText(400+50,150+15,"Thong Tin Nhan Vien",Black,Cyan,sizeChu);
	DrawBar(250,190,970,400,LWhite);
	DrawRecTangle(250,190,970,500,Black,2);
	// MaNV
	WriteText(280,230,"Ma Nhan Vien: ",Black,LWhite,sizeChu);
	DrawRecTangle(500,220,800,250,Black,1);
	//ho
	WriteText(280,280,"Ho: ",Black,LWhite,sizeChu);
	DrawRecTangle(500,270,800,300,Black,1);
	//ten
	WriteText(280,330,"Ten: ",Black,LWhite,sizeChu);
	DrawRecTangle(500,320,800,350,Black,1);
	//phai
	WriteText(280,380,"Phai: ",Black,LWhite,sizeChu);
	DrawBar(500,370,650,400,LWhite);
	DrawBar(650,370,800,400,LWhite);
	DrawRecTangle(500,370,650,400,Black,1);
	DrawRecTangle(650,370,800,400,Black,1);
	WriteText(500+50,370+7,"NAM",Black,LWhite,sizeChu);
	WriteText(650+55,370+7,"NU",Black,LWhite,sizeChu);
	
	DrawBar(270,420,600,460,LYellow);
	WriteText(410,430,"LUU",Black,LYellow,sizeChu);
	DrawRecTangle(270,420,600,460,Black,2);
	
	DrawBar(620,420,950,460,LYellow);
	WriteText(760,430,"XOA",Black,LYellow,sizeChu);
	DrawRecTangle(620,420,950,460,Black,2);
	CleanID2();
}
void DrawTableNvInDSNV(){
	CleanBK();
	//
	DrawRecTangle(15,75,MAX_X-10,115,Black,2);
	// 3 o muc luc
	DrawBar(20,80,260,110,LYellow);
	WriteText(25,85,"Them Nhan Vien",Black,LYellow,sizeChu);
	DrawBar(270,80,440,110,LYellow);
	WriteText(275,85,"Hieu Chinh",Black,LYellow,sizeChu);
	DrawBar(450,80,650,110,LGreen);
	WriteText(455,85,"In Danh Sach",Black,LGreen,sizeChu);
	DrawRecTangle(450,80,650,110,Black,2);
	// tieu de
	DrawBar(300,145,950,200,Cyan);
	WriteText(300+200,145+20,"Danh Sach Nhan Vien",Black,Cyan,sizeChu);
	// back + next
	DrawBar(110,145,230,200,Blue);
	DrawRecTangle(110,145,230,200,Black,2);
	WriteText(110+5,145+20," << Prev",LWhite,Blue,sizeChu);
	
	DrawBar(1020,145,1140,200,Blue);
	DrawRecTangle(1020,145,1140,200,Black,2);
	WriteText(1020+5,145+20," Next >>",LWhite,Blue,sizeChu);
	
	//khung
	DrawRecTangle(100,135,1150,590,Black,2);
	//bang
	DrawRecTangle(105,210,355,585,Black,1);
	WriteText(105+90,210+6,"Ma NV",Black,LWhite,sizeChu);
	
	DrawRecTangle(355,210,705,585,Black,1);
	WriteText(355+150,210+6,"Ho", Black,LWhite,sizeChu);
	
	DrawRecTangle(705,210,905,585,Black,1);
	WriteText(705+70,210+6,"Ten",Black,LWhite,sizeChu);
	
	DrawRecTangle(905,210,1145,585,Black,1);
	WriteText(905+90,210+6,"Phai", Black,LWhite,sizeChu);
	
	line(105,240,1145,240);
	
	CleanID2();
	TaoID(110,145,230,200,231);
	TaoID(1020,145,1140,200,232);
	
}
void DrawTableT_Toan(){
	setKhung();
	// ve nen thanh cong cu
	DrawBar(4,4,MAX_X-45,70,Cyan);
	DrawBar(MAX_X-45,4,MAX_X-2,70,LRed);
	WriteText(MAX_X-35,25,"X",Black,LRed,3);
	DrawRecTangle(2,2,MAX_X,68,Black,4);
	DrawRecTangle(MAX_X-46,2,MAX_X,68,Black,4);
	 // 	
	DrawBar(12,10,302,60,LGreen);
	WriteText(100,25,"VAT TU",Black,LGreen,sizeChu);
	DrawBar(310,10,600,60,LGreen);
	WriteText(380,25,"NHAN VIEN",Black,LGreen,sizeChu); 
	DrawBar(608,10,898,60,LYellow); 
	WriteText(680,25,"THANH TOAN",Black,LYellow,sizeChu); 
	DrawRecTangle(608,10,898,60,Black,2);// note
	
	DrawBar(906,10,1198,60,LGreen);
	WriteText(1000,25,"THONG KE",Black,LGreen,sizeChu);
	//khung muc luc
	DrawRecTangle(15,75,MAX_X-10,115,Black,2);
	// 3 o muc luc
	DrawBar(20,80,220,110,LYellow);
	WriteText(25,85,"Lap Hoa Don",Black,LYellow,sizeChu);
	DrawBar(230,80,400,110,LYellow);
	WriteText(235,85,"In Hoa Don",Black,LYellow,sizeChu);	
	//tao ID
	CleanID();
	TaoID(20,80,220,110,31);
	TaoID(230,80,400,110,32);
}
void DrawTableT_TChiTiet(){
	/// clean;
	DrawBar(19,269,MAX_X-14,MAX_Y-9,LWhite);
	// draw;
	DrawRecTangle(20,270,150,MAX_Y-10,Black,1);
	WriteText(20+25,270+2,"MaVT", Black,LWhite,sizeChu);
	
	DrawRecTangle(150,270,450,MAX_Y-10,Black,1);	
	WriteText(150+110,270+2,"TenVT", Black,LWhite,sizeChu);
	
	DrawRecTangle(450,270,590,MAX_Y-10,Black,1);		
	WriteText(450+30,270+2,"DonVi", Black,LWhite,sizeChu);
	
	DrawRecTangle(590,270,720,MAX_Y-10,Black,1);	
	WriteText(590+25,270+2,"SLuong", Black,LWhite,sizeChu);
	
	DrawRecTangle(720,270,900,MAX_Y-10,Black,1);	
	WriteText(720+25,270+2,"DonGia", Black,LWhite,sizeChu);
	
	DrawRecTangle(900,270,970,MAX_Y-10,Black,1);		
	WriteText(900+10,270+2,"VAT", Black,LWhite,sizeChu);
	
	DrawRecTangle(970,270,MAX_X-55,MAX_Y-10,Black,1);		
	WriteText(970+40,270+2,"Thanh Tien", Black,LWhite,sizeChu);
	
	DrawRecTangle(MAX_X-55,270,MAX_X-15,MAX_Y-10,Black,1);
	WriteText(MAX_X-55+10,270,"X", Black,LRed,sizeChu);
	DrawRecTangle(MAX_X-47,270+2,MAX_X-25,290,Black,1);
	
	line(20,290,MAX_X-15,290);
}
void DrawTableT_TLapHoaDon(){
	// clean
	CleanBK();
	//
	//khung muc luc
	DrawRecTangle(15,75,MAX_X-10,115,Black,2);
	// 3 o muc luc
	DrawBar(20,80,220,110,LGreen);
	WriteText(25,85,"Lap Hoa Don",Black,LGreen,sizeChu);
	DrawRecTangle(20,80,220,110,Black,2);
	
	DrawBar(230,80,400,110,LYellow);
	WriteText(235,85,"In Hoa Don",Black,LYellow,sizeChu);	
	//
	DrawBar(400,84,822,107,LWhite);
	DrawBar(20,125,1235,265,LCyan);
	DrawRecTangle(20,125,1235,265,LCyan,1);
	//
//	DrawBar(98,132,1152,592,LWhite);
	DrawRecTangle(15,120,MAX_X-10,MAX_Y-5,Black,1);
	// lap hoa don
	DrawBar(20,125,100,200,LRed);
	DrawRecTangle(20,125,100,200,Black,1);
	WriteText(20+7,125+3,"LAP",Black,LRed,2);
	WriteText(20+7,148+3,"HOA",Black,LRed,2);
	WriteText(20+7,171+3,"DON",Black,LRed,2);
	// nhap xuat
	DrawRecTangle(20,205,120,265,Black,1);
	WriteText(25+40,205+20,"N",Black,LCyan,sizeChu);
	DrawRecTangle(120,205,215,265,Black,1);
	WriteText(125+40,205+20,"X",Black,LCyan,sizeChu);
	// dong 1
	DrawRecTangle(105,125,450,195,Black,1);
	WriteText(105+5,125+5,"  So Hoa Don",Black,LCyan,sizeChu);
	DrawRecTangle(110,155,445,190,Black,1);	
	
	setlinestyle(1,2,3);
	setcolor(LRed);
	line(105,200,215,200);
	
	DrawRecTangle(450,125,700,195,Black,1);
	WriteText(450+5,125+5,"MaNv",Black,LCyan,sizeChu);
	DrawRecTangle(455,155,695,190,Black,1);
	
	
	// XUat ngay thang nam 
	char ngay[50]="";
	char thang[50]="";
	char nam[50]="";
	TODAY(ngay,thang,nam);
	DrawRecTangle(700,125,820,195,Black,1);
	WriteText(700+5,125+15,"Ngay",Black,LCyan,sizeChu);
	DrawRecTangle(780,130,815,170,Black,1);
	WriteText(780+3,130+7,ngay,Black,LCyan,sizeChu);
	
	DrawRecTangle(820,125,950,195,Black,1);
	WriteText(820+5,125+15,"Thang",Black,LCyan,sizeChu);
	DrawRecTangle(910,130,950-5,170,Black,1);
	WriteText(910+3,130+7,thang,Black,LCyan,sizeChu);
	
	DrawRecTangle(950,125,1100,195,Black,1);
	WriteText(950+5,125+15,"Nam",Black,LCyan,sizeChu);
	DrawRecTangle(1010,130,1100-5,170,Black,1);
	WriteText(1010+10,130+7,nam,Black,LCyan,sizeChu);
	
	DrawBar(1105,125,MAX_X-15,190,Blue);
	WriteText(1105+30,125+10,"Them",LWhite,Blue,sizeChu);
	WriteText(1105+30,150+5 ,"CTHD",LWhite,Blue,sizeChu);
	DrawRecTangle(1105,125,MAX_X-15,190,Black,2);
	//dong 2

	DrawRecTangle(220,195,480,265,Black,1);
	WriteText(220+5,195+5,"MaVT",Black,LCyan,sizeChu);
	DrawRecTangle(225,225,475,260,Black,1);
	
	DrawRecTangle(480,195,700,265,Black,1);
	WriteText(480+5,195+5,"SLuong",Black,LCyan,sizeChu);
	DrawRecTangle(485,225,695,260,Black,1);
	
	DrawRecTangle(700,195,950,265,Black,1);
	WriteText(700+5,195+5,"DonGia",Black,LCyan,sizeChu);
	DrawRecTangle(705,225,945,260,Black,1);
	
	DrawRecTangle(950,195,1100,265,Black,1);
	WriteText(950+5,195+5,"VAT",Black,LCyan,sizeChu);
	DrawRecTangle(955,225,1095,260,Black,1);
	// bang thong ke chi tiet hoa don
	DrawTableT_TChiTiet();
	// thanh toan + tong bill
	DrawBar(1105,200,MAX_X-15,260,Blue);
	WriteText(1105+2,205,"Thanh toan", LWhite,Blue,sizeChu);
	WriteText(1105+5,230,"  Hoa Don", LWhite,Blue,sizeChu);
	WriteText(820+5,85,"Tong HD:", Black,LWhite,sizeChu);
	DrawBar(950,84,MAX_X-20,107,LWhite);
	WriteText(950+5,85,"0", Black,LWhite,sizeChu);
	DrawRecTangle(1105,200,MAX_X-15,260,Black,2);
	
	CleanID2();

	TaoID(110,155,445,190,311);	
	TaoID(455,155,695,190,312);
	TaoID(225,225,475,260,313);
	TaoID(485,225,695,260,314);
	TaoID(705,225,945,260,315);
	TaoID(955,225,1130,260,316);
	TaoID(20,205,120,265,317);
	TaoID(120,205,215,265,318);
	TaoID(1105,125,MAX_X-15,190,319); // nut them
	TaoID(1105,200,MAX_X-15,260,3110); // thanh toan hoa don
}
void DrawTableT_TSoHD(){
	// clean
	CleanBK();
	//
	//khung muc luc
	DrawRecTangle(15,75,MAX_X-10,115,Black,2);
	// 3 o muc luc
	DrawBar(20,80,220,110,LYellow);
	WriteText(25,85,"Lap Hoa Don",Black,LYellow,sizeChu);
	DrawBar(230,80,400,110,LGreen);
	WriteText(235,85,"In Hoa Don",Black,LGreen,sizeChu);
	DrawRecTangle(230,80,400,110,Black,2);
	//
	DrawBar(98,132,1152,592,LWhite);
	DrawRecTangle(15,120,MAX_X-10,MAX_Y-10,Black,1);
	
	DrawBar(98,133,1152,592,LWhite);
	DrawBar(400,150,820,190,Cyan);
	DrawRecTangle(400,150,820,190,Black,2);
	WriteText(400+70,150+15,"Nhap Vao So Hoa Don",Black,Cyan,sizeChu);
	DrawBar(250,190,970,400,LWhite);
	DrawRecTangle(250,190,970,500,Black,2);
	
	WriteText(300,310,"So hoa don: ",Black,LWhite,sizeChu);
	DrawRecTangle(500,300,800,330,Black,1);
	
	DrawBar(270,420,950,460,LYellow);
	WriteText(530,435,"Tim hoa don",Black,LYellow,sizeChu);	
	DrawRecTangle(270,420,950,460,Black,2);
	
	CleanID2();
	TaoID(500,300,800,330,321);
	TaoID(270,420,950,460,322);
}
void DrawTableT_TInHD(){
	// clean BK;
		CleanBK();
		CleanID2();
	//
	//khung muc luc
	DrawRecTangle(15,75,MAX_X-10,115,Black,2);
	// 3 o muc luc
	DrawBar(20,80,220,110,LYellow);
	WriteText(25,85,"Lap Hoa Don",Black,LYellow,sizeChu);
	DrawBar(230,80,400,110,LGreen);
	WriteText(235,85,"In Hoa Don",Black,LGreen,sizeChu);
	DrawRecTangle(230,80,400,110,Black,2);	
	//
	// khung
	DrawBar(98,132,1152,592,LWhite);
	DrawRecTangle(15,120,MAX_X-10,MAX_Y-10,Black,2);
	DrawBar(20,125,MAX_X-15,225,LCyan);
	// box in hoa don
	DrawBar(20,125,295,225,LGreen);
	DrawRecTangle(20,125,295,225,Black,1);
	WriteText(20+50,125+40,"IN HOA DON",Black,LGreen,sizeChu);
	// thong tin
	DrawRecTangle(295,125,700,175,Black,1);
	WriteText(295+20,125+15,"SoHD",Black,LCyan,sizeChu);
	DrawRecTangle(400,130,695,170,Black,1);
	
	DrawRecTangle(700,125,820,175,Black,1);
	WriteText(700+5,125+15,"Ngay",Black,LCyan,sizeChu);
	DrawRecTangle(780,130,820-5,170,Black,1);
	
	DrawRecTangle(820,125,950,175,Black,1);
	WriteText(820+5,125+15,"Thang",Black,LCyan,sizeChu);
	DrawRecTangle(910,130,950-5,170,Black,1);
	
	DrawRecTangle(950,125,1100,175,Black,1);
	WriteText(950+5,125+15,"Nam",Black,LCyan,sizeChu);
	DrawRecTangle(1010,130,1100-5,170,Black,1);
	
	DrawRecTangle(1105,125,1167,175,Black,1);
	WriteText(1105+20,125+20,"N",Black,LCyan,sizeChu);
	DrawRecTangle(1167,125,1235,175,Black,1);
	WriteText(1167+20,125+20,"X",Black,LCyan,sizeChu);
	//
	DrawRecTangle(295,175,550,225,Black,1);
	WriteText(295+20,175+15,"MaNV",Black,LCyan,sizeChu);
	DrawRecTangle(400,180,545,220,Black,1);
	
	DrawRecTangle(550,175,960,225,Black,1);
	WriteText(550+10,175+15,"Ho",Black,LCyan,sizeChu);
	DrawRecTangle(600,180,960-5,220,Black,1);
	
	DrawRecTangle(960,175,MAX_X-15,225,Black,1);
	WriteText(960+10,175+15,"Ten",Black,LCyan,sizeChu);
	DrawRecTangle(1030,180,MAX_X-20,220,Black,1);
	// table
	int y=230;
	DrawBar(20,y,MAX_X-15,y+30,Cyan);
	WriteText(20+150,y+5,"MaVT", Black,Cyan,sizeChu);
	WriteText(400+110,y+5,"SLuong", Black,Cyan,sizeChu);
	WriteText(700+55,y+5,"DonGia", Black,Cyan,sizeChu);	
	WriteText(900+10,y+5,"%VAT", Black,Cyan,sizeChu);	
	WriteText(1000+35,y+5,"Thanh Tien", Black,Cyan,sizeChu);
	line(20,y+30,MAX_X-15,y+30);	
}
void DrawTableTke(){
	setKhung();
	// ve nen thanh cong cu
	DrawBar(4,4,MAX_X-45,70,Cyan);
	DrawBar(MAX_X-45,4,MAX_X-2,70,LRed);
	WriteText(MAX_X-35,25,"X",Black,LRed,3);
	DrawRecTangle(2,2,MAX_X,68,Black,4);
	DrawRecTangle(MAX_X-46,2,MAX_X,68,Black,4);
	//   	
	DrawBar(12,10,302,60,LGreen);
	WriteText(100,25,"VAT TU",Black,LGreen,sizeChu);
	DrawBar(310,10,600,60,LGreen);
	WriteText(380,25,"NHAN VIEN",Black,LGreen,sizeChu); 
	DrawBar(608,10,898,60,LGreen); 
	WriteText(680,25,"THANH TOAN",Black,LGreen,sizeChu); 
	DrawBar(906,10,1198,60,LYellow);
	WriteText(1000,25,"THONG KE",Black,LYellow,sizeChu); // note
	DrawRecTangle(906,10,1198,60,Black,2);
	
	//khung muc luc
	DrawRecTangle(15,75,MAX_X-10,115,Black,2);
	// 3 o muc luc
	DrawBar(20,80,300,110,LYellow);
	WriteText(25,85,"Thong Ke Hoa Don",Black,LYellow,sizeChu);
	DrawBar(310,80,530,110,LYellow);
	WriteText(315,85,"Top 10 Vat Tu",Black,LYellow,sizeChu);	
	//tao ID
	CleanID();
	TaoID(20,80,300,110,41);
	TaoID(310,80,530,110,42);
}
void DrawTableTke_Tim(){
	CleanBK();
	//
	DrawRecTangle(15,75,MAX_X-10,115,Black,2);
	// 3 o muc luc
	DrawBar(20,80,300,110,LGreen);
	WriteText(25,85,"Thong Ke Hoa Don",Black,LGreen,sizeChu);
	DrawRecTangle(20,80,300,110,Black,2);
	
	DrawBar(310,80,530,110,LYellow);
	WriteText(315,85,"Top 10 Vat Tu",Black,LYellow,sizeChu);
	//
	DrawBar(400,150,820,190,Cyan);
	DrawRecTangle(400,150,820,190,Black,2);
	WriteText(400+70,150+15,"Tim Kiem Hoa Don",Black,Cyan,sizeChu);
	// khung
	DrawBar(250,190,970,400,LWhite);
	DrawRecTangle(250,190,970,500,Black,2);
	// tu ngay
	int y=250;
	DrawBar(280,y-15-30,520,y-15,Cyan);
	DrawRecTangle(280,y-15-30,520,y-15,Black,2);
	WriteText(280+15,y-15-30+5,"Tu Ngay (BEGIN)",Black,Cyan,sizeChu);
	
	WriteText(270+5,y,"Ngay",Black,LWhite,sizeChu);
	DrawRecTangle(350,y-5,470,y+25,Black,1);
	
	WriteText(510+5,y,"Thang",Black,LWhite,sizeChu);
	DrawRecTangle(610,y-5,730,y+25,Black,1);
	
	WriteText(760+5,y,"Nam",Black,LWhite,sizeChu);
	DrawRecTangle(830,y-5,950,y+25,Black,1);
	// den ngay
	int y1= 360;
	DrawBar(280,y1-45,520,y1-15,Cyan);
	DrawRecTangle(280,y1-45,520,y1-15,Black,2);
	WriteText(280+15,y1-45+5,"Den Ngay (END)",Black,Cyan,sizeChu);
	
	DrawBar(550,y1-45,670,y1-15,LCyan);
	DrawRecTangle(550,y1-45,670,y1-15,Black,2);
	WriteText(550+10,y1-45+5,"TODAY",Black,LCyan,sizeChu);
	
	WriteText(270+5,y1,"Ngay",Black,LWhite,sizeChu);
	DrawRecTangle(350,y1-5,470,y1+25,Black,1);
	
	WriteText(510+5,y1,"Thang",Black,LWhite,sizeChu);
	DrawRecTangle(610,y1-5,730,y1+25,Black,1);
	
	WriteText(760+5,y1+15,"Nam",Black,LWhite,sizeChu);
	DrawRecTangle(830,y1-5,950,y1+25,Black,1);
	
	DrawBar(270,425,950,465,LYellow);
	WriteText(530,440,"Tim Kiem",Black,LYellow,sizeChu);	
	DrawRecTangle(270,425,950,465,Black,2);
	
	CleanID2();
	TaoID(350,y-5,470,y+25,411);
	TaoID(610,y-5,730,y+25,412);
	TaoID(830,y-5,950,y+25,413);
	TaoID(350,y1-5,470,y1+25,414);
	TaoID(610,y1-5,730,y1+25,415);
	TaoID(830,y1-5,950,y1+25,416);
	TaoID(270,420,950,460,417);
	TaoID(550,y1-45,670,y1-15,418);
}
void DrawTableTke_Top10(){
	CleanBK();
	//
	DrawRecTangle(15,75,MAX_X-10,115,Black,2);
	// 3 o muc luc
	DrawBar(20,80,300,110,LYellow);
	WriteText(25,85,"Thong Ke Hoa Don",Black,LYellow,sizeChu);
	DrawBar(310,80,530,110,LGreen);
	WriteText(315,85,"Top 10 Vat Tu",Black,LGreen,sizeChu);
	DrawRecTangle(310,80,530,110,Black,2);
	//
	DrawBar(400,150,820,190,Cyan);
	DrawRecTangle(400,150,820,190,Black,2);
	WriteText(400+70,150+15,"Tim Top 10 Vat Tu",Black,Cyan,sizeChu);
	// khung
	DrawBar(250,190,970,400,LWhite);
	DrawRecTangle(250,190,970,500,Black,2);
	// tu ngay
	int y=250;
	DrawBar(280,y-15-30,520,y-15,Cyan);
	DrawRecTangle(280,y-15-30,520,y-15,Black,2);
	WriteText(280+15,y-15-30+5,"Tu ngay (BEGIN)",Black,Cyan,sizeChu);
	
	WriteText(270+5,y,"Ngay",Black,LWhite,sizeChu);
	DrawRecTangle(350,y-5,470,y+25,Black,1);
	
	WriteText(510+5,y,"Thang",Black,LWhite,sizeChu);
	DrawRecTangle(610,y-5,730,y+25,Black,1);
	
	WriteText(760+5,y,"Nam",Black,LWhite,sizeChu);
	DrawRecTangle(830,y-5,950,y+25,Black,1);
	
	// den ngay
	int y1= 360;
	DrawBar(280,y1-45,520,y1-15,Cyan);
	DrawRecTangle(280,y1-45,520,y1-15,Black,2);
	WriteText(280+15,y1-45+5,"Den Ngay (END)",Black,Cyan,sizeChu);
	
	WriteText(270+5,y1,"Ngay",Black,LWhite,sizeChu);
	DrawRecTangle(350,y1-5,470,y1+25,Black,1);
	
	WriteText(510+5,y1,"Thang",Black,LWhite,sizeChu);
	DrawRecTangle(610,y1-5,730,y1+25,Black,1);
	
	WriteText(760+5,y1+15,"Nam",Black,LWhite,sizeChu);
	DrawRecTangle(830,y1-5,950,y1+25,Black,1);
	
	DrawBar(270,425,950,465,LYellow);
	WriteText(530,440,"Tim Kiem",Black,LYellow,sizeChu);	
	DrawRecTangle(270,425,950,465,Black,2);
	// today
	DrawBar(550,y1-45,670,y1-15,LCyan);
	DrawRecTangle(550,y1-45,670,y1-15,Black,2);
	WriteText(550+10,y1-45+5,"TODAY",Black,LCyan,sizeChu);
	
	CleanID2();
	TaoID(350,y-5,470,y+25,421);
	TaoID(610,y-5,730,y+25,422);
	TaoID(830,y-5,950,y+25,423);
	TaoID(350,y1-5,470,y1+25,424);
	TaoID(610,y1-5,730,y1+25,425);
	TaoID(830,y1-5,950,y1+25,426);
	TaoID(270,420,950,460,427);
	TaoID(550,y1-45,670,y1-15,428);
}
void DrawTableTke_LietKe(){
	CleanBK();
	CleanID2();
	// khung
	DrawBar(20,80,300,110,LGreen);
	WriteText(25,85,"Thong Ke Hoa Don",Black,LGreen,sizeChu);
	DrawRecTangle(20,80,300,110,Black,2);
	
	DrawBar(310,80,530,110,LYellow);
	WriteText(315,85,"Top 10 Vat Tu",Black,LYellow,sizeChu);
	//
	DrawBar(15,120,MAX_X-10,165,Cyan);
	DrawRecTangle(15,120,MAX_X-10,165,Black,2);
	DrawRecTangle(15,120,MAX_X-10,MAX_Y-10,Black,2);
	WriteText(130,130,"BANG LIET KE CAC HOA DON TRONG KHOANG THOI GIAN",Black,Cyan,3);
	// tu ngay den ngay
	int y=180;
	DrawBar(115,170,MAX_X-10-145,215,LCyan);
	DrawRecTangle(115,170,MAX_X-10-145,215,Black,1);
	
	WriteText(110+15,y+5,"Tu",Black,LCyan,2);
	
	WriteText(180+5,y+5,"Ngay",Black,LCyan,sizeChu);
	DrawRecTangle(250,y-5,300,y+30,Black,1);
		
	WriteText(310+5,y+5,"Thang",Black,LCyan,sizeChu);
	DrawRecTangle(400-5,y-5,450,y+30,Black,1);
	
	WriteText(460+2,y+5,"Nam",Black,LCyan,sizeChu);
	DrawRecTangle(520-5,y-5,590,y+30,Black,1);
	
	WriteText(610+15,y+5,"Den",Black,LCyan,2);
	
	WriteText(680+5,y+5,"Ngay",Black,LCyan,sizeChu);
	DrawRecTangle(750,y-5,800,y+30,Black,1);
	
	WriteText(810+5,y+5,"Thang",Black,LCyan,sizeChu);
	DrawRecTangle(900-5,y-5,950,y+30,Black,1);
	
	WriteText(960+2,y+5,"Nam",Black,LCyan,sizeChu);
	DrawRecTangle(1020-5,y-5,1090,y+30,Black,1);
	// prev + next
	DrawBar(20,170,80,215,Blue);
	WriteText(20+5,170+3,"Prev",LWhite,Blue,1);
	WriteText(20+10,170+23," <<",LWhite,Blue,1);
	DrawRecTangle(20,170,80,215,Black,2);
	
	DrawBar(MAX_X-75,170,MAX_X-15,215,Blue);
	WriteText(MAX_X-75+2,170+3,"Next",LWhite,Blue,1);
	WriteText(MAX_X-75+10,170+23," >>",LWhite,Blue,1);
	DrawRecTangle(MAX_X-75,170,MAX_X-15,215,Black,2);
	// bang
	y=220;
	DrawBar(20,220,MAX_X-15,250,LCyan);
	WriteText(20+95,y+5,"SoHD", Black,LCyan,sizeChu);
	WriteText(280+25,y+5,"Ngay Lap", Black,LCyan,sizeChu);	
	WriteText(460+5,y+5,"Loai", Black,LCyan,sizeChu);		
	WriteText(530+105,y+5,"Ho Ten NV Lap", Black,LCyan,sizeChu);
	WriteText(1000+15,y+5,"Tri Gia Hoa Don", Black,LCyan,sizeChu);
	
	line(20,y+30,MAX_X-15,y+30);	
	CleanID2();
	TaoID(20,170,80,215,4171);
	TaoID(MAX_X-75,170,MAX_X-15,215,4172);
}
void DrawTableTKe_BangTop10(){
	//
	CleanBK();
	CleanID2();
	//
	DrawRecTangle(15,75,MAX_X-10,115,Black,2);
	// 3 o muc luc
	DrawBar(20,80,300,110,LYellow);
	WriteText(25,85,"Thong Ke Hoa Don",Black,LYellow,sizeChu);
	
	DrawBar(310,80,530,110,LGreen);
	WriteText(315,85,"Top 10 Vat Tu",Black,LGreen,sizeChu);
	DrawRecTangle(310,80,530,110,Black,2);
	//
	DrawBar(280,145,990,200,Cyan);
	WriteText(290,145+20,"DANH SACH TOP 10 VAT TU DOANH THU CAO NHAT",Black,Cyan,sizeChu);
	DrawRecTangle(100,135,1150,545,Black,2);
	
	//table
	DrawBar(105,210,1145,240,LCyan);
	DrawRecTangle(105,210,155,540,Black,1);
	WriteText(105+3,210+6,"Top",Black,LCyan,sizeChu);
	
	DrawRecTangle(155,210,390,540,Black,1);
	WriteText(155+70,210+6,"Ma VT",Black,LCyan,sizeChu);
	
	DrawRecTangle(390,210,705,540,Black,1);
	WriteText(390+90,210+6,"Ten Vat Tu", Black,LCyan,sizeChu);
	
	DrawRecTangle(705,210,905,540,Black,1);
	WriteText(705+40,210+6,"Don vi tinh",Black,LCyan,sizeChu);
	
	DrawRecTangle(905,210,1145,540,Black,1);
	WriteText(905+65,210+6,"Doanh thu", Black,LCyan,sizeChu);
	
	line(105,240,1145,240);	
	char* s[11] ={"1","2","3","4","5","6","7","8","9","10"};
	int y=240;
	int cach = 16;
	for (int i=0; i<10; i++){
		if (i==9) cach = 10;
		DrawRecTangle(105,y,1145,y+30,Black,1);
		WriteText(105+cach,y+5,s[i],Black,LWhite,sizeChu);
		y+=30;
	}
}
void DrawLogIn(){
	CleanBK();
	
	DrawRecTangle(330,300,860,490,Black,2);
	WriteText(460,310,"    DANG NHAP    ",Black,LRed,3);
	
	WriteText(340,360,"Ten tai khoan:",Black,LWhite,1);
	DrawRecTangle(510,355,770,385,Black,1);
	WriteText(340,395,"Mat khau:",Black,LWhite,1);
	DrawRecTangle(510,390,770,420,Black,1);
	
	DrawBar(775,355,855,420,Blue);
	DrawRecTangle(775,355,855,420,Black,2);
	WriteText(780,375,"Login",LWhite,Blue,1);
	CleanID2();
	TaoID(510,355,770,385,11111);
	TaoID(510,390,770,420,22222);
	TaoID(775,355,855,420,33333);
} 
void BaoTrong(int x, int y){
	WriteText(x+10,y,"Khong duoc",Red,LWhite,sizeChu);
	WriteText(x+10,y+20,"de trong",Red,LWhite,sizeChu);
}
void DrawBegin(){
	setKhung();
	// ve nen thanh cong cu
	DrawBar(4,4,MAX_X-45,70,Cyan);
	DrawBar(MAX_X-45,4,MAX_X-2,70,LRed);
	TaoID(MAX_X-45,4,MAX_X-2,70,-1);
	WriteText(MAX_X-35,25,"X",Black,LRed,3);
	DrawRecTangle(2,2,MAX_X,68,Black,4);
	DrawRecTangle(MAX_X-46,2,MAX_X,68,Black,4);
	// ve 4 o cong cu
	// o vat tu
	DrawBar(12,10,302,60,Cyan); 
	WriteText(100,25,"VAT TU",Black,Cyan,sizeChu);
	TaoID(12,10,302,60,1);
	
	DrawBar(310,10,600,60,Cyan);
	WriteText(380,25,"NHAN VIEN",Black,Cyan,sizeChu);
	TaoID(310,10,600,60,2);
		
	DrawBar(608,10,898,60,Cyan);
	WriteText(680,25,"THANH TOAN",Black,Cyan,sizeChu);
	TaoID(608,10,898,60,3);
	
	DrawBar(906,10,1198,60,Cyan);
	WriteText(1000,25,"THONG KE",Black,Cyan,sizeChu);
	TaoID(906,10,1198,60,4);
	
	DrawRecTangle(290,180,900,550,Black,4);
	DrawRecTangle(280,170,910,560,Black,2);
	
	WriteText(320,220,"  QUAN LI VAT TU", Red,LWhite,5);	
	WriteText(480,330,"Le Quang Hung", Red,LWhite,3);	
	WriteText(470,400,"Tran Quoc Nhon", Red,LWhite,3);	
	WriteText(320,365,"Tac gia:", Red,LWhite,3);
	WriteText(200,600,"(Luu y: Click",Black,LWhite,2);
	WriteText(570,600,"de LUU(Save) va KET THUC chuong trinh)",Black,LWhite,2);
	WriteText(370,600,"(X)",Black,LRed,2);
	DrawRecTangle(420,580,550,650,Black,2);
	DrawBar(420,580,510,620,Cyan);
	DrawBar(510,580,550,620,LRed);
	WriteText(510+10,580+10,"X",Black,LRed,2);
	DrawRecTangle(420,580,510,620,Black,2);
	DrawRecTangle(510,580,550,620,Black,2);
}
void DrawLoading(int x1, int y1, int x2, int y2){
	DrawRecTangle(x1,y1,x2,y2,Red,2);
	int kc = 20;
	int i=1;
	int j=x1;
	while ((x1 + (i-1)*kc) < x2){
		DrawBar(x1+3,y1+3,x1+kc*i,y2-3,Red);
		i++;
		delay(15);
	}
}
void DrawWin(){
	initwindow(MAX_X+10, MAX_Y+15);	
	setbkcolor(LWhite);						
   	cleardevice();
	setMapID();
}
void LogIn(){
	char tk[18]="";
	char mk[20]="";
	char Ntk[18]="";
	char Nmk[20]="";
	int Keyy;
		while(true){
		delay(1);
		Keyy= return_click_mouse();
		lable:
			switch (Keyy){
				case 11111 : {
					
					ScanMa(510+10,355+5,Ntk,13,LWhite,11111,Keyy);
					goto lable;
					break;
				}
				case 22222 : {
					ScanSo(510+10,390+5,Nmk,15,LWhite,22222,Keyy);
					goto lable;
					break;
				}
				case 33333 :{
					if (strcmp(Ntk,tk)==0 && strcmp(Nmk,mk)==0){						
						DrawLoading(335,425,855,450);
						WriteText(500,460,"TK && MK dung",Red,LWhite,1);
						delay(1300);
						DrawBegin();
						Xuli();
					}
					else {
						DrawLoading(335,425,855,450);
						WriteText(500,460,"TK hoac MK sai",Red,LWhite,1);
						delay(1300);
						strcpy(Nmk,"");
						strcpy(Ntk,"");
						DrawLogIn();
					}
					break;
				}
				default : break;
			}
		}
}

