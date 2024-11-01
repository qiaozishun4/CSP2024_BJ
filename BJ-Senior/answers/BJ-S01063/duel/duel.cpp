#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
#define F(i,a,b) for(int i=a;i<=b;i++)
#define dF(i,b,a) for(int i=b;i>=a;i--)
#define LL long long
int ans,n,r[N];
priority_queue <int,vector<int>,greater<int>> q;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    ans = n;
    F(i,1,n) cin>>r[i];
    sort(r+1,r+n+1);
    F(i,1,n)
    {
        if(q.size())
        {
            int x = q.top();
            if(r[i] > x)
            {
                q.pop();
                ans--;
            }
        }
        q.push(r[i]);
    }
    cout << ans << '\n';
   return 0;
}