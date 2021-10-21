#include<bits/stdc++.h>
using namespace std;

struct process
{
    int pid;
    int bt;
};


bool cmp(process a,process b)
{
    return a.bt < b.bt;
}

void findWaitingTime(process proc[], int n, int wt[])
{
   
    wt[0] = 0;
 
    
    for (int i = 1; i < n ; i++)
    {
        wt[i] = proc[i-1].bt + wt[i-1] ;
    }
}
 

void findTurnAroundTime(process proc[], int n, int wt[], int tat[])
{
    
    for (int i = 0; i < n ; i++)
    {
        tat[i] = proc[i].bt + wt[i];
    }
}
 

void findAverageTime(process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
 
    
    findWaitingTime(proc, n, wt);
 
   
    findTurnAroundTime(proc, n, wt, tat);
 
   
    cout << "\nProcesses "<< " Burst time "
         << " Waiting time " << " Turn around time\n";
 
    
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << proc[i].pid << "\t\t"
             << proc[i].bt << "\t " << wt[i]
             << "\t\t " << tat[i] <<endl;
    }
 
    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n;
    cout << "\nAverage response time = "
         << (float)total_wt / (float)n;
}

int main()
{
    cout << "Enter the no. of processes: ";
    int n;
    cin >> n;

     process  pro[n];

    cout << "Enter the process id and their respective burst time: ";
    for(int i=0;i<n;i++)
        cin >> pro[i].pid >> pro[i].bt;

    sort(pro,pro+n,cmp);

    cout << "Order in which process gets executed\n";
    for (int i = 0 ; i < n; i++)
        cout << pro[i].pid <<" ";

    findAverageTime(pro, n);

    return 0;
    
}