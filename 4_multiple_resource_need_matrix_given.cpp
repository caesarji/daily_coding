#include <bits/stdc++.h>
using namespace std;

void safeSequence(int n, int r, vector<int> available, vector<vector<int>> allocated, vector<vector<int>> requested)
{

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
                    if (requested[i][j] > work[j])
                        break;

                if (j == r)
                    index = i;
            }
        }

        if (index == -1)
        {
            cout << "****** Deadlock Detected *******" << endl;
            break;
        }
        else
        {
            for (int j = 0; j < r; j++)
                work[j] += allocated[index][j];

            safeSeq[count++] = index;
            done[index] = true;
        }
    }

    if (count != n)
    {
        cout << "The process in the Deadlock are:" << endl;
        for (int i = 0; i < n; i++)
        {
            if (!done[i])
                cout << "P" << i + 1 << "\t";
        }
        cout << endl;
    }
    else
    {
        cout << "The Safe sequence of execution is: ";
        for (int i = 0; i < n; i++)
            cout << "P" + to_string(safeSeq[i] + 1) + " ";
        cout << endl;
    }
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
    vector<vector<int>> requested(n, vector<int>(r));

    for (int i = 0; i < n; i++)
    {
        cout << "For process P" + to_string(i + 1) + ": " << endl;

        cout << "Enter resources allocated" << endl;
        for (int j = 0; j < r; j++)
            cin >> allocated[i][j];

        cout << "Enter resources Requested" << endl;
        for (int j = 0; j < r; j++)
            cin >> requested[i][j];
    }
    cout << endl;

    cout << "Enter current available resources: " << endl;
    for (int i = 0; i < r; i++)
        cin >> available[i];

    safeSequence(n, r, available, allocated, requested);

    return 0;
}