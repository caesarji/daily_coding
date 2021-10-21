#include <bits/stdc++.h>
using namespace std;

void safeSequence(int n, int r, vector<int> available, vector<vector<int>> allocated, vector<vector<int>> max)
{
    vector<vector<int>> need(n, vector<int>(r));

    cout << "Need Matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P" + to_string(i + 1) + ": ";
        for (int j = 0; j < r; j++)
        {
            need[i][j] = max[i][j] - allocated[i][j];
            cout << need[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    vector<int> work(available);
    vector<bool> done(n, false);
    vector<int> safeSeq(n, 0);
    int count = 0;

    while (count != n)
    {
        int index = -1;

        for (int i = 0; i < n; i++)
        {
            if (done[i] == false)
            {
                int j;
                for (j = 0; j < r; j++)
                    if (need[i][j] > work[j])
                        break;

                if (j == r)
                    index = i;
            }
        }

        if (index == -1)
        {
            cout << "There is no safe sequence of execution";
            return;
        }
        else
        {
            for (int j = 0; j < r; j++)
                work[j] += allocated[index][j];

            safeSeq[count++] = index;
            done[index] = true;
        }
    }

    cout << "The Safe sequence of execution is: ";
    for (int i = 0; i < n; i++)
        cout << "P" + to_string(safeSeq[i] + 1) + " ";
    cout << endl;
}

int main()
{
    int n, r;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resources: ";
    cin >> r;

    vector<int> available(r);
    vector<vector<int>> allocated(n, vector<int>(r));
    vector<vector<int>> max(n, vector<int>(r));

    for (int i = 0; i < n; i++)
    {
        cout << "For process P" + to_string(i + 1) + ": " << endl;

        cout << "Enter resources allocated" << endl;
        for (int j = 0; j < r; j++)
            cin >> allocated[i][j];

        cout << "Enter max resources" << endl;
        for (int j = 0; j < r; j++)
            cin >> max[i][j];
    }
    cout << endl;

    cout << "Enter current available resources: " << endl;
    for (int i = 0; i < r; i++)
        cin >> available[i];

    safeSequence(n, r, available, allocated, max);

    return 0;
}
/*
5
3
0 1 0
7 5 3
2 0 0
3 2 2
3 0 2
9 0 2
2 1 1
2 2 2
0 0 2
4 3 3
3 3 2
*/