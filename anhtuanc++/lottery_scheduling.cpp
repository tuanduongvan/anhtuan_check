#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

struct Process {
    int id;
    int arrival_time;
    int execution_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};

void lottery_scheduling(std::vector<Process>& processes) {
    int total_tickets = 0;
    for (const Process& p : processes) {
        total_tickets += p.priority;
    }

    srand(time(0));
    for (Process& p : processes) {
        int lottery_number = rand() % total_tickets;
        int cumulative_priority = 0;
        for (const Process& q : processes) {
            cumulative_priority += q.priority;
            if (lottery_number < cumulative_priority) {
                p.execution_time--;
                break;
            }
        }
    }
}

int main() {
    int n;
    std::cout << "Nhap so tien trinh: ";
    std::cin >> n;
    std::vector<Process> processes(n);

    for (int i = 0; i < n; ++i) {
        processes[i].id = i + 1;
        std::cout << "Nhap execution time, arrival_time, va priority for process " << i + 1 << ": ";
        std::cin >> processes[i].execution_time >> processes[i].arrival_time >> processes[i].priority;
    }

    int current_time = 0;
    for (Process& p : processes) {
        p.waiting_time = current_time - p.arrival_time;
        p.turnaround_time = p.waiting_time + p.execution_time;
        current_time += p.execution_time;
    }

    lottery_scheduling(processes);

    double total_waiting_time = 0;
    double total_turnaround_time = 0;
    for (const Process& p : processes) {
        total_waiting_time += p.waiting_time;
        total_turnaround_time += p.turnaround_time;
    }

    double avg_waiting_time = total_waiting_time / n;
    double avg_turnaround_time = total_turnaround_time / n;


    std::cout << "\nAvg waiting time: " << avg_waiting_time << std::endl;
    std::cout << "Avg turnaround time: " << avg_turnaround_time << std::endl;
    system("pause");
    return 0;
}
