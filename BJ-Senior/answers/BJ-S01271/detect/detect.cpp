#include<bits/stdc++.h>
using namespace std;
long long n,T,m,L,V,a[101000],b[101000],c[101000],
ansg[101000];
int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
        for(int i=1;i<=m;i++) cin>>ansg[i];
        sort(ansg+1,ansg+m+1);
        int uo;
        if(c[1]>0) uo=1;
        if(c[1]<0) uo=2;
        if(c[1]==0) uo=0;
        if(uo==0)
        {
            int anss=0;
            for(int i=1;i<=n;i++) if(ansg[m]>=a[i]&&b[i]>V) anss++;
            cout<<anss<<" "<<m-(anss>=1)<<endl;
        }
        if(uo==2)
        {
            int anss=0;
            for(int i=1;i<=n;i++)
            {
                double tim=1.0*(b[i]*b[i]-a[i]*a[i])*1.0/(2*c[i])*1.0;
                if(tim>ansg[1]) anss++;
            }
            cout<<anss<<" "<<m-1<<endl;
        }
        //if(uo==1)
       // {
       //
        //}
    }
    return 0;
}
