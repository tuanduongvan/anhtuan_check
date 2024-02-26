#include<iostream>
using namespace std;

class pheptinh {
protected:
	int sn1, sn2;
public:
	pheptinh() {
		sn1 = 10;
		sn2 = 5;
	}
	virtual int calculate() = 0;
};

class Cong : public pheptinh {
private:
public:
	Cong() : pheptinh(){}
	int calculate() override {
		return sn1 + sn2;
	}
};

class Tru : public pheptinh {
private:
public:
	Tru() : pheptinh(){}
	int calculate() override {
		return sn1 - sn2;
	}
};

// class NhanVien {
// public:
// 	virtual int calLuong() {
// 		return 0;
// 	}
// 	int tinhLuong() {
// 		return 0;
// 	}
// };

// class NhanVienKiThuat : public NhanVien {
// public:
// 	int calLuong() override {
// 		return 1000;
// 	}
// 	int tinhLuong() {
// 		return 1000;
// 	}
// };


int main() {
	Cong cong;
	// pheptinh* object;
	// object = new Cong();
	cout << "tong : ";
	cout << cong.calculate() << endl;
	// cout << "tru: ";
	// object = new Tru();
	// cout << object->calculate() << endl;
	// NhanVien* ob = new NhanVien();
	// cout << "tinh luong: " << ob->tinhLuong() << endl;
	// ob = new NhanVienKiThuat();
	// cout << "tinh luong: " << ob->tinhLuong();
	system("pause");
	return 0;

}
