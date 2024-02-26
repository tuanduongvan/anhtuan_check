#include<iostream>
#include<vector>
#include<map>
//học hai cái này là ok rồi vector, với map
//ngoài ra còn nhiều as: set, unordered_set, map, unordered_map, uk chứ giống tạo ra làm đéo gì
using namespace std;

int main()
{
//     vector<pair<string, string>> list;
//     list.push_back({"M01", "Go Xanh"});
//     list.push_back({"M02", "Hoa Phat"});
    // // //để truy suất này
    // // //cách 1
    // // //trong pair<string, string> heey : thi it bên dưới đại diện cho pair<string, string> ok
    // // //thì để truy suất đến thằng đầu tiên là it.first, còn thứ hai là it.second ok
    // // //ok thằng cha điên ni
    // // //đang nói một phần tử trong list ok : là pair<>
    // for(auto it : list){
    //     cout << it.first << " : " << it.second << endl; //chạy là hiểu ngay
    // }

    // for(pair<string, string> it : list){
    //     cout << it.first << " : " << it.second << endl; 
    // }

    //thì làm bình thường thôi
    //lấy được giá trị rồi mà sợ ko so sánh được
    //ex
//

    vector<pair<string, string>> list;
    list.push_back({"M01", "Go Xanh"});
    list.push_back({"M02", "Hoa Phat"});
    string ID = "M01";
    
    // //kiểm tra xem ID này có trong list ko validation
    bool check = false;
    for(auto it : list){
        if(it.first.compare(ID) == 0){
            check = true;
        }
    }

    cout << check << endl; //1: true, 0 false

    // //cách thứ hai
    // //đr
    // //cách hai
    // for(int i = 0; i < list.size(); i++){
    //     cout << list[i].first << " : " << list[i].second << endl;
    // }
    //từ từ tí gửi, tí gửi hết luôn
    map<string, string> mp;
    mp["M01"] = "Go Xang";
    mp["M02"] = "Hoa Phat";
    for(auto it : mp){
        cout << it.first << " : " << it.second << endl;
    }
    cout << "========================\n";
    // //nếu không dùng auto thì mình dùng pair như này
    // for(pair<string, string> it : mp){
    //     cout << it.first << " : " << it.second << endl;
    // }
    //tứ là mình biết chính xác trong mp đang quản lí các pair
    system("pause");
}

/*
    hiểu vấn đề chưa
    ok chuwa
    kieeu vay
    ee hieeu chua
    hieeur chua cha nhanh
    auto thực chất là nó tự nhận biết để định dạng kiểu dữ liệu: tự nhận lịnh động, mình khỏi phải chỉ
    cụ thể kiểu dữ liệu là gì
*/
