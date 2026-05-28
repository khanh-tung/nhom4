#include<iostream>

using namespace std;

class MaTran{
	private:
		int n, m;
		int a[10][10];
	public:
		void nhap(){
			do{
				cout << "Nhap so hang: "; cin >> n;
				cout << "Nhap so cot: "; cin >> m;
			}
			while(n<=0 || m<=0);
			for(int i=0; i<n; i++)
			for(int j=0; j<m; j++){
				cout << "Nhap phan tu " << i << "," << j << ": ";
				cin >> a[i][j];
			}
		}
		void xuat(){
			for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cout << a[i][j] << "\t";
			}
			cout << endl;
			}
		}
		int getn(){
			return n;
		}
		int getm(){
			return m;
		}
		int geta(int i, int j){
			return a[i][j];
		}
		friend void congmt(MaTran mt1, MaTran mt2);
};

void congmt(MaTran mt1, MaTran mt2){
	int tong = 0;
	MaTran kq;
	if (mt1.n == mt2.n && mt1.m == mt2.m){
		kq.n = mt1.n;
		kq.m = mt1.m;
		for(int i=0; i<kq.n; i++)
		for(int j=0; j<kq.m; j++){
			kq.a[i][j] = mt1.a[i][j] + mt2.a[i][j] ;
		}
		kq.xuat();
	}
	else
		cout << "Khong dong cap" << endl;
}

void tongvien(MaTran mt){
	int tong = 0;
	for(int i=0; i<mt.getn(); i++){
		tong += mt.geta(i,0);
		tong += mt.geta(i, mt.getm()-1);
	}
	for(int j=1; j<mt.getm()-1; j++){
		tong += mt.geta(0,j);
		tong += mt.geta(mt.getn()-1, j);
	}
	cout << "\nTong phan tu tren 4 duong vien cua ma tran = " << tong << endl;
}

int main(){
	MaTran a,b;
	cout  << "Nhap ma tran a" << endl;
	a.nhap();
	cout << "Xuat ma tran" << endl;
	a.xuat();
	tongvien(a);
	cout  << "Nhap ma tran b" << endl;
	b.nhap();
	cout << "Xuat ma tran" << endl;
	b.xuat();
	cout << "Tong hai ma tran" << endl;
	congmt(a, b);
	
	return 0;
}
