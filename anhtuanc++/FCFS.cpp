// #include<iostream>
// #include<iomanip>

// using namespace std;


// void  FCFS(int n)
// {
//     int S = 0;
//     int i, j;
//     int p[10],at[10], wt[10], tt[10];
//     double avgwt, avgtt;
//     cout << "nhap thoi gian cua moi tien trinh," << endl;
//     cout << "thoi gian den" << endl;
//     for ( i = 0; i < n; i ++)
//     {
//         cout << endl << "p[" << i << "],"<< "st[" << i << "]:";
//         cin >> p[i] >> at[i];
//     }
//     wt[0] = 0;
//     for ( i = 1; i < n; i ++)
//     {
//         wt[i] = 0;
//         for ( j = 0; j < i; j++)
//         {
//             wt[i] += p[j];
//         }
//         wt[i] = wt[i] - at[i];
//     }

//     for ( i = 0; i < n; i++)
//     {
//         tt[i] = wt[i] + p[i];
//     }
//     for( i = 0; i < n; i++)
//     {
//         S += wt[i]; 
//     }
//     avgwt =(double) S/n;//không ép kiểu ở đây á 
//     S = 0;                          
//     for( i = 0; i < n; i++)
//     {
//         S += tt[i]; 
//     }
//     avgtt = (double)S/n;//đây nữa
//     cout << "tien trinh" << "\tservice time" << "\tarrival time" << "\twaitting time" << "\tturnaround time" << endl;
//     for ( i = 0; i < n; i ++)
//     {
//         cout << "p[" << i << "]" << "\t\t" << p[i] << "\t\t" << at[i] << "\t\t" << wt[i] << "\t\t" << tt[i] << endl; 
//     }
//     cout << setiosflags(ios::showpoint) << setprecision(3);
//     cout << "AVG waitting time:" << endl; 
//     cout << fixed << setprecision(2) << avgwt << endl;
//     cout << "AVG turnaround time:" << endl;
//     cout << fixed << setprecision(2) << avgtt << endl;


// }

// int main()
// {
//     int n;
//     int S = 0;
//     int p[10], at[10], wt[10], tt[10];
//     float avgwt, avgtt;
//     cout << "nhap so tien trinh(max = 10): " ; cin >> n;
//     FCFS(n);

//     system("pause");

//     return 0;

// }


//SJF

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

bool compareAT(const Process& a, const Process& b) {
    return a.arrival_time < b.arrival_time;
}

bool compareBT(const Process& a, const Process& b) {
    return a.burst_time < b.burst_time;
}

int main() {
    int n;
    cout << "Nhap so tien trinh: ";
    cin >> n;

    vector<Process> processes(n);

    cout << "Nhap Arrival_time va Burst_time :\n";
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cout << "P " << processes[i].id << " - Burst_Time: ";
        cin >> processes[i].burst_time;
        cout << "P " << processes[i].id << " - Arrival_Time: ";
        cin >> processes[i].arrival_time;
    }

    sort(processes.begin(), processes.end(), compareAT);

    int current_time = 0;
    double total_waiting_time = 0;
    double total_turnaround_time = 0;
    cout << "Process\tArrival_Time\tBurst_Time\tWaiting_Time\tTurnaround_Time\n";

    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        processes[i].waiting_time = current_time - processes[i].arrival_time;

        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;

        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;

        cout << "P" << processes[i].id << "\t" << processes[i].arrival_time << "\t\t"
                  << processes[i].burst_time << "\t\t" << processes[i].waiting_time << "\t\t"
                  << processes[i].turnaround_time << endl;

        current_time += processes[i].burst_time;
    }

    double avg_waiting_time = total_waiting_time / n;
    double avg_turnaround_time = total_turnaround_time / n;

    cout << "Average Waiting Time: " << avg_waiting_time << std::endl;
    cout << "Average Turnaround Time: " << avg_turnaround_time << std::endl;

    return 0;
}
