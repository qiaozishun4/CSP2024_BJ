#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;
int a[100010];
queue<int> q;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    int ans=n;
    for(int i=1;i<=n;i++)
    {
        if(!q.empty()&&a[i]>q.front())
        {
            ans--;
            q.pop();
        }
        q.push(a[i]);
    }
    cout<<ans<<endl;
}
