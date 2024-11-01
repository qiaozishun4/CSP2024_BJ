#include <iostream>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

struct car
{
    int d,v,a;
    void input()
    {
        cin >> d >> v >> a;
    }
};

car a[100010];
int c[100010];
bool f[100010];
int cnt = 0;
int n,m,l,v;
int speed(car x,int k)
{
    double s = sqrt(1.0 * (x.v*x.v + 2*x.a*(k-x.d)));
    return s;
}

void ride(int x)
{
    for(int i = 1;i <= m ;i++)
    {
        if(c[i] < a[x].d)
        {
            continue;
        }
        if(speed(a[x],c[i]) > 1.0 *v)
        {
            f[i] = 1;
           //cout <<
            cnt ++;
            return;
        }
    }
    return;
}

int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {

        cnt = 0;
        memset(f,sizeof(f),0);
        cin >> n >> m >> l >> v;
        for(int i = 1;i <= n ;i ++)
        {
            a[i].input();
        }
        for(int i = 1;i <= m;i ++)
        {
            cin >> c[i];
        }
        sort(c+1,c+m+1);
        for(int i = 1;i <= n;i ++)
        {
            ride(i);
        }
        int sum = 0;
        for(int i = 1;i <= m;i ++)
        {
            if(!f[i])
            {
               //cout << "\n***" << c[i] << "***\n";
               sum++;
            }
        }
        cout <<cnt << " " << sum <<endl;
    }
    return 0;
}
