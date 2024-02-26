#include<iostream>
#include<iomanip>
using namespace std;

// // void A(){
// //     int x = 3;// bien cuc bo dong: ham ket thuc vung nho bi giai phong
// //     static int y = 4;//bien cuc bo tinh: khong bi thu hoi sau khi loi goi ham ket thuc
// //     x ++;
// //     y ++;
// //     cout << x << "," << y << endl;
// // }
// // int main(){
// //     A(); //4 , 5
// //     A(); // 4, 6
// //     int x;
// //     double y;
// //     x = int(y);// ep kieu trong c++

// //     enum hangso
// //      { //liet ke cac phan tu co gia tri la hang so, mac dinh voi kieu du lieu la (int)
// //         pi = 3,
// //         e = 2
// //     };
// //     hangso a = pi;
// //     cout << a;
// //     return 0;
// //    /* int x = 1; 
// //     cout << "input" ;
// //     cin >> x;
// //     cout << "x + 1 =" << x + 1;
// //     double x = 1.2345;
// //     cout << setiosflags(ios::showpoint) << setprecision(3);
// //     cout << x << endl;
// //     */
// //    int x = 1;
// //    int &y = x;
   


// // }


// // buoi 2

 int main (){
// // hằng tham chiếu
    int x = 2;
    // const int y = 3;
    // const int &z1 = y;
    // z1 = 10;
    // cout << y << "," << z1 << endl;// loi
    const int &z2 = x;
    x =  10;
    cout << x << "," << z2 << endl;

//     const int& z3 = 3;
//     //cout << z3 << endl;
//     system ("pause");
//     return 0;

// //doi so mac dinh
//  void show(int x, int y = 2, int z = 3)
//  {
//     cout << x << y << z << endl;
    system("pause");

 }
// int main(){
//     show(); //error
//     show(1); //123
//     show(1,3); //133
//     show(2,3,4); // 2,3,4
//     show(1, ,2), //error
// }

// // so sanh ham hang va ham tra ve hang tham chieu: const int A() vs int A() const;
// // con tro
// int x = 5;
// int* p = &x;
// cout << "&x = " << &x << endl;
// cout << p << endl;
// cout << "*p = " << *p << "x = " << x << endl;
// cout << "&p = " << &p << endl;// in ra dia chi luu con tro p trong bo nho HEAP (p != &p)
// // vidu
// //con tro hang: const int *p = &x;->khong cho phep thay doi gia tri, nhung co the tro toi cac vung nho khac nhau
// // hang con tro: int* const p; -> khong cho phep thay doi vung nho (da tro toi vung nho nao roi thi khong the thay doi duoc), nhung co the thay doi gia tri vung nho tro toi
// // const_cast : loai bo thuoc tinh hang ra khoi mot bien
// void show(char* str){
//     cout << str;
// }
// int main(){
//     const char *str = "dut";
//     show(str); // error
//     show(const_cast<char>(str));
//     return 0;
// }
// // con trỏ va mảng
// int main(){
//     int a[]= {2, 4, 6, 8};
//     int *p =  a;// con trỏ p trỏ tới địa chỉ của mảng
//     //khi đó: p <=> &a[0] <=> &p[0]
//     //hoặc: a[i] <=> p[i] <=> *(p + i)
//     // &a[i] = (p + i);
//   }
// int main(){
//     int A[] = {1, 2, 3, 4, 5};
//     int* p = A;
//     p += 2;
//     cout << *p; //*p = A[2] = 3
//     p--;
//     cout << *p; // *p = A[1] = 2
//     *p++;
//     cout << *p;// *p = A[1] = 3;
//     return 0;

// // mảng hai chiều
// int A[2][3] = {1, 2, 3, 4, 5, 6};
// cout << A << " ," << endl; 

// //con trỏ hàm

// int sum(int a, int b){
//     return a + b;
// }

// int sub(int a, int b){
//     return a - b;
// }
// int TT (int a, int b, int(*cmp)(int , int)){
//     return (*cmp)(a,b);
// }
// int main(){
//     int (*p)(int, int);
//     p = sum;
//     cout << sum(a, b) << "," <<(*p)(a, b) << endl;
//     cout << TT(a, b, p) << ", " << TT(a, b, sub);
//     return 0;

// // sắp xếp theo thứ tự tăng dần
// void sort(int *p, int a){
//     int i, j;
//     p = new int[a];
//     for (i = 0; i < n; i ++){
//         min = p[i];
//         for (j = i + 1; j < n; j ++)
//         {
//             if (p[j] < min ){
//                 min = p[j];
//             } 
//         }
//         if (min =! p[i]) 
//         swap(min, p[i]);
//     }
// }

// // con trỏ hàm
// bool tangdan(int a, int b){
//     return a > b;
// }

// bool giamdan(int a, int b){
//     return a < b;
// }
// void sort(int *p, int n, bool (*cmp)(int, int) = tangdan)
// {
//     for(int i = 0 ; i < n; i ++)
//         {
//             for(int j = i + 1; j < n; j++)
//             {
//                 if ((*cmp)(*(p + i), *(p + j)))
//                 {
//                     swap(*(p + i), *(p + j));
//                 }
//             }
//         }
// }
// }

// //cấp phát động cho mảng
// void input(int *p, int &n)
// {
//     cin >> n;
//     p = new int [n];
//     //khoi tao gia tri cua mang
// }

// void show(int *p, int n)
// {
//     for (int i = 0; i < n: i++)
//     {

//     }
// }

// int main()
// {
//     int n;
//     int *p = new int[n];
//     input(p, n);
//     show(p, n);
// }


// //cấp phát động cho mảng hai chiều
// int main()
// {
//     int row, col;
//     cout << "row = ";
//     cin >> row;
//     cout << "col = ";
//     cin >> col;
//     int **p = new int*[row];
//     for (int i = 0; i < row; i++)
//     {
//         *(p + i) = new int[col];
//         for (int j = 0; j < col; j++)
//         {
//             *(*(p + i) + j) = 3;

//         }
//     }
//     for (int i = 0; i < row; i++)
//     {
//         for(int j = 0; j < col; j++)
//         {
//             cout <<*(*(p + i) + j) << " ";
//         }
//         cout << endl;
//     }
//     for(int i = 0; i < row; i++)
//     {
//         delete[] *(p + i);
//     }
//     delete[] p;
//     return 0;
// }




// }
// #include<iostream>
// #include<vector>
// #include<map>
// //học hai cái này là ok rồi vector, với map
// //ngoài ra còn nhiều as: set, unordered_set, map, unordered_map, uk chứ giống tạo ra làm đéo gì
// using namespace std;

// int main(){
//     // vector<pair<string, string>> list;
//     // list.push_back({"M01", "Go Xanh"});
//     // list.push_back({"M02", "Hoa Phat"});
//     // //để truy suất này
//     // //cách 1
//     // //trong pair<string, string> heey : thi it bên dưới đại diện cho pair<string, string> ok
//     // //thì để truy suất đến thằng đầu tiên là it.first, còn thứ hai là it.second ok
//     // //ok thằng cha điên ni
//     // //đang nói một phần tử trong list ok : là pair<>
//     // for(auto it : list){
//     //     cout << it.first << " : " << it.second << endl; //chạy là hiểu ngay
//     // }

//     // for(pair<string, string> it : list){
//     //     cout << it.first << " : " << it.second << endl; //chạy là hiểu ngay
//     // }

//     //thì làm bình thường thôi
//     //lấy được giá trị rồi mà sợ ko so sánh được
//     //ex

//     vector<pair<string, string>> list;
//     list.push_back({"M01", "Go Xanh"});
//     list.push_back({"M02", "Hoa Phat"});
//     string ID = "M01";
    
//     //kiểm tra xem ID này có trong list ko validation
//     bool check = false;
//     for(auto it : list){
//         if(it.first.compare(ID) == 0){
//             check = true;
//         }
//     }

//     cout << check << endl; //1: true, 0 false

//     // //cách thứ hai
//     // //đr
//     // //cách hai
//     // for(int i = 0; i < list.size(); i++){
//     //     cout << list[i].first << " : " << list[i].second << endl;
//     // }
//     //từ từ tí gửi, tí gửi hết luôn
//     // map<string, string> mp;
//     // mp["M01"] = "Go Xang";
//     // mp["M02"] = "Hoa Phat";
//     // for(auto it : mp){
//     //     cout << it.first << " : " << it.second << endl;
//     // }
//     // cout << "========================\n";
//     // //nếu không dùng auto thì mình dùng pair như này
//     // for(pair<string, string> it : mp){
//     //     cout << it.first << " : " << it.second << endl;
//     // }
//     //tứ là mình biết chính xác trong mp đang quản lí các pair
//     system("pause");
// }

// /*
//     hiểu vấn đề chưa
//     ok chuwa
//     kieeu vay
//     ee hieeu chua
//     hieeur chua cha nhanh
//     auto thực chất là nó tự nhận biết để định dạng kiểu dữ liệu: tự nhận lịnh động, mình khỏi phải chỉ
//     cụ thể kiểu dữ liệu là gì
// */










 


 