#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
inline int read(){
    int s=0,f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-'){f=-1;}c=getchar();}
    while(isdigit(c)){s=s*10+c-'0';c=getchar();}
    return s*f;
}
struct Edge{int to,next,w;}edge[2*N];
int cnt=1,head[N];
void add(int u,int v,int w){
    edge[++cnt]=(Edge){v,head[u],w};
    head[u]=cnt;
}
int n,m,l,v,p[N],pre[N],ans1=0;
struct Car{int d,v,a,pos;}car[N];
void init(){
    cnt=0,ans1=0;
    memset(p,0,sizeof p);
    memset(pre,0,sizeof pre);
    memset(car,0,sizeof car);
    memset(head,0,sizeof head);
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T=read();
    while(T--){
        init();int tag=0;
        n=read();m=read(),l=read(),v=read();
        for(int i=1;i<=n;i++){
            car[i].d=read();
            car[i].v=read();
            car[i].a=read();
            if(car[i].a<0){tag=1;}
        }
        for(int i=1;i<=m;i++){int x=read();p[x]=1;}
        for(int i=1;i<=l;i++){pre[i]=pre[i-1]+p[i];}
        for(int i=1;i<=n;i++){
            int d=car[i].d,a=car[i].a;
            if(a==0){
                if(car[i].v>v){if(pre[l]-pre[d-1]>0){ans1++;}car[i].pos=d;}
            }
            if(a>0){
                if(car[i].v>v){if(pre[l]-pre[d-1]>0){ans1++;}car[i].pos=d;}
                else{
                    int s=floor((1.0*v*v-1.0*car[i].v*car[i].v)/(2.0*a));
                    if(d+s<=l){car[i].pos=d+s;if(pre[l]-pre[d+s]>0){ans1++;}}
                }

            }
            if(a<0){
                if(car[i].v>v){
                    int s=floor((1.0*car[i].v*car[i].v-1.0*v*v)/(-2.0*a));
                    if(d+s<=l){car[i].pos=d+s;if(pre[d+s]-pre[d-1]>0){ans1++;}}
                    else{car[i].pos=l;if(pre[l]-pre[d-1]>0){ans1++;}}
                }
            }
        }
        cout<<ans1<<" ";
        if(!tag){cout<<m-1<<endl;}
        else{}
    }
    return 0;
}
