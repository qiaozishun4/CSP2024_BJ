#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int N=1e6+10;
int T;
int n,m,L,V;
struct node
{
    int d,v,a;
};
node Car[N];
int p[N],shot[N],jug[N];
double ex[N];
int pre[N],exi[N];
int rest[N];
int satis[N];
int pos;
int nxtover[N];
bool cmp(node x,node y)
{
    return x.d<y.d;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
     cin >> T;
     while(T--)
     {
         cin >> n >> m >> L >> V;
         memset(p,0,sizeof(p));
         memset(jug,0,sizeof(jug));
         memset(shot,0,sizeof(shot));
         //memset(pre,0,sizeof(pre));
         //memset(exi,0,sizeof(exi));
         //memset(rest,0,sizeof(rest));
         //memset(satis,0,sizeof(satis));
         //memset(nxtover,0,sizeof(nxtover));
         //pos=0;
         bool p1=1,p2=1;
         for(int i=0;i<=n+1;i++)
         {
             Car[i].d=0;
             Car[i].v=0;
             Car[i].a=0;
         }
         for(int i=1;i<=n;i++)
         {
             cin >> Car[i].d >> Car[i].v >> Car[i].a;
             if(Car[i].a>=0)
             {
                 pos++;
             }
             if(Car[i].a!=0)
             {
                 p1=0;
             }
             if(!(Car[i].a>0))
             {
                 p2=0;
             }
         }
         sort(Car+1,Car+1+n,cmp);
         for(int i=1;i<=m;i++)
         {
             cin >> p[i];
             shot[p[i]]=1;
             exi[p[i]]=1;
         }
         for(int i=1;i<=L+1;i++)
         {
             shot[i]+=shot[i-1];
         }
         int cnt=0;
         for(int i=1;i<=n;i++)
         {
             double x=0,t=0,d=0;
             double v0,vf,a;
             int d_front,d_nxt;
             v0=Car[i].v,vf=V,a=Car[i].a;
             if(Car[i].a>0)
             {
                 t=(vf-v0)/a;
                 x=v0*t+0.5*a*t*t;
                 d=x+Car[i].d;
                 if(Car[i].v>V)
                 {
                    if(Car[i].d==0)
                    {
                        if(shot[L]>0)
                        {
                            cnt++;
                            jug[i]=1;
                            ex[i]=d;
                        }
                    }
                    else
                    {
                        if(shot[L]-shot[Car[i].d-1]>0)
                        {
                            cnt++;
                            jug[i]=1;
                            ex[i]=d;
                        }
                    }
                    continue;
                 }
                 if(d>L)
                 {
                     continue;
                 }
                 else
                 {
                     d_front=d;
                     d_nxt=d_front+1;
                     if(d==d_front)
                     {
                         if(shot[L]-shot[d_front]>0)
                         {
                             cnt++;
                             jug[i]=1;
                             ex[i]=d;
                             //cout << i << endl;
                         }
                     }
                     else
                     {
                         if(shot[L]-shot[d_nxt-1]>0)
                         {
                             cnt++;
                             jug[i]=1;
                             ex[i]=d;
                             //cout << i << endl;
                         }
                     }
                 }
             }
             if(Car[i].a==0)
             {
                 if(v0<=V)
                 {
                     continue;
                 }
                 else
                 {
                     if(Car[i].d-1<0)
                     {
                         if(shot[L]>0)
                         {
                             cnt++;
                             jug[i]=1;
                             ex[i]=Car[i].d;
                         }
                     }
                     else if(shot[L]-shot[Car[i].d-1]>0)
                     {
                         cnt++;
                         jug[i]=1;
                         ex[i]=Car[i].d;
                         //cout << i << endl;
                     }
                 }
             }
             if(Car[i].a<0)
             {
                 t=(vf-v0)/a;
                 x=v0*t+0.5*a*t*t;
                 d=x+Car[i].d;
                 if(d>L)
                 {
                     d=L+1;
                 }
                 if(v0<=V)
                 {
                     continue;
                 }
                 d_front=d;
                 //cout << endl << i << " " << d << " ";
                 if(d==d_front)
                 {
                     //cout << shot[d_front-1] << " " << shot[Car[i].d-1] << endl;
                     if(d_front-1<0)
                     {
                         if(shot[0]>0)
                         {
                             cnt++;
                             jug[i]=1;
                             ex[i]=d;
                         }
                     }
                     else if(Car[i].d-1<0)
                     {
                         if(shot[d_front-1]>0)
                         {
                             cnt++;
                             jug[i]=1;
                             ex[i]=d;
                         }
                     }
                     else if(shot[d_front-1]-shot[Car[i].d-1]>0)
                     {
                         cnt++;
                         jug[i]=1;
                         ex[i]=d;
                         //cout << i << endl;
                     }
                 }
                 else
                 {
                     //cout << shot[d_front] << " " << shot[Car[i].d-1] << endl;
                     if(Car[i].d-1<0)
                     {
                         if(shot[d_front]>0)
                         {
                             cnt++;
                             jug[i]=1;
                             ex[i]=d;
                         }
                     }
                     else if(shot[d_front]-shot[Car[i].d-1]>0)
                     {
                         cnt++;
                         jug[i]=1;
                         ex[i]=d;
                         //cout << i << endl;
                     }
                 }
             }
         }
         cout << cnt << " ";
         if(p1)
         {
             if(cnt==0)
             {
                 cout << m << endl;
             }
             else
             {
                 cout << m-1 << endl;
             }
         }
         else if(p2)
         {
             if(cnt==0)
             {
                 cout << m << endl;
             }
             else
             {
                 cout << m-1 << endl;
             }
         }
         else
         {
            cout << m << endl;
         }
     }
    return 0;
}
