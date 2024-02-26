#include<iostream>
#include "myexp.h"
// #include "EXP.h"
using namespace std;

void Chia(int& a, int& b)
{

    try
    {
        if (b == 0)
        throw myexp("ngu lam", 1);
    else 
        cout << a/b << endl;
    }
    catch(myexp& e)
    {
        cout << "chiacon -" << e << endl;
        throw e;//chuyen tiep nguyen ve ngoai le thu cong theo bien "e" thuoc kieu duoc dinh nghia trong ham
        //nếu chỉ là "throw;" thì nó chuyển tiếp nguyên vẹn ngoại lệ được tạo ở "try"
    }   
    
    catch (EXP& e)
    {
        cout << "chia -" << e << endl;
        throw;
       
    }

}

void TT(int& a, int& b)
{
    
    try
    {
        Chia(a,b);
    }
    catch(myexp& e)
    {
        cout << "TTcon- " << e << endl;
        throw;
    }
    catch(EXP& e)
    {
        cout << "TT -" << e << endl;
        throw;
       
    }
    
}

int main()
{
    int a = 5, b = 0;
    //khong co try catch
    // Chia(a,b);
     
    // co try catch

    try
    {
        TT(a,b);
    }
     catch(myexp& e)
    {
        cout << "maincon -" << e << endl;
    }
    catch(EXP& e)
    {
        cout << "main -" << e << endl;
    }

    return 0;
    

}
//mot so luu y


