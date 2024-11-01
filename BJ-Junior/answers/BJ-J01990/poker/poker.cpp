#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int n;
int cnt=0;
string p[55]={};
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> p[i];
    }
    cnt=52-n;
    sort(p+1,p+n+1);
    for(int i=1;i<=n;i++)
    {
        if(p[i]==p[i+1])
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
