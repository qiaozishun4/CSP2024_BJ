#include<bits/stdc++.h>
using namespace std;
int n,r[100005];
//multiset<int> st;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> r[i];
    }
    sort(r+1,r+n+1);
    int len = 0,ans = n,cur = 1;
    for(int i=2;i<=n;i++)
    {
        if(r[i] > r[cur])
        {
            cur ++;
            ans --;
        }
    }
    cout << ans;
    return 0;
}
