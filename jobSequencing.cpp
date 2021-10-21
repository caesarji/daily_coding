#include<bits/stdc++.h>
using namespace std;


struct Job
{
char id;
int dead;
int profit;
};

bool comparison(Job a, Job b)
{
	return (a.profit > b.profit);
}

void printJobScheduling(Job arr[], int n)
{
	sort(arr, arr+n, comparison);

	for(int i=0;i<n;i++)
        cout << arr[i].profit << " ";
    cout << endl;

	int result[n];
	//vector<int>result;
	bool slot[n];

	for (int i=0; i<n; i++)
		slot[i] = false;


	for (int i=0; i<n; i++)
	{
        for (int j=min(n, arr[i].dead)-1; j>=0; j--)
        {

		if (slot[j]==false)
		{
			result[j] = i;
			slot[j] = true;
			break;
		}
	}
	}

    int sum = 0;
    for (int i=0; i<n; i++)
        if (slot[i])
            sum+=arr[result[i]].profit;

    /* for(int i=0;i<result.size();i++)
        {
            sum+=arr[result[i]].profit;
        }*/

	for (int i=0; i<n; i++)
        if (slot[i])
            cout << arr[result[i]].id << " ";
    cout << "and  maximum profit is " << sum << endl;
}ube



int main()
{
    int n;
    cout << "Enter the number of jobs ";
    cin >> n;
    Job arr[n];
    char a;
    int b,c;
    cout << "Enter the job id,with deadline and profit \n";
    for(int i=0;i<n;i++)
    {
        cin >> a >> b >> c;
        arr[i].id = a;
        arr[i].dead = b;
        arr[i].profit = c;

    }

	cout << "Maximum profit sequence of jobs are \n";

	printJobScheduling(arr, n);
	return 0;
}