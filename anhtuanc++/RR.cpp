#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

void findWaitingTime(vector<int>& arrivalTime, vector<int>& burstTime, vector<int>& waitingTime, int quantum) {
    int n = arrivalTime.size();
    vector<int> remainingTime(n);

    for (int i = 0; i < n; i++) {
        remainingTime[i] = burstTime[i];
    }

    int currentTime = 0;

    while (true) {
        bool done = true;

        for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0 && arrivalTime[i] <= currentTime) {
                done = false;

                if (remainingTime[i] > quantum) {
                    currentTime += quantum;
                    remainingTime[i] -= quantum;
                } else {
                    currentTime += remainingTime[i];
                    waitingTime[i] = currentTime - burstTime[i] - arrivalTime[i];
                    remainingTime[i] = 0;
                }
            }
        }

        if (done) break;
    }
}

void findTurnAroundTime(vector<int>& burstTime, vector<int>& waitingTime, vector<int>& turnAroundTime) {
    int n = burstTime.size();
    for (int i = 0; i < n; i++) {
        turnAroundTime[i] = burstTime[i] + waitingTime[i];
    }
}

void findavgTime(vector<int>& arrivalTime, vector<int>& burstTime, int quantum) {
    int n = arrivalTime.size();
    vector<int> waitingTime(n, 0);
    vector<int> turnAroundTime(n, 0);

    findWaitingTime(arrivalTime, burstTime, waitingTime, quantum);
    findTurnAroundTime(burstTime, waitingTime, turnAroundTime);

    cout << "Processes\tBurst time\tWaiting time\tTurn around time\n";

    int total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += waitingTime[i];
        total_tat += turnAroundTime[i];
        cout << i + 1 << "\t\t" << burstTime[i] << "\t\t" << waitingTime[i] << "\t\t" << turnAroundTime[i] << endl;
    }
    cout << "Average waiting time = " << (double)total_wt / n << endl;
    cout << "Average turn around time = " << (double)total_tat / n << endl;
}

int main() {
    int n;
    cout << "Nhap so tien trinh: ";
    cin >> n;

    vector<int> arrivalTime(n);
    vector<int> burstTime(n);

    cout << "Nhap burst_time va arrival_time:\n";
    for (int i = 0; i < n; i++) {
        cin >> burstTime[i] >> arrivalTime[i];
    }

    int time_slice;
    cout << "Nhap thoi gian time_slice: ";
    cin >> time_slice;

    findavgTime(arrivalTime, burstTime, time_slice);
    system("pause");
    return 0;
}
