#include<bits/stdc++.h>
using namespace std;

struct Process
{
  int pid,arrivalTime,burstTime,waitTime,turnAroundTime,ResponseTime,completionTime,TempBurstTime;
  
  Process(){
    ResponseTime=-1;
  }
};


struct Ghantt
{
  int endTime,pid;
  Ghantt(int x,int y)
  {
    pid=x;
    endTime=y;
  }
};


int GetProcess(vector<Process>&proc,int t)
{
    int n=proc.size();
    int time=1e9;
    int k=-1;
    
    for(int i=0;i<n;i++)
    {
        if(proc[i].arrivalTime<=t && proc[i].TempBurstTime<time && proc[i].TempBurstTime>0)
        {
            k=i;
            time=proc[i].TempBurstTime;
        }
    }
    cout << k << endl;
    return k;
}

int schedule(vector<Process>&proc,vector<Ghantt>&ghanttChart)
{
    int time=0;
    int idleTime=0;
    int count=0;
    int n=proc.size();

    while(count<n)
    {
        int p=GetProcess(proc,time);
        time++;

        if(p==-1)
        {
            idleTime++;
            if(ghanttChart.size() && ghanttChart.back().pid==-1)
                ghanttChart.back().endTime=time;
            else
                ghanttChart.push_back(Ghantt(-1,time));
            continue;
        }

        proc[p].TempBurstTime--;

        if(proc[p].TempBurstTime==0)
        {
            proc[p].completionTime=time;
            proc[p].turnAroundTime=time-proc[p].arrivalTime;
            proc[p].waitTime=proc[p].turnAroundTime-proc[p].burstTime;
            count++;
        }

        if(proc[p].ResponseTime==-1)
          proc[p].ResponseTime=time-1-proc[p].arrivalTime;
        
        if(ghanttChart.size()==0||ghanttChart.back().pid!=proc[p].pid)
        {
            if(ghanttChart.size())
                idleTime++;
            ghanttChart.push_back(Ghantt(proc[p].pid,time));
        }
        else
            ghanttChart.back().endTime=time;
    }

    return idleTime;
}


void print(vector<Process>&proc)
{ cout<<setw(15)<<"processId"<<setw(15)<<"ArrivalTime"<<setw(15)<<"burstTime"<<
  setw(15)<<"completionTime"<<setw(15)<<"TurnAround"<<setw(15)<<"WaitTime"
  <<setw(15)<<"ResponseTime"<<endl;

  for(auto it:proc)
  {
    cout<<setw(15)<<it.pid<<setw(15)<<it.arrivalTime<<setw(15)<<it.burstTime<<
    setw(15)<<it.completionTime<<setw(15)<<it.turnAroundTime<<setw(15)<<it.waitTime
    <<setw(15)<<it.ResponseTime<<endl;
  }
  cout<<endl;
}


void GhanttPrint(vector<Ghantt>&ghanttChart,int first_start_time)
{
    cout<<setw(4)<<"Pid|";
    for(auto i : ghanttChart)
    {
        if(i.pid==-1)
            cout<<setw(11)<<"empty|";
        else
            cout<<setw(10)<<i.pid<<"|";
    }
    cout<<endl;

    cout<<setw(3)<<first_start_time<<"|";
    for(auto i : ghanttChart)
        cout<<setw(10)<<i.endTime<<"|";

    cout<<endl;

}

double AvgTurn(vector<Process>& p)
{
  int n=p.size();
  double sum=0;

  for(auto it:p)
      sum+=it.turnAroundTime;

  return sum/n;
}

double AvgWait(vector<Process>& p)
{
  int n=p.size();
  double sum=0;
  for(auto it:p)
      sum+=it.waitTime;

  return sum/n;
}

double avgResponse(vector<Process>& p)
{
  int n=p.size();
  double sum=0;
  for(auto it:p)
      sum+=it.ResponseTime;

  return sum/n;
}

double CPUUtilization(vector<Process>& p,int idleTime)
{
  double sum=0;
  int n=p.size();
  for(auto it:p)
      sum+=it.burstTime;

  return sum/(sum+idleTime)*100;
}

int main()
{
    int n;
    cout<<"enter the number of processes : ";
    cin>>n;

    vector<Process>proc(n);

    cout<<"enter arrival time and burst time\n";
    for(int i=0;i<n;i++)
    {
        proc[i].pid=i+1;
        cout<<"for process "<<i+1<<" :";
        cin>>proc[i].arrivalTime>>proc[i].burstTime;
        proc[i].TempBurstTime=proc[i].burstTime;
    }

    vector<Ghantt>g;

    int idleTime=schedule(proc,g);

    int first_start_time=proc[g[0].pid-1].arrivalTime;

    print(proc);

    GhanttPrint(g,first_start_time);

    cout<<endl;

    cout<<"Average Turn Around Time : "<<AvgTurn(proc)<<endl;
    cout<<"Average waiting time : "<<AvgWait(proc)<<endl;
    cout<<"Average response time : "<<avgResponse(proc)<<endl;
    cout<<"CPU UTILIZATION "<<CPUUtilization(proc,idleTime)<< "%" <<endl;

    return 0;
}