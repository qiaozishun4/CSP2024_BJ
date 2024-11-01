#include <bits/stdc++.h>
using namespace std;
int T7;
const int N=1e5+5;
struct car
{
    int enter;
    int velocity;
    int accelerant;
    int spd;
}cnm[N];
int pg[N];
double spdmax[N];
long double sv(int vel,int acc,int i,int enter)
{
    return sqrt(vel*vel+2*acc*abs(pg[i]-enter));
}
long double s(int vel,int t,int acc)
{
    return vel*t+0.5*acc*t*t;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T7;
    while(T7--)
    {
        int n,m,l,v;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++)
        {
            cin>>cnm[i].enter>>cnm[i].velocity>>cnm[i].accelerant;
        }
        for(int i=1;i<=m;i++)
        {
            cin>>pg[i];
        }
        cout<<n<<" "<<m;
    }
    return 0;
}