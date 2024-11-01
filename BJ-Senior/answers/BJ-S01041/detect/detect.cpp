#include<bits/stdc++.h>
using namespace std;
#define MAXN 100001
#define W 0.000001
int T;
int n,m,L,V,d[MAXN],v[MAXN],a[MAXN],p[MAXN];
struct _Range
{
    double l,r;
    bool eql,eqr;
    bool operator < (const _Range &a)
    {
        return l<a.l;
    }
    bool operator > (const int &a)
    {
        if(eql) return a<l;
        else return a<=l;
    }
    bool operator ^ (const int &a)
    {
        return (l<a&&a<r)||(eql&&a==l)||(eqr&&a==r);
    }
    bool operator < (const int &a)
    {
        if(eqr) return a>r;
        else return a>=r;
    }
};
_Range range[MAXN];int tot;
inline double sq(double a){return a*a;}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>L>>V;
        for(int i=0;i<n;i++) cin>>d[i]>>v[i]>>a[i];
        for(int i=0;i<m;i++) cin>>p[i];
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                if(v[i]>V)
                    range[tot++]={(double)d[i],(double)L,1,1};
            }
            else if(a[i]<0)
            {
                if(v[i]>V)
                {
                    double s=(double)(sq(V)-sq(v[i]))/a[i]/2.0;
                    if(d[i]+s>L) range[tot++]={(double)d[i],(double)L,1,1};
                    else range[tot++]={(double)d[i],(double)d[i]+s,1,0};
                }
            }
            else
            {
                if(v[i]>V) range[tot++]={(double)d[i],(double)L,1,1};
                else
                {
                    double s=(double)(sq(V)-sq(v[i]))/a[i]/2.0;
                    if(d[i]+s<=L) range[tot++]={(double)d[i]+s,(double)L,0,1};
                }
            }
        }
        sort(range,range+tot);
        _Range det[tot];int k=0,tt=0;
        for(int i=0;i<m;i++)
        {
            while(k<tot&&range[k]<p[i]) k++;
            while(k<tot&&range[k]^p[i]) det[tt++]=range[k++];
            if(k==tot) break;
        }
        cout<<tt<<' ';//<<endl;
        //for(int i=0;i<tt;i++) cout<<det[i].l<<"～"<<det[i].r<<endl;
        k=0;int ttt=0;
        for(int i=0;i<tt;i++)
        {
            while(k<m&&range[i]^p[k]) k++;k--;
            while(i<tt&&range[i]^p[k]) i++;
            ttt++;
        }
        cout<<ttt<<endl;//<<endl;
    }
    return 0;
}
