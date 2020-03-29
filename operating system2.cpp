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
void priorityScheduling(Process proc[], int n)
{
	
	int temp = 0;
	for(int i = 0 ; i < n; i++)
	{
		temp = temp + proc[i].bt;
		
	}
	//cout<<"\n MAXTIME: "<<temp<<endl;
	
	// Sort processes by priority8
    sort(proc, proc + n, comparison);
	
	
	//needed for level 2
	// process id's
    int processes[20];
 
    // Burst time of all processes
    int burst_time[20];
	
	//level 1
	//  main Logic to communicate between the levels

	int i,j=0,f=0,newi=0;
	int time = 0;
	bool flag2 = true;
	bool flag1 = true;
	
	while(flag1)
	{	
		for(i = 0; i < n; ++i)
		{
			
			if(time >= proc[i].at and proc[i].pid != -1)
			{
				
				if(proc[i].bt != 0)
					{
					
					
					if(flag2)
					{
						j = i;
						flag2 = false;
					}
					
					proc[i].bt = proc[i].bt -1;
					
					if(proc[i].bt == 0)
					{
						dony[top] = proc[i].pid;
						top++;
						
					}
					
					if(i != j )
					{
						if(proc[j].bt != 0)
						{
					
						processes[newi] = proc[j].pid;
						burst_time[newi] = proc[j].bt;
						proc[j].pid = -1;
						newi++;
						j = i;
						}
						else
						{
						flag2 = true;
						}
					
					}
				
				
					i = -1;				
					time++;
				}	
			}
			
		}
		if(time >= temp)
			{
				flag1 = false;
			}
		time++;
		
	}
	
	cout<<"\nProcesses those are completed in level 1:"<<endl;
		
	for(int i=0;i<top-1;i++)
	{
		cout<<"  "<<dony[i]<<"  --> ";
		
	}cout<<dony[top-1]<<endl;
