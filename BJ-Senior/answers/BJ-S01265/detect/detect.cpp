#include<iostream>
#include<memory.h>

using namespace std;

const int Mod=1e3,NO=1e8+0.1;

int ans1=0,ans2=0;
struct car
{
    double st=0.0,en=0.0;
} x[Mod];


int main()
{
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T=0,n=0,m=0,p=0,f[Mod],i,j;
    double d=0.0,v=0.0,a=0.0,t=0.0,V=0.0,L=0.0;
    memset(f,0,sizeof(f));
    //memset(v,0,sizeof(v));
    //memset(a,0,sizeof(a));
    scanf("%d",&T);
    while(T--)
    {
        cin>>n>>m>>L>>V;
        ans2=m;
        for(i=1;i<=n;++i)
        {
            cin>>d>>v>>a;
            //cout<<d<<v<<a;
            if(a==0.0)
            {
                if(v>V){
                    x[i].st=d;
                    x[i].en=L;

                    cout<<x[i].st<<'\n'<<x[i].en<<'\n'<<ans1<<'\n';
                }
                else{

                    x[i].st=x[i].en=NO;
                    cout<<x[i].st<<'\n'<<x[i].en<<'\n'<<ans1<<'\n';
                }
            }
            else if(a<0){
                if(v>V){
                    t=(V-v)/a;
                    x[i].st=d;
                    x[i].en=v*t+a*t*t;

                    cout<<x[i].st<<'\n'<<x[i].en<<'\n'<<ans1<<'\n';
                }
                else{
                    x[i].st=x[i].en=NO;
                    cout<<x[i].st<<'\n'<<x[i].en<<'\n'<<ans1<<'\n';
                }
            }
            else{//a>0
                if(v>V){
                    x[i].st=d;
                    x[i].en=L;

                    cout<<x[i].st<<'\n'<<x[i].en<<'\n'<<ans1<<'\n';

                }
                else{
                    t=(V-v)/a;
                    x[i].st=v*t+a*t*t;
                    x[i].en=L;
                    if(x[i].st<=x[i].en)
                    cout<<x[i].st<<'\n'<<x[i].en<<'\n'<<ans1<<'\n';
                }
            }
            cout<<'\n';
        }
        for(i=1;i<=m;++i)
        {
            cin>>p;
            for(i=1;i<=m;++i)
            {

            for(j=1;i<=n;++j){
                //if(x[j].st<=p[i]&&p[i]<=x[j].en){
                {
                    ans1++;
                }
            }
        }
        //for(i=1;i<=n;++i){
          //  if(f[i]!=0) ans1++;
        //}
        cout<<ans1;
        //printf("%d",T);
    }
    return 0;
}
