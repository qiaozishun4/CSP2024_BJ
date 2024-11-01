#include<fstream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
vector<double>d,a,v,p;
vector<bool>detected;
ifstream cin("detect.in");
ofstream cout("detect.out");
inline double calct(double v0,double a,double s)
{
    return sqrt(v0*v0+2*a*s);
    //return sqrt(2*s/a+v0*v0/(a*a));
}
inline double calcv(double v0,double a,double t)
{
    return v0+a*t;
}

void term()
{
    int n,m,L,V,ans=0,maxc=0;
    cin>>n>>m>>L>>V;
    d.clear(),a.clear(),v.clear(),detected.clear();
    d.resize(n);
    a.resize(n);
    v.resize(n);
    detected.resize(n);
    //p.resize(m);
    for(size_t i=0;i<n;i++)
    {
        cin>>d[i]>>a[i]>>v[i];
    }
    for(size_t i=0;i<m;i++)
    {
        int pd;
        cin>>pd;
        bool flip=true;
        for(size_t j=0;j<n;j++)
        {

            double vj=calcv(v[j], a[j], calct(v[j], a[j], pd - d[j]));
            if(pd>d[j] && v[j]*v[j]+pd-d[j]>=0 && vj>V+0.1)
            {
                ans+=flip;
                flip=false;
                detected[j]=true;
            }
        }
    }
    for(bool b:detected)maxc+=b;
    cout<<maxc<<' '<<ans<<endl;
}
int main()
{
    int t;cin>>t;
    while(t--)term();
    return 0;
}
