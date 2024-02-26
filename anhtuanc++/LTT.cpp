#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> 
//#include <random>

using namespace std;
int Det(int matrix[100][100], int N) {
    int det = 0; // Biến chứa giá trị định thức
    {
        for (int k = 0; k < N; k++) {
            int submatrix[100][100];
            for (int i = 1; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (j < k) {
                        submatrix[i - 1][j] = matrix[i][j];
                    } else if (j > k) {
                        submatrix[i - 1][j - 1] = matrix[i][j];
                    }
                }
            }
            det += (k % 2 == 0 ? 1 : -1) * matrix[0][k] * Det(submatrix, N);
        }
    }

    return det;
}

int main() {
    int k, n;
    cout << "nhap k, n: ";
    cin >> k >> n;

    int A[100][100];
    int B[100][100];
    int C[100][100];
    int E[100];
    int y[100];
    int Y[100];
    srand(time(0));
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            A[i][j] = rand() % 2;
        }
    }
    cout << "ma tran sinh G" << endl;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                B[i][j] = 1;
            }
            else
            {
                B[i][j] = 0;
            }
        }
    }
    cout << "ma tran hoan vi P" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
do {
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            C[i][j] = rand() % 2;
        }
    }
} while(Det(C, k) != 0);

cout << "Ma tran kha nghich" << endl;
for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }


    system("pause");
    return 0;
}
