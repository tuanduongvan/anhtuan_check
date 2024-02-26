#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

struct Process {
    string name;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;

    Process(string n, int at, int bt) : name(n), arrival_time(at), burst_time(bt), remaining_time(bt), waiting_time(0), turnaround_time(0) {}
};

struct CompareProcess {
    bool operator()(const Process& p1, const Process& p2) const {
        return p1.remaining_time > p2.remaining_time;
    }
};

int main() {
    int n;
    cout << "Nhap so tien trinh: ";
    cin >> n;

    vector<Process> processes;
    for (int i = 0; i < n; ++i) {
        string name;
        int arrival_time, burst_time;
        cout << "Tien trinh  " << i + 1 << endl;
        cout << "Nhap arrival time va burst time: ";
        cin >> arrival_time >> burst_time;
        processes.push_back(Process(name, arrival_time, burst_time));
    }

    sort(processes.begin(), processes.end(), [](const Process& p1, const Process& p2) {
        return p1.arrival_time < p2.arrival_time;
    });

    int current_time = 0;
    priority_queue<Process, vector<Process>, CompareProcess> process_queue;

    double total_waiting_time = 0;
    double total_turnaround_time = 0;

    int i = 0;
    while (i < n || !process_queue.empty()) {
        while (i < n && processes[i].arrival_time <= current_time) {
            process_queue.push(processes[i]);
            i++;
        }

        if (!process_queue.empty()) {
            Process current_process = process_queue.top();
            process_queue.pop();
            current_time += 1;
            current_process.remaining_time -= 1;

            if (current_process.remaining_time == 0) {
                current_process.turnaround_time = current_time - current_process.arrival_time;
                current_process.waiting_time = current_process.turnaround_time - current_process.burst_time;
                total_waiting_time += current_process.waiting_time;
                total_turnaround_time += current_process.turnaround_time;
            } else {
                process_queue.push(current_process);
            }
        } else {
            current_time = processes[i].arrival_time;
        }
    }

    double avg_waiting_time = total_waiting_time / n;
    double avg_turnaround_time = total_turnaround_time / n;

    cout << "Avg Waiting Time: " << avg_waiting_time << endl;
    cout << "Avg Turnaround Time: " << avg_turnaround_time << endl;

    return 0;
}
