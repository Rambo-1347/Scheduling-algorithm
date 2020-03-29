#include<bits/stdc++.h>
using namespace std;

 int dony[20];
 int top = 0;
void findavgTime(int [], int, int [], int);

struct Process
{
    int pid;  // Process ID
    int at;   // Arrival time
    int bt;   // CPU Burst time required
    int priority; // Priority of this process
};
 
// Function to sort the Process acc. to priority
bool comparison(Process a, Process b)
{
    return !(a.priority > b.priority);
}
