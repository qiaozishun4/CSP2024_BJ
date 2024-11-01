#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,l,v;
struct node{
    int d,v,p;
}a[100005];
int nl[100005];
double nv(node x,int y)
{
    int s=y-x.d;
    double v=sqrt(x.v*x.v+2*s*x.p);
    return v;
}
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>l>>v;
        for(int i=0;i<n;i++)
        {
            cin>>a[i].d>>a[i].v>>a[i].p;
        }
        for(int i=0;i<m;i++)
        {
            cin>>nl[i];
        }
        int numcar=0,numlight=m;
        bool visl[100005]={};
        memset(visl,0,sizeof(visl));
        double maxs=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(nv(a[i],nl[j])>v&&nl[j]>=a[i].d)
                {
                    numcar++;
                    maxs=max(maxs,nl[j]*1.0);
                    if(!visl[j])
                    {
                        visl[j]=true;
                        numlight--;
                    }
                    break;
                }
                if(nv(a[i],nl[j])<=0&&nl[j]>=a[i].d)
                {
                    maxs=max(maxs,nl[j]*1.0);
                    break;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            if(nl[i]>maxs&&(!visl[i])) numlight++;
        }
        cout<<numcar<<" "<<numlight<<endl;
    }
}
