#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

bool flag[2] = {false, false};
int turn;

void criticalSection(int id) {
    int other = 1 - id;
    flag[id] = true;
    turn = other;
    while (flag[other] && turn == other);
    
    cout << "Process " << id << " is in critical section\n";
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Process " << id << " is leaving critical section\n";

    flag[id] = false;
}

void process(int id) {
    for (int i = 0; i < 3; i++) {
        cout << "Process " << id << " is trying to enter critical section\n";
        criticalSection(id);
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

int main() {
    thread p0(process,0);
    thread p1(process,1);
    p0.join();
    p1.join();

    return 0;
}