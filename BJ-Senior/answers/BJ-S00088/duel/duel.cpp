#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N];
queue<int>ss;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        if(!ss.empty()&&ss.front()<a[i])
        {
            ss.pop();
        }
        ss.push(a[i]);
    }
    cout<<ss.size();
    return 0;
}