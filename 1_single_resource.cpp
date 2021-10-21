#include <bits/stdc++.h>
using namespace std;

void safeSequence(int n, int available, vector<int> allocated, vector<int> max)
{
    vector<int> need(n);

    cout << "Need Matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        need[i] = max[i] - allocated[i];
        cout << "P" + to_string(i + 1) + ": " << need[i] << endl;
    }
    cout << endl;

    int work = available;
    vector<bool> done(n, false);
    vector<int> safeSeq(n, 0);
    int count = 0;

    while (count != n)
    {
        int index = -1;

        for (int j = 0; j < n; j++)
            if (done[j] == false && need[j] <= work)
                index = j;

        if (index == -1)
        {
            cout << "There is no safe sequence of execution";
            return;
        }
        else
        {
            safeSeq[count++] = index;
            done[index] = true;
            work += allocated[index];
        }
    }

    cout << "The Safe sequence of execution is: ";
    for (int i = 0; i < n; i++)
        cout << "P" + to_string(safeSeq[i] + 1) + " ";
    cout << endl;
}

int main()
{
    int n, available;
    cout << "Enter number of processes: ";
    cin >> n;
    vector<int> allocated(n);
    vector<int> max(n);
    cout << "Enter resources allocated and max resources" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P" + to_string(i + 1) + ": ";
        cin >> allocated[i] >> max[i];
    }
    cout << "Enter current available resources: " << endl;
    cin >> available;

    safeSequence(n, available, allocated, max);

    return 0;
}
/*
4
1 6
1 5 
2 4 
4 7
2
*/