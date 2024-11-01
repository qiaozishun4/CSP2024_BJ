#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<deque>
#include<queue>
#include<cstring>
#include<string>
#include<cmath>
#define endl '\n'
using namespace std;
int n,m,a[100005],ra[100005],c[100005];
string s[10005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    srand(time(NULL));
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>c[i];
    int cnt=0,x=1;
    while(x<n)
    {
        cnt++;
        x*=2;
    }
    for(int i=cnt;i>=1;i--) cin>>s[i];
    int T;
    cin>>T;
    while(T--)
    {
        int x[5],ans=0;
        cin>>x[0]>>x[1]>>x[2]>>x[3];
        for(int i=1;i<=n;i++)
        {
            ra[i]=(a[i]^x[i%4]);
        }
        for(int i=1;i<=m;i++)
        {
            int p=rand()%c[i]+1;
            ans=ans^(p*i);
        }
        cout<<ans<<endl;
    }
    return 0;
}

