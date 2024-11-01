#include <bits/stdc++.h>
using namespace std;

int r[100000];

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int ri;
        cin >> ri;
        r[ri]++;
    }
    sort(r,r+100001,cmp);
    cout << r[0];
    fclose(stdin);
    fclose(stdout);
    return 0;
}