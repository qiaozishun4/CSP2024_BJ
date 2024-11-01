#include <bits/stdc++.h>
using namespace std;
int d[100050],v[100050],a[100050],p[100050],jishu[100050],chaosu_che[1000][1000];
double v_now,vmax_now[100050];
bool speed_over[100050];
int cls=0;
unsigned long long ans=0;

double jisuan_v(int che_i,int ce_j)
{
    if(a[che_i]==0)
    {
        return double(v[che_i]);
    }
    double vans=sqrt(v[che_i]*v[che_i]+2*a[che_i]*(p[ce_j]-d[che_i]));
    if(vans<0)
    {
        return 0.0;
    }
    else
    {
        return vans;
    }
}

int main()
{
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,T,m,L,vmaxn;
    while(cin>>n)
{
cout<<-1;
}
    return 0;
}
/*

1
5
5
15
3
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2
5
8
9
15


*/
