#include <bits/stdc++.h>
using namespace std;
long long n,m,i,j,s[500009],a[500009];
priority_queue<long long,vector<long long>,greater<long long>> p,q;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        q.push(a[i]);
    }
    p.push(q.top());
    q.pop();
    while(!q.empty())
    {
        long long x=q.top(),y=p.top();
        q.pop();
        p.push(x);
        if(y<x)
        {
            n--;
            p.pop();
        }
    }
    cout <<n;
    return 0;
}
