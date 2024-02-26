#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Process {
    int arrivalTime;
    int burstTime;
    int priority;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
};

bool comparePriority(Process p1, Process p2) {
    return p1.priority < p2.priority;
}

int main() {
    int n;
    cout << "Nhap so tien trinh: ";
    cin >> n;

    vector<Process> processes(n);
    for(int i = 0; i < n; i++) {
        cout << "Nhap burst_time, arrival_time va priority: " << i+1 << ": ";
        cin >> processes[i].burstTime >> processes[i].arrivalTime >> processes[i].priority;
    }

    sort(processes.begin(), processes.end(), comparePriority);

    processes[0].completionTime = processes[0].arrivalTime + processes[0].burstTime;
    processes[0].turnaroundTime = processes[0].completionTime - processes[0].arrivalTime;
    processes[0].waitingTime = processes[0].turnaroundTime - processes[0].burstTime;

    for(int i = 1; i < n; i++) {
        processes[i].completionTime = processes[i-1].completionTime + processes[i].burstTime;
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
    }

    double avgWaitingTime = 0, avgTurnaroundTime = 0;
    for(int i = 0; i < n; i++) {
        avgWaitingTime += processes[i].waitingTime;
        avgTurnaroundTime += processes[i].turnaroundTime;
    }

    avgWaitingTime /= n;
    avgTurnaroundTime /= n;

    cout << "Avg waiting time: " << avgWaitingTime << endl;
    cout << "Avg turnaround time: " << avgTurnaroundTime << endl;

    system("pause");
    return 0;
}
