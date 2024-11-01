#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
#define int long long
const int N = 1e5 + 5;
const int L = 22;

int n,m,t,ans,a[N],b[N],c[N],d[L][2*N],x[4];

int check(int x,int y,int d,int r)
{
    if(d == 0)
    {
        if(x >= r) return 1;
        else return 2;
    }
    if(d == 1)
    {
        if(y >= r) return 2;
        else return 1;
    }
}

struct node
{
    int a,r;
};

signed main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=m;i++)
        cin >> c[i];
    int k = ceil(log2(n));
    for(int i=1;i<=k;i++)
        for(int j=1;j<=pow(2,k-i);j++)
            cin >> d[i][j];
    cin >> t;
    for(int tt=1;tt<=t;tt++)
    {
        for(int i=0;i<=3;i++) cin >> x[i];
        for(int i=1;i<=n;i++)
            b[i] = a[i] ^ x[i % 4];
        queue<node> q;
        for(int i=1;i<=n;i++)
            q.push({b[i],1});
        int lst = 0, gg = 0;
        while(q.size() > 1)
        {
            int num1 = q.front().a;
            int round = q.front().r;
            q.pop();
            int num2 = q.front().a;
            q.pop();
            if(round != lst) gg = 0;
            gg++;
            if(check(num1,num2,d[round][gg],round) == 1) q.push({num1,round+1});
            else q.push({num2,round+1});
        }
        cout << q.front().a << endl;
    }
    return 0;
}
