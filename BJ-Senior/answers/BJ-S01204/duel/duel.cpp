#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005]={};
int c[100005] = {};
int n;
int w;
int st(int a[])
{
    int maxn = -1;
    int t;
    for(int i = 1; i <= w; i++)
    {
        if(maxn <= a[i])
        {
            maxn = a[i];
            t = i;
        }

    }
    a[t] = -1;

    return maxn;
}
int f(int x,int y,int z)
{
    if(y == 0)
    {
        return 0;
    }
    if(x == y)
    {
        return f(b[z+1],b[z+2],z+1);
    }

    n -= 1;
    b[z+1] = 0;
    int c[100005];
    for(int i=1; i <= w; i++)
    {
        c[i] = b[i];
    }
    for(int i = 1; i <= w; i++)
    {
        b[i] = st(c);
    }
    return f(b[z+1],b[z+2],z+1);
}
int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    cin >> w;
    n = w;
    for(int i = 1; i <= w; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= w; i++)
    {
        b[i] = st(a);
    }
    int c = f(b[1],b[2],1);
    cout << n-1;

    return 0;
}