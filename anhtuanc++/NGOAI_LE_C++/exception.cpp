// #include<iostream>
// using namespace std;
// // int main()
// // {
// //     int a, b, c;
// //   do
// //   {
// //     cout << "nhap a = " ;
// //     cin >> a;
// //     cout << "nhap b = ";
// //     cin >> b;
// //        try 
// //         {
// //             if (b == 0)
// //                 throw string("nhap lai di") ;
// //             else 
// //             {
// //                 c = a / b;
// //                 cout << "c =" << c << endl;
// //             }
           
// //         }

// //     catch(string e)
// //     {
// //         cout << e << endl;
// //     }

// //     // catch (double e) 
// //     // {
// //     //     cout << e << endl;
// //     // }

// //     /*catch (point e) 
// //     {
// //         cout << e << endl;
// //     }*/
// //   }
// //   while( b == 0);
    
// //     return 0;
// // }

// //BUOI 2
// //chuyển tiếp ngoại lệ
// //tu dong chuyen tiep try catch
// void Chia(int& a, int& b)
// {
//     //khong co try catch
//     // if(b == 0)
//     // throw string("ngu lam");
//     // else
//     //  cout << a/b << endl;

//     //co try catch
//     try
//     {
//         if (b == 0)
//         throw string("ngu lam");
//         else cout << a/b << endl;
//     }
//     catch(string e)
//     {
//         cout << "chia -" << e << endl;
//         throw;//chuyen tiep ngoai le thu cong, chuyen len ham cao hon goi den ham Chia()
//     }
    
// }

// void TT(int& a, int& b)
// {
//     //khong co try catch
//     //  Chia(a,b);

//     //co try catch
//     try
//     {
//         Chia(a,b);
//     }
//     catch(string  e)
//     {
//         cout << "TT- " << e << endl;
//         throw;//nhu tren
//     }
    
// }

// int main()
// {
//     int a = 5, b = 0;
//     //khong co try catch
//     Chia(a,b);
     
//     // co try catch

//     // try
//     // {
//     //     TT(a,b);
//     // }
//     // catch(string e)
//     // {
//     //     cout << "main -" << e << endl;
//     // }

//     return 0;
    

// }

//mot so luu y

#include<iostream>
using namespace std;

void Chia(int& a, int& b)
{
    try
    {
        if (b==0)
            throw invalid_argument("truyen ngu");//invalid_argument: bien ngoai le 
        else
            cout << a/b << endl; 
        
    }
    catch(invalid_argument& e)
    {
        cout << e.what() << endl;//.what(): ham cho phep goi ra masseg ngoai le duoc truyen
    }
    
}


int main()
{
    int x = 5, y = 0;
    Chia(x, y);

    return 0;
}