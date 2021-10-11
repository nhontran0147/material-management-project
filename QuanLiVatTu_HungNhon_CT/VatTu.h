struct VatTu{
	char MAVT[10];
	char TENVT[50];
	char DVT[23];
	int SLT;
};
struct Node_VatTu{
	VatTu VT;
	Node_VatTu* Trai;
	Node_VatTu* Phai;
};

