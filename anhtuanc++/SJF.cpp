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

    system("pause");
    return 0;
}