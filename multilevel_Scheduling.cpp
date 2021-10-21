#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int pid, arrivalTime, burstTime, waitTime, turnAroundTime, ResponseTime, completionTime, TempBurstTime, queue;
    bool inqueue;
    Process()
    {
        ResponseTime = -1;
        inqueue = false;
    }
};

struct Ghantt
{
    int endTime, pid;
    Ghantt(int x, int y)
    {
        pid = x;
        endTime = y;
    }
};

bool cmp(Process &a, Process &b)
{
    if (a.arrivalTime == b.arrivalTime)
        return a.burstTime < b.burstTime;
    return a.arrivalTime < b.arrivalTime;
}

void GetProcess(vector<Process> &proc, int t, queue<int> &rrq, queue<int> &fcfsq)
{
    int n = proc.size();

    for (int i = 0; i < n; i++)
    {
        if (proc[i].arrivalTime <= t)
        {
            if (proc[i].TempBurstTime > 0 && proc[i].inqueue == false)
            {
                if (proc[i].queue == 1)
                    rrq.push(i);
                else
                    fcfsq.push(i);
                proc[i].inqueue = true;
            }
        }
    }
}

int schedule(vector<Process> &proc, vector<Ghantt> &ghanttChart, int timeQuantum)
{
    int time = proc[0].arrivalTime;
    int idleTime = proc[0].arrivalTime;
    int count = 0;
    int n = proc.size();
    queue<int> rrq, fcfsq;
    GetProcess(proc, time, rrq, fcfsq);

    while (count < n)
    {
        if (rrq.empty() && fcfsq.empty())
        {
            idleTime++;
            time++;
            if (ghanttChart.size() && ghanttChart.back().pid == -1)
                ghanttChart.back().endTime = time;
            else
                ghanttChart.push_back(Ghantt(-1, time));
            GetProcess(proc, time, rrq, fcfsq);
            continue;
        }
        int p;
        if (rrq.empty())
        {
            p = fcfsq.front();
            if (proc[p].TempBurstTime == 1)
            {
                fcfsq.pop();
                proc[p].inqueue = false;
            }
            proc[p].TempBurstTime--;
            time++;
            if (proc[p].TempBurstTime == 0)
            {
                proc[p].completionTime = time;
                proc[p].turnAroundTime = time - proc[p].arrivalTime;
                proc[p].waitTime = proc[p].turnAroundTime - proc[p].burstTime;
                count++;
            }
            if (proc[p].ResponseTime == -1)
            {
                proc[p].ResponseTime = time - 1 - proc[p].arrivalTime;
            }
            GetProcess(proc, time, rrq, fcfsq);
        }

        else
        {
            p = rrq.front();
            rrq.pop();
            int t = min(timeQuantum, proc[p].TempBurstTime);
            time += t;
            GetProcess(proc, time, rrq, fcfsq);
            proc[p].inqueue = false;
            (proc[p].TempBurstTime) -= t;
            if (proc[p].TempBurstTime == 0)
            {
                proc[p].completionTime = time;
                proc[p].turnAroundTime = time - proc[p].arrivalTime;
                proc[p].waitTime = proc[p].turnAroundTime - proc[p].burstTime;
                count++;
            }
            else
            {
                rrq.push(p);
                proc[p].inqueue = true;
            }
            if (proc[p].ResponseTime == -1)
            {
                proc[p].ResponseTime = time - t - proc[p].arrivalTime;
            }
        }
        if (ghanttChart.size() == 0 || ghanttChart.back().pid != proc[p].pid)
        {
            if (ghanttChart.size())
                idleTime++;
            ghanttChart.push_back(Ghantt(proc[p].pid, time));
        }
        else
            ghanttChart.back().endTime = time;
    }
    return idleTime;
}

void print(vector<Process> &proc)
{

    cout << setw(10) << "processId" << setw(10) << "Arrival" << setw(10) << "burst" << setw(15) << "completion" << setw(15) << "TurnAround" << setw(10) << "Wait"
         << setw(10) << "Response" << endl;

    for (auto it : proc)
    {
        cout << setw(10) << it.pid << setw(10) << it.arrivalTime << setw(10) << it.burstTime << setw(15) << it.completionTime << setw(15) << it.turnAroundTime << setw(10) << it.waitTime
             << setw(10) << it.ResponseTime << endl;
    }
    cout << endl;
}

int GhanttPrint(vector<Ghantt> &ghanttChart, int first_start_time)
{
    cout << setw(4) << "Pid|";
    for (auto i : ghanttChart)
    {
        if (i.pid == -1)
            cout << setw(11) << "empty|";
        else
            cout << setw(7) << i.pid << "|";
    }
    cout << endl;
    cout << setw(3) << first_start_time << "|";
    for (auto i : ghanttChart)
    {
        cout << setw(7) << i.endTime << "|";
    }
    cout << endl;
}

double AvgTurn(vector<Process> &p)
{
    int n = p.size();
    double sum = 0;
    for (auto it : p)
    {
        sum += it.turnAroundTime;
    }
    return sum / n;
}

double AvgWait(vector<Process> &p)
{
    int n = p.size();
    double sum = 0;
    for (auto it : p)
    {
        sum += it.waitTime;
    }
    return sum / n;
}

double avgResponse(vector<Process> &p)
{
    int n = p.size();
    double sum = 0;
    for (auto it : p)
    {
        sum += it.ResponseTime;
    }
    return sum / n;
}

double CPUUtilization(vector<Process> &p, int idleTime)
{
    double sum = 0;
    int n = p.size();
    for (auto it : p)
    {
        sum += it.burstTime;
    }
    return sum / (sum + idleTime) * 100;
}

int main()
{
    int n;
    cout << "enter the number of processes : ";
    cin >> n;
    cout << "enter time Quantum : ";
    int timeQuantum;
    cin >> timeQuantum;
    vector<Process> proc(n);
    cout << "enter arrival time,burst time and queue number\n";
    for (int i = 0; i < n; i++)
    {
        proc[i].pid = i + 1;
        cout << "for process " << i + 1 << " :";
        cin >> proc[i].arrivalTime >> proc[i].burstTime >> proc[i].queue;
        proc[i].TempBurstTime = proc[i].burstTime;
    }
    sort(proc.begin(), proc.end(), cmp);
    vector<Ghantt> g;
    int idleTime = schedule(proc, g, timeQuantum);
    int first_start_time = proc[g[0].pid - 1].arrivalTime;
    print(proc);
    GhanttPrint(g, first_start_time);
    cout << endl;
    cout << "Average Turn Around Time : " << AvgTurn(proc) << endl;
    cout << "Average waiting time : " << AvgWait(proc) << endl;
    cout << "Average response time : " << avgResponse(proc) << endl;
    cout << "CPU UTILIZATION " << CPUUtilization(proc, idleTime) <<"%" << endl;
    return 0;
}



