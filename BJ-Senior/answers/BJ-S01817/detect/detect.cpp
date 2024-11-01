#include<iostream>
#include<cstdio>
#include<iomanip>
#define N 100009
using namespace std;
int d[N];
int v[N];
int a[N];
int p[N];
int n, m, l, maxv;
const double eps=1e-31;
int abs(int x)
{
    if(x>0) return x;
    return -x;
}
namespace _A{
    void main_func()
    {
        int cnt=0;
        for(int i=1; i<=n; i++)
        {
            if(v[i]>maxv && d[i]<=p[m]) cnt++;
        }
        if(cnt!=0)
            cout << cnt << " " << m-1 << endl;
        else if(cnt==0)
            cout << cnt << " " << m << endl;
        return ;

    }
}
inline int square(int x) {return x*x;}
namespace _B{
    void main_func()
    {
        int cnt=0;
        for(int i=1; i<=n; i++)
        {
            if(v[i]>maxv && p[m]>=d[i]) cnt++;
            else{
             //   double x=((square(maxv)-square(v[i]))/(2.0000000000000000000000000*a[i]))+d[i]*1.000000000000000000000000000;
             //   cout << x << endl;
              //  cout << fixed<<setprecision(10)<< x << endl;
              //  if(x<=(p[m]*1.0000)) cnt++;


                int x1=square(maxv)-square(v[i]);
                int x2=p[m]*a[i]*2-2*a[i]*d[i];
                if(x1<x2&&p[m]>=d[i]) cnt++;

               // if(p[m]*1.0-x >= eps) cnt++;
            }

        }

        if(cnt!=0)
            cout << cnt << " " << m-1 << endl;
       else if(cnt==0)
            cout << cnt << " " << m << endl;

        return ;

    }
}
void mian()
{
    cin>>n>>m>>l>>maxv;
    bool A=true;
    bool B=true;
    for(int i=1; i<=n; i++)
    {
        cin>>d[i]>>v[i]>>a[i];
        if(a[i]!=0) A=false;
        else if(a[i]<0) B=false;
    }
    for(int i=1; i<=m; i++)
    {
        cin>>p[i];
    }
    if(A) _A::main_func();
    else if(B) _B::main_func();

}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin >> T;
    while(T--)
    {
        mian();
    }
    return 0;
}
