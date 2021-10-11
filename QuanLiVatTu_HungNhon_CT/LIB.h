#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdio>
#include <sstream>
#include <string.h>
#include <stdlib.h>

#include "VatTu.h"
#include "NhanVien.h"

#define year HDon.NgayLap.nam
#define month HDon.NgayLap.thang
#define day HDon.NgayLap.ngay

#define Black 0
#define Blue 1
#define Green 2
#define Cyan 3
#define Red 4
#define Magenta 5
#define Yellow 6
#define White 7
#define Gray 8
#define LBlue 9
#define LGreen 10
#define LCyan 11
#define LRed 12
#define LMagenta 13
#define LYellow 14
#define LWhite 15
#define MAX_X  1250
#define MAX_Y  700
#define sizeChu 1
#define sizeTieuDe 2

#define LH -1
#define EH 0
#define RH 1

#define PTR_HD Node_DSHoaDon*
#define PTR_VT Node_VatTu*
#define PTR_TK_TOP TK_TOP*
using namespace std;
struct TK_TOP{
	string data;
	long long tt;
	PTR_VT vattu;
	TK_TOP *pTrai;
	TK_TOP *pPhai;
};
struct qNode{
	PTR_VT data;
	qNode *next;
};
struct Queue{
	qNode *bot, *top;
	Queue(){
		bot=NULL;
		top=bot;
	}
	bool empty(){
		return(top==NULL);
	}
void push(PTR_VT value){
		qNode *p = new qNode;
		p->data=value;
		p->next=NULL;
		if(top==NULL)
		{
			top=p;
			bot=top;
		}
		else
		{
			bot->next=p; //them phan tu moi vao cuoi Queue
			bot=bot->next;
		}	
	}
	
void pop(){
		if (empty())	return;
		qNode *p = top;
		top=top->next;
		delete p;
	}
	PTR_VT get()
	{
		if (empty()) return NULL;
		return top->data;
	}
	// giai phong bo nho
	~Queue(){
		while(top!=NULL){
			qNode *temp ;
			temp=top;
			top=top->next;
			delete temp;
		}
	}
};
////////////////////////    DANH SACH CAC HAM *******************
void push(PTR_VT value);
void pop();
int  CharToInt(char ch[]);    
void IntToChar(int num,char ch[]);
long long  Char_to_Long(char ch[]);
char* Long_to_Char(long long number);
// vat tu
VatTu tao_VatTuMoi(char mavt[], char tenvt[], char dvt[], int slt);
PTR_VT taoMotNode_VatTuMoi(VatTu VatTuMoi);
void themVaoCay(PTR_VT &Root, char mavt[], char tenvt[], char dvt[], int slt);
PTR_VT TimKiem_MaVT(PTR_VT Root, char mavt_cantim[]);
void DuyetCay_Inorder(PTR_VT p);
void XoaHetCay(PTR_VT &p);
void XoaHetCay_Top10(PTR_TK_TOP &p);
void Xoa_DacBiet(PTR_VT &q,PTR_VT &tam);
void Xoa_MotVatTu(PTR_VT &p,char s[]);
void Nap_DanhSachVatTu(PTR_VT &p, VatTu DSVT[], int &k);
void In_DanhSachVatTu(PTR_VT Root);
void Sort_DanhSachVatTu(VatTu DanhSach_VT[], int low, int high);
void swap(VatTu &a, VatTu &b);
// nhan vien
int TimKiem_MaNV(DanhSachNV DSNhanVien, char s_Ma[]);
void In_ThongTinNhanVien(DanhSachNV &DSNhanVien, char s_Ma[]);
void ADD_nhanVienMoi(DanhSachNV &DSNhanVien, char MaNv[], char HoNv[], char TenNv[],char Phai[]);
void Xoa_MotNhanVien(DanhSachNV &DSNhanVien, char s_Ma[]);
void Sort_dsNhanVien(DanhSachNV &DSNhanVien);
void InFile_NhanVien(DanhSachNV &DSNhanVien);
void OutFile_NhanVien(DanhSachNV &DSNhanVien);
void TODAY(char ngay[], char thang[], char nam[]);
int Return_STT_CTHD(int x_click, int begin, int khoangcach);
//hoa don - chi tiet hoa don
void Add_MotChiTietHoaDon(ChiTietHoaDon &CTHD, char mvt[], int soluong, int dongia, int vat);
void Delete_MotVatTu(ChiTietHoaDon &CTHD, int Vitri);
void Delete_MotVatTu(ChiTietHoaDon &CTHD, int Vitri);
void DocFile_HoaDon(DanhSachNV &DSNhanVien);
void GhiFile_HoaDon(DanhSachNV &DSNhanVien);
void Ghi(PTR_HD tmp,FILE* &file);
bool KTraMaVt_CTHD(ChiTietHoaDon &CTHD, char maVT[]);
bool NamNhuan(int nam);
bool SoSanhDMY(int ngay1, int thang1, int nam1, int ngay2, int thang2, int nam2);
void Sort_DanhSachHoaDon(HoaDon arrHD[],string arrHoTen[], int left, int right);
void Nap_DanhSachMaVatTu(PTR_VT &p, string arrMa[], int &k);
void them_TK_TOP(PTR_TK_TOP &p,string x,long long tt,PTR_VT vattu,int &k);
void LNR(PTR_TK_TOP p,PTR_TK_TOP arr[],int &n);
void Heap(int r,int n,PTR_TK_TOP a[]);
void Heap_Sort(PTR_TK_TOP a[],int n,int x);
////////////////////////////////////////////
void InFile_VatTu(PTR_VT &Root,int &n_VatTu){
	fstream inputFile;
	inputFile.open("VatTuu.txt", ios::in| ios::binary);
	VatTu VTtmp;
	while(inputFile.read((char *) &VTtmp, sizeof(VatTu))){
			themVaoCay(Root, VTtmp.MAVT, VTtmp.TENVT, VTtmp.DVT, VTtmp.SLT);
			n_VatTu++;
			
	}
	inputFile.close();
}
void OutFile_VatTu(PTR_VT Root){
	fstream outputFile;
	outputFile.open("VatTuu.txt", ios::out|ios::binary);
	Queue q;
    PTR_VT p;
    if (Root == NULL) return;
    p = Root;
    q.push(p);
	while (!q.empty()) {
        p = q.get();
        q.pop();
        outputFile.write((const char*) &p->VT, sizeof(VatTu));
        if (p->Trai) q.push(p->Trai);
        if (p->Phai) q.push(p->Phai);
    }
	outputFile.close();
}
int  CharToInt(char ch[]){
	int l=strlen(ch);
	int i=0;
	int res=0;
	while (i<l){
		res =res*10 + (int)(ch[i] - '0');
		i++;
	}
	return res;
}
void IntToChar(int num,char ch[]){
	itoa(num,ch,10);
}
char* Long_to_Char(long long number)
{	      
	string s="";    
	char* array;
    ostringstream convert;   
    convert << number;      
    s = convert.str(); 
    array=(char*)s.c_str(); 
    return array;
}
long long  Char_to_Long(char ch[]){
	int l=strlen(ch);
	int i=0;
	long long res=0;
	while (i<l){
		res =res*10 + (long long)(ch[i] - '0');
		i++;
	}
	return res;
}
VatTu tao_VatTuMoi(char mavt[], char tenvt[], char dvt[], int slt){
	VatTu VatTuMoi;
	strcpy(VatTuMoi.MAVT,mavt);
	strcpy(VatTuMoi.TENVT,tenvt);
	strcpy(VatTuMoi.DVT,dvt);
	VatTuMoi.SLT=slt;
	return VatTuMoi;
}
PTR_VT taoMotNode_VatTuMoi(VatTu VatTuMoi){
	PTR_VT p = new Node_VatTu();
	p->VT = VatTuMoi;
	p->Trai = NULL;
	p->Phai = NULL;
	return p;
}
void themVaoCay(PTR_VT &Root, char mavt[], char tenvt[], char dvt[], int slt)
{
    if(Root==NULL)
    	Root=taoMotNode_VatTuMoi(tao_VatTuMoi(mavt,tenvt,dvt,slt));
	else{
		PTR_VT p=Root;
		PTR_VT q=p;
    	while(p != NULL)
    	{	
    		
  			q=p;
      		if (strcmp(mavt,p->VT.MAVT) == 0)  // bi trung khoa
         		return;	
      		if (strcmp(mavt,p->VT.MAVT) < 0)
	 			p = p->Trai;
      		else      	
	  			p = p->Phai;
    	}
    	if(strcmp(mavt,q->VT.MAVT)<0)
    		q->Trai=taoMotNode_VatTuMoi(tao_VatTuMoi(mavt,tenvt,dvt,slt));
    	else
    		q->Phai=taoMotNode_VatTuMoi(tao_VatTuMoi(mavt,tenvt,dvt,slt));
	}	
}
PTR_VT TimKiem_MaVT(PTR_VT Root, char mavt_cantim[]){
	PTR_VT nodeChay = Root;
	while(nodeChay!=NULL){ 
		int x=strcmp(mavt_cantim, nodeChay->VT.MAVT);
		if(x>0)
			nodeChay=nodeChay->Phai;
		else if(x<0)
				nodeChay=nodeChay->Trai;
			 else
				return nodeChay;
	}
	return NULL;	
}

void Xoa_MotVatTu(PTR_VT &p,char s[]){		
	int x=strcmp(s,p->VT.MAVT);
	if (x<0) Xoa_MotVatTu(p->Trai,s);
	else
		if(x>0) Xoa_MotVatTu(p->Phai,s);
	    else{
			PTR_VT tam=p;
			if(tam->Phai==NULL) p=tam->Trai;
			// p là nút lá hoac la nut chi co cay con ben trai
			else
				if(tam->Trai==NULL) p=tam->Phai;  // p là nut co cay con ben phai hoac la nut la
				else{
					PTR_VT q=p;
					Xoa_DacBiet(q->Phai,tam);
				}
			delete tam;
			}
}
void Xoa_DacBiet(PTR_VT &q,PTR_VT &tam){
	if(q->Trai!=NULL)
		Xoa_DacBiet(q->Trai,tam);
		//den day q la nut cuc trai cua cay con ben phai co nut goc la tam
	else{
		strcpy(tam->VT.MAVT,q->VT.MAVT);  	//Chep noi dung cua tam sang p ";
   		strcpy(tam->VT.TENVT,q->VT.TENVT);
   		strcpy(tam->VT.DVT,q->VT.DVT);
   		tam->VT.SLT=q->VT.SLT;
   		tam=q;	//  de lat nua free(p)
		q=tam->Phai;
	}		
}
void XoaHetCay(PTR_VT &p){
	if(p==NULL)
		return;	
	XoaHetCay(p->Trai);
	XoaHetCay(p->Phai);
	free(p);
}
void XoaHetCay_Top10(PTR_TK_TOP &p){
	if(p==NULL)
		return;	
	XoaHetCay_Top10(p->pTrai);
	XoaHetCay_Top10(p->pPhai);
	free(p);
}
void Nap_DanhSachVatTu(PTR_VT &p, VatTu DanhSach_VT[], int &k){
	if(p != NULL){
		Nap_DanhSachVatTu(p->Trai, DanhSach_VT, k);
    	DanhSach_VT[k]=p->VT;
    	k++;
    	Nap_DanhSachVatTu(p->Phai, DanhSach_VT, k);
   }
}
////**  SAP XEP DS VAT TU THEO TEN
void Sort_DanhSachVatTu(VatTu DanhSach_VT[], int left, int right){
    if (left>=right) return;
    else if(left+1==right){
    		int x=strcmp(DanhSach_VT[left].TENVT, DanhSach_VT[right].TENVT);
    		if(x>0)
    			swap(DanhSach_VT[left],DanhSach_VT[right]);
		 }
         else{
        	char pivot[83];
			strcpy(pivot, DanhSach_VT[right].TENVT);
        	int L=left-1;
        	for(int j=left; j<right;++j){
        		int y=strcmp(DanhSach_VT[j].TENVT,pivot);
        		if(y<=0){
        			L++;
        			swap(DanhSach_VT[j],DanhSach_VT[L]);
				}
			}
			swap(DanhSach_VT[L+1],DanhSach_VT[right]);
			Sort_DanhSachVatTu(DanhSach_VT, left, L);
			Sort_DanhSachVatTu(DanhSach_VT, L+2, right);	
	}
}
void swap(VatTu &a, VatTu &b){
	VatTu tam=a;
    a=b;
    b=tam;
}
int TimKiem_MaNV(DanhSachNV DSNhanVien, char s_Ma[]){
	for(int i=0; i < DSNhanVien.NumFact_NV; ++i){
		if(strcmp(DSNhanVien.DanhSachNhanVien[i]->MaNV, s_Ma)==0)
			return i;
	}
	return -1;
}
void ADD_nhanVienMoi(DanhSachNV &DSNhanVien, char MaNv[], char HoNv[], char TenNv[],char Phai[]){
	DSNhanVien.DanhSachNhanVien[DSNhanVien.NumFact_NV] = new NhanVien();
	strcpy(DSNhanVien.DanhSachNhanVien[DSNhanVien.NumFact_NV]->MaNV,MaNv);
	strcpy(DSNhanVien.DanhSachNhanVien[DSNhanVien.NumFact_NV]->Ho,HoNv);
	strcpy(DSNhanVien.DanhSachNhanVien[DSNhanVien.NumFact_NV]->Ten,TenNv);
	strcpy(DSNhanVien.DanhSachNhanVien[DSNhanVien.NumFact_NV]->Phai,Phai);
	DSNhanVien.DanhSachNhanVien[DSNhanVien.NumFact_NV]->First_DSHD=NULL;
	DSNhanVien.NumFact_NV++;
}
void Xoa_MotNhanVien(DanhSachNV &DSNhanVien, char s_Ma[]){	
	int t=TimKiem_MaNV(DSNhanVien, s_Ma);
	for(int i=t; i < DSNhanVien.NumFact_NV-1; ++i)
		*(DSNhanVien.DanhSachNhanVien[i])=*(DSNhanVien.DanhSachNhanVien[i+1]);
	DSNhanVien.NumFact_NV--;
	delete DSNhanVien.DanhSachNhanVien[DSNhanVien.NumFact_NV];
}
void Sort_dsNhanVien(DanhSachNV &DSNhanVien){
	for(int i=0; i < DSNhanVien.NumFact_NV-1;++i)
		for(int j=i+1;j<DSNhanVien.NumFact_NV;++j){
			int x=strcmp(DSNhanVien.DanhSachNhanVien[i]->Ten,DSNhanVien.DanhSachNhanVien[j]->Ten);
			if(x>0){
				NhanVien* tmp=DSNhanVien.DanhSachNhanVien[i];
				DSNhanVien.DanhSachNhanVien[i]=DSNhanVien.DanhSachNhanVien[j];
				DSNhanVien.DanhSachNhanVien[j]=tmp;
			}
			else{
				if(x==0){
					int y=strcmp(DSNhanVien.DanhSachNhanVien[i]->Ho,DSNhanVien.DanhSachNhanVien[j]->Ho);
					if(y>0){
						NhanVien* tmp=DSNhanVien.DanhSachNhanVien[i];
						DSNhanVien.DanhSachNhanVien[i]=DSNhanVien.DanhSachNhanVien[j];
						DSNhanVien.DanhSachNhanVien[j]=tmp;
					}	
				}
			}
		}	
}
void InFile_NhanVien(DanhSachNV &DSNhanVien){
	fstream inputFile;
	inputFile.open("NhanVien.txt", ios::in);
	char maNV[20];
	char ho[52];
	char ten[12];
	char phai[5];
	while(!inputFile.eof()){
		inputFile.getline(maNV, sizeof(maNV), '\n');
		if(strlen(maNV)==0) break;
		inputFile.getline(ho, sizeof(ho), '\n');
		inputFile.getline(ten, sizeof(ten), '\n');
		inputFile.getline(phai, sizeof(phai), '\n');
		ADD_nhanVienMoi(DSNhanVien,maNV,ho,ten,phai);		
	}
	inputFile.close();
}
void OutFile_NhanVien(DanhSachNV &DSNhanVien){
	fstream outputFile;
	outputFile.open("NhanVien.txt", ios::out);
	for (int i=0; i< DSNhanVien.NumFact_NV; i++ ){
		outputFile << DSNhanVien.DanhSachNhanVien[i]->MaNV << endl;
		outputFile << DSNhanVien.DanhSachNhanVien[i]->Ho << endl;
		outputFile << DSNhanVien.DanhSachNhanVien[i]->Ten << endl;
		outputFile << DSNhanVien.DanhSachNhanVien[i]->Phai << endl;
	}
	outputFile.close();
}
void TODAY(char ngay[], char thang[], char nam[]){
	time_t now = time(0);
	tm *ltm = localtime(&now);
	IntToChar(1900 + ltm->tm_year,nam);
	IntToChar(1+ ltm->tm_mon,thang);
	IntToChar(ltm->tm_mday,ngay);
}
HoaDon taoHoaDonmoi(char soHd[], char ngay[], char thang[], char nam[], char loai){
		HoaDon hoaDonmoi;
		strcpy(hoaDonmoi.SoHD, soHd);
		
		hoaDonmoi.NgayLap.ngay =CharToInt(ngay);
		hoaDonmoi.NgayLap.thang=CharToInt(thang);
		hoaDonmoi.NgayLap.nam  =CharToInt(nam);
		
		hoaDonmoi.Loai=loai;
		hoaDonmoi.trigia=0;
	return hoaDonmoi;
}
void ChenDau_MotHoaDon(NhanVien &nVien, HoaDon* HDtmp){
		Node_DSHoaDon *phanTuMoi = new Node_DSHoaDon();
		strcpy(phanTuMoi->HDon.SoHD,HDtmp->SoHD); // Gan gia tri (noi dung chinh) cho nod
		phanTuMoi->HDon.NgayLap=HDtmp->NgayLap;
		phanTuMoi->HDon.Loai=HDtmp->Loai;
		phanTuMoi->HDon.trigia=HDtmp->trigia;
		phanTuMoi->HDon.CTHD=new ChiTietHoaDon;
		*phanTuMoi->HDon.CTHD = *HDtmp->CTHD;
		phanTuMoi->next = NULL;
		if(nVien.First_DSHD == NULL)
			nVien.First_DSHD = phanTuMoi;
		else{
			phanTuMoi->next = nVien.First_DSHD;
			nVien.First_DSHD = phanTuMoi;
		}
}
bool TimKiem_SoHoaDon(DanhSachNV &DSNhanVien, char soHd[]){
	for(int i=0;i<DSNhanVien.NumFact_NV;++i){
		Node_DSHoaDon *nodeChay = DSNhanVien.DanhSachNhanVien[i]->First_DSHD;
		while(nodeChay!=NULL){
			int x=strcmp(nodeChay->HDon.SoHD, soHd);
			if(x==0){
				return true;
			}
			nodeChay=nodeChay->next;
		}
	}
	return false;	
}
PTR_HD TimKiem_NodeHoaDon(DanhSachNV &DSNhanVien, char soHd[]){
	for(int i=0;i<DSNhanVien.NumFact_NV;++i){
		Node_DSHoaDon *nodeChay = DSNhanVien.DanhSachNhanVien[i]->First_DSHD;
		while(nodeChay!=NULL){
			int x=strcmp(nodeChay->HDon.SoHD, soHd);
			if(x==0){
				return nodeChay;
			}
			nodeChay=nodeChay->next;
		}
	}
	return NULL;
}
int TimKiem_NhanVien_SoHD(DanhSachNV &DSNhanVien, char soHd[]){
	for(int i=0;i<DSNhanVien.NumFact_NV;++i){
		Node_DSHoaDon *nodeChay = DSNhanVien.DanhSachNhanVien[i]->First_DSHD;
		while(nodeChay!=NULL){
			int x=strcmp(nodeChay->HDon.SoHD, soHd);
			if(x==0){
				return i;
			}
			nodeChay=nodeChay->next;
		}
	}
	return -1;
}
int Return_STT_CTHD(int x_click, int begin, int khoangcach){
	return (x_click - begin)/khoangcach;
}
void Add_MotChiTietHoaDon(ChiTietHoaDon &CTHD, char mvt[], int soluong, int dongia, int vat){	
	strcpy(CTHD.CTHoaDon[CTHD.NumFact_CTHoaDon].MaVT,mvt);
	CTHD.CTHoaDon[CTHD.NumFact_CTHoaDon].SoLuong=soluong;
	CTHD.CTHoaDon[CTHD.NumFact_CTHoaDon].DonGia=dongia;
	CTHD.CTHoaDon[CTHD.NumFact_CTHoaDon].VAT=vat;
	CTHD.NumFact_CTHoaDon+=1;
}
void Delete_MotVatTu(ChiTietHoaDon &CTHD, int Vitri)
{	
	for (int i = Vitri; i < CTHD.NumFact_CTHoaDon-1 ; i++)
		CTHD.CTHoaDon[i] = CTHD.CTHoaDon[i+1];
	CTHD.NumFact_CTHoaDon--;
}
void DocFile_HoaDon(DanhSachNV &DSNhanVien,int& n_HoaDon){
	for(int i=0;i<DSNhanVien.NumFact_NV;i++){
		string s=string(DSNhanVien.DanhSachNhanVien[i]->MaNV) +".txt";
		FILE* file=fopen((char*)s.c_str(),"r");
		char tmpMa[13];
		int tmpSl;
		int tmpGia;
		int tmpVat;
		int num;
		HoaDon HDtmp;
		while(!feof(file)){
			fscanf(file,"%s %c %d/%d/%d %d \n",HDtmp.SoHD,&HDtmp.Loai,&HDtmp.NgayLap.ngay,&HDtmp.NgayLap.thang,&HDtmp.NgayLap.nam,&num);
			if(feof(file)) break;
			for(int j=0;j<num;j++){
				fscanf(file,"%s %d %d %d \n",tmpMa,&tmpSl,&tmpGia,&tmpVat);
				HDtmp.trigia+= (long long)tmpSl * (long long)tmpGia + (long long)tmpSl* (long long)tmpGia * (long long)tmpVat/100;
				Add_MotChiTietHoaDon(*HDtmp.CTHD, tmpMa, tmpSl, tmpGia, tmpVat);
			}
			ChenDau_MotHoaDon(*DSNhanVien.DanhSachNhanVien[i],&HDtmp);
			n_HoaDon++;
			HDtmp.trigia=0;
			HDtmp.CTHD->NumFact_CTHoaDon=0;	
		
		}
		fclose(file);
	}
}

void Ghi(PTR_HD tmp,FILE* &file){
	if(tmp==NULL) return;
	Ghi(tmp->next,file);
	fprintf(file,"%s %c %d/%d/%d %d \n",tmp->HDon.SoHD, tmp->HDon.Loai, tmp->HDon.NgayLap.ngay, tmp->HDon.NgayLap.thang, tmp->HDon.NgayLap.nam, tmp->HDon.CTHD->NumFact_CTHoaDon);
		for(int j=0;j<tmp->HDon.CTHD->NumFact_CTHoaDon;j++){
			fprintf(file,"%s %d %d %d \n",tmp->HDon.CTHD->CTHoaDon[j].MaVT, tmp->HDon.CTHD->CTHoaDon[j].SoLuong, tmp->HDon.CTHD->CTHoaDon[j].DonGia, tmp->HDon.CTHD->CTHoaDon[j].VAT);
		}
	
}
void GhiFile_HoaDon(DanhSachNV &DSNhanVien)	{
	for(int i=0;i<DSNhanVien.NumFact_NV;i++){
		string s=string(DSNhanVien.DanhSachNhanVien[i]->MaNV)+".txt";		
		FILE* file=fopen((char*)s.c_str(),"w");
		Ghi(DSNhanVien.DanhSachNhanVien[i]->First_DSHD,file);
		fclose(file);
	}
}
bool KTraMaVt_CTHD(ChiTietHoaDon &CTHD, char maVT[]){
	for (int i=0; i<CTHD.NumFact_CTHoaDon;i++)
		if (strcmp(CTHD.CTHoaDon[i].MaVT,maVT) == 0) return true;
	return false;
}
bool NamNhuan(int nam){
	if (( nam % 400 == 0) || (nam %4 ==0 && nam % 100 != 0)) return true;
	else return false;
}
bool SoSanhDMY(int ngay1, int thang1, int nam1, int ngay2, int thang2, int nam2){
	if (ngay1 == ngay2 && thang1 == thang2 && nam1 == nam2) return true;
	else if (nam2>nam1) return true;
	else if (nam2<nam1) return false;
	else if (thang2 > thang1) return true;
	else if (thang2 < thang1) return false;
	else if (ngay2 > ngay1) return true;
	else return false;
}
void Sort_DanhSachHoaDon(HoaDon arrHD[],string arrHoTen[], int left, int right){
    if (left>=right) return;
    else if(left+1==right){
    		if(arrHD[left].NgayLap.nam>arrHD[right].NgayLap.nam || (arrHD[left].NgayLap.nam==arrHD[right].NgayLap.nam && arrHD[left].NgayLap.thang>arrHD[right].NgayLap.thang) || (arrHD[left].NgayLap.nam==arrHD[right].NgayLap.nam && arrHD[left].NgayLap.thang==arrHD[right].NgayLap.thang && arrHD[left].NgayLap.ngay>arrHD[right].NgayLap.ngay))
    			{
    				HoaDon tam=arrHD[left];
    				arrHD[left]=arrHD[right];
    				arrHD[right]=tam;
    				///
    				string s1=arrHoTen[left];
    				arrHoTen[left]=arrHoTen[right];
    				arrHoTen[right]=s1;
				}
		 }
         else{
        	HoaDon pivot=arrHD[right];
        	int L=left-1;
        	for(int j=left; j<right;++j){
        		if(arrHD[j].NgayLap.nam<pivot.NgayLap.nam || (arrHD[j].NgayLap.nam==pivot.NgayLap.nam && arrHD[j].NgayLap.thang<pivot.NgayLap.thang) || (arrHD[j].NgayLap.nam==pivot.NgayLap.nam && arrHD[j].NgayLap.thang==pivot.NgayLap.thang && arrHD[j].NgayLap.ngay<=pivot.NgayLap.ngay))
				{
        			L++;
        			HoaDon tam=arrHD[j];
    				arrHD[j]=arrHD[L];
    				arrHD[L]=tam;
    				///
    				string s1=arrHoTen[j];
    				arrHoTen[j]=arrHoTen[L];
    				arrHoTen[L]=s1;
				}
			}
			HoaDon tam=arrHD[L+1];
    		arrHD[L+1]=arrHD[right];
    		arrHD[right]=tam;
    				///
    		string s1=arrHoTen[L+1];
    		arrHoTen[L+1]=arrHoTen[right];
    		arrHoTen[right]=s1;
			Sort_DanhSachHoaDon(arrHD,arrHoTen, left, L);
			Sort_DanhSachHoaDon(arrHD,arrHoTen, L+2, right);	
	}
}
///////////////////////////////////// TOP 10 ////////////////////////////////////////
void Nap_DanhSachMaVatTu(PTR_VT &p, string arrMa[], int &k){
	if(p != NULL){
		Nap_DanhSachMaVatTu(p->Trai, arrMa, k);
    	arrMa[k]=string(p->VT.MAVT);
    	k++;
    	Nap_DanhSachMaVatTu(p->Phai, arrMa, k);
   }
}
void them_TK_TOP(PTR_TK_TOP &p,string x,long long tt,PTR_VT vattu,int &k)
{
	if(p==NULL)
	{
		PTR_TK_TOP q = new TK_TOP;
		q->data=x;
		q->tt=tt;
		q->pTrai=NULL;
		q->pPhai=NULL;
		q->vattu=vattu;
		p=q;
		k++;
	}
	else
	{
		if(p->data > x)
			them_TK_TOP(p->pTrai,x,tt,vattu,k);
		else if(p->data < x)
			them_TK_TOP(p->pPhai,x,tt,vattu,k);
		else
		{
			p->tt+=tt;
		}
	}
}

void LNR(PTR_TK_TOP p,PTR_TK_TOP arr[],int &n)
{
	if(p!=NULL)
	{
		LNR(p->pTrai,arr,n);
		arr[n]=p;
		n++;
		LNR(p->pPhai,arr,n);
	}
}

void Heap(int r,int n,PTR_TK_TOP a[])
{
	int k= 2*r+1;
	PTR_TK_TOP temp= a[r];
	bool check= true;
	while(k <= n-1 && check)
	{
		if(k<n-1)
			if(a[k]->tt < a[k+1]->tt)
				k++;
		if(a[k]->tt <= temp->tt) check=false;
		else
		{
			a[r]=a[k];
			a[k]=temp;
			r=k;
			k=2*r+1;
		}
		
	}
}

void Heap_Sort(PTR_TK_TOP a[],int n,int x)
{
	PTR_TK_TOP temp;
	for(int i=n/2-1;i>=0;i--)	
		Heap(i,n,a);
	for(int i=n-2,j=0;i>=0&&j<x;i--,j++)
	{
		temp=a[0];
		a[0]=a[i+1];
		a[i+1]=temp;
		Heap(0,i+1,a);
	}
}
