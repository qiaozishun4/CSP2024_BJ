#include<bits/stdc++.h>
using namespace std;
int a[100010], b[100010], lb[100010];
stack<int> maxa;
int main()
{
    ifstream fin("duel.in", ios::in);
    ofstream fout("duel.out", ios::out);
    int n;
    fin >> n;
    for(int i = 0;i < n;i++)
    {
        fin >> b[i];
        lb[i] = b[i];
    }
    sort(b, b + n);
    sort(lb, lb + n);
    for(int i = 0;i < n;i++)
    {
        if(i == 0) b[i] = 0;
        else if(lb[i] == lb[i - 1]) b[i] = b[i - 1];
        else if(lb[i] > lb[i - 1]) b[i] = b[i - 1] + 1;
    }
    for(int i = 0;i < n;i++)
    {
        a[b[i]]++;
        if(maxa.empty()) maxa.push(b[i]);
        else if(b[i] > maxa.top()) maxa.push(b[i]);
    }
    int sum = n;
    for(int i = 0;i < n;i++)
    {
        if(a[b[i] + 1] >= 1)
        {
            sum--;
            a[b[i] + 1]--;
        }
        else for(int p = b[i] + 2;p < maxa.top();p++)
        {
            if(a[p] >= 1)
            {
                sum--;
                a[p]--;
                if(a[p] == 0 && p == maxa.top()) maxa.pop();
                break;
            }
        }
    }
    fout << sum << endl;
    return 0;
}
