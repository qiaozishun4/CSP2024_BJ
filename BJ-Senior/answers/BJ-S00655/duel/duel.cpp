#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int n,a[N];
bool f[N];
int c1=0,c2=0;
int id[N];
struct st
{
    int num;
    int cnt;
} b[N];
bool cmp(int x,int y)
{
    return x>y;
}
int maxn = -1,minn = N;
int nt[N];
int cnt = 0;
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;++i)
    {
        int x;
        cin >> x;
        ++a[x];
        f[x] = 1;
        if(x==1)
            ++c1;
        if(x==2)
            ++c2;
        minn = min(minn,x);
        maxn = max(maxn,x);
    }
    //cout << maxn << " " << minn << endl;
    if(c1+c2==n)
    {
        if(c2>=c1)
            cout << c2;
        else
            cout << c1;
        return 0;
    }
    int p = minn;
    for(int i=p+1;i<=maxn;++i)
    {
        if(f[i])
        {
            nt[p] = i;
            p = i;
        }
    }
    int l = minn;
    int r = l;
    while(r<=maxn&&r!=0&&l!=0)
    {
        r = nt[l];

        //cout << l << " " << r << endl;
        if(a[l]<=a[r])
            cnt += a[l];
        else
        {
            cnt += a[r];
            a[r] += (a[l]-a[r]);
        }
        l = r;
    }
    cout << n-cnt;
    return 0;
}
