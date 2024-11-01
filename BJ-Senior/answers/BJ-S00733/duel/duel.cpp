#include <bits/stdc++.h>
using namespace std;

int n,a1[100001],a2[100001];

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    int zd = 0,s1 = 0,s2 = 0;
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a1[i];
        if (a1[i] > zd)
        {
            zd = a1[i];
        }
        if (a1[i] == 1)
        {
            s1++;
        }
        else if (a1[i] == 2)
        {
            s2++;
        }
    }
    if (zd <= 2)
    {
        if (s2 > s1)
        {
            cout << s2;
        }
        else
        {
            cout << s1;
        }
        return 0;
    }
    sort(a1+1,a1+n+1);
    int d = n;
    for (int i = 2;i <= n;i++)
    {
        int j = i-1;
        while (j > 1 && (a2[j] != 0 || a1[i] <= a1[j]))
        {
            j--;
        }
        if (a1[i] > a1[j] && a2[j] == 0)
        {
            a2[j] = 1;
            d--;
        }
    }
    cout << d;


    return 0;
}

