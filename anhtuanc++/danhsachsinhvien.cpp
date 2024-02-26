#include<iostream>
#include<string>
using namespace std;


class SinhVien{
    private:
        string ma, hoten, lop, email;
    public:
        SinhVien(){
            ma = "";
            hoten = "";
            lop = "";
            email = "";
        }
        string getlop(){
            return lop; 
        }
        string getma(){
            return ma;
        }
        // void sethoten(string hoten){
        //     this-> hoten = hoten;
        // }
        friend istream& operator >> (istream& is, SinhVien& a);
        friend ostream& operator << (ostream& os,const  SinhVien& a);
};

istream& operator >> (istream& is, SinhVien& a){
    getline(is, a.ma);
    if(a.ma == "") return is;
    getline(is, a.hoten);
    getline(is, a.lop);
    getline(is, a.email);
    return is;
}

ostream& operator << (ostream& os, const SinhVien& a){
    os << a.ma << " " << a.hoten << " " << a.lop << " " << a.email << endl;
    return os;
    }

int main(){
    int n;
    SinhVien a[1000];
    cin.ignore();
    // for (int i = 1; i <= 1000; i ++){
    //     cin >> a[i];
    //     if (a[i].getma() == ""){
    //         n = i - 1;
    //         break;
    //         }
    //     }
    int i = 0;
    while (cin >> a[i]){
         if (a[i].getma() == ""){
            n = i;
            break;
         }
         i ++;

    }
    for (int i = 0; i <= n; i++){
        int min = i;
        for(int j = i + 1; j <= n; j++){
            if(a[min].getlop().compare(a[j].getlop()) == 1){
                min = j;
            } 
            else if(a[min].getlop().compare(a[j].getlop()) == 0){
                if(a[min].getma().compare(a[j].getma()) == 1)
                min = j;
            } 
            swap(a[i], a[min]);
        }
    }
    for (int i = 0; i <= n; i ++){
        cout << a[i] << endl;
    }
    system("pause");
    return 0;
    string parent = "abcgdfjdhfdhff";
    string child = "jdhf";
    // for (int i = 0; i < parent.length(); i++){
    //     int j = 0;
    //     for (j = 0; j < child.length(); j ++){
    //         if(parent[i + j] == child[j])
    //         continue;
    //         else break;
    //     }
    // }
    for(int i = 0; i < parent.length(); i ++){
        if(parent[i] == child[0]){
            for(int j = 0; j < child.length(); j++){
                if(parent[i + j] == child[j])
                continue;
                else break;
            }
        }
    }

}
// B16DCCN011
// Nguyen Trong Duc Anh
// D16CNPM1
// sv1@stu.ptit.edu.vn
// B15DCCN215
// To Ngoc Hieu
// D15CNPM3
// sv2@stu.ptit.edu.vn
// B15DCKT150
// Nguyen Ngoc Son
// D15CQKT02-B
// sv3@stu.ptit.edu.vn
// B15DCKT199
// Nguyen Trong Tung
// D15CQKT03-B
// sv4@stu.ptit.edu.vn

