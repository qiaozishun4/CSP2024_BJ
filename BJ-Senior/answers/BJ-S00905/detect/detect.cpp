#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,t;
double L,V,p[N];
struct cars{
    double d,v,a;
    double cs,ct;
    bool hbs,hbt;//1->han 0->bu han
}c[N];
struct line{
    double l,r;
    bool hbl,hbr;
}k[N];
bool cmp(line x,line y){
    return x.r<y.r;
}
int sceh(double x,bool hb){
    int lb=1,rb=m,mid,ans=0;
    while(lb<=rb){
        mid=(lb+rb)/2;
        if((hb==true && p[mid]<=x) || (hb==false && p[mid]<x)) ans=max(ans,mid);
        if(p[mid]<=x){
            lb=mid+1;
        }else{
            rb=mid-1;
        }
    }
    return ans;
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie();cout.tie();
    int T;
    cin>>T;
    while(T--){
        memset(c,0,sizeof(c));
        memset(k,0,sizeof(k));
        t=0;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>c[i].d>>c[i].v>>c[i].a;
            if(c[i].a>0){
                if(c[i].v>V){
                    c[i].cs=c[i].d;c[i].hbs=1;
                    c[i].ct=L;c[i].hbt=1;
                }else{
                    c[i].cs=c[i].d+(V*V-c[i].v*c[i].v)/(2*c[i].a);c[i].hbs=0;
                    c[i].ct=L;c[i].hbt=1;
                    if(c[i].cs>c[i].ct){
                        c[i].cs=-1;
                        c[i].ct=-1;
                    }
                }
            }else if(c[i].a==0){
                if(c[i].v>V){
                    c[i].cs=c[i].d;c[i].hbs=1;
                    c[i].ct=L;c[i].hbt=1;
                }else{
                    c[i].cs=-1;
                    c[i].ct=-1;
                }
            }else{
                if(c[i].v<=V){
                    c[i].cs=-1;
                    c[i].ct=-1;
                }else{
                    c[i].cs=c[i].d;c[i].hbs=1;
                    c[i].ct=c[i].d+(V*V-c[i].v*c[i].v)/(2*c[i].a);c[i].hbt=0;
                }
            }

        }
        for(int i=1;i<=m;i++) cin>>p[i];
        sort(p+1,p+m+1);
        int ans1=0;
        for(int i=1;i<=n;i++){
            if(c[i].cs==-1 && c[i].ct==-1) continue;
            bool flag=false;
            if(c[i].hbs==1){
                int id=lower_bound(p+1,p+n+1,c[i].cs)-p;
                if(c[i].hbt==0 && p[id]<c[i].ct){
                    ans1++;flag=true;
                }else if(c[i].hbt==1 && p[id]<=c[i].ct){
                    ans1++;flag=true;
                }
            }else{
                int id=upper_bound(p+1,p+n+1,c[i].cs)-p;
                if(c[i].hbt==0 && p[id]<c[i].ct){
                    ans1++;flag=true;
                }else if(c[i].hbt==1 && p[id]<=c[i].ct){
                    ans1++;flag=true;
                }
            }
            if(flag==true){
                t++;
                k[t].l=c[i].cs;k[t].r=c[i].ct;
                k[t].hbl=c[i].hbs;k[t].hbr=c[i].hbt;
            }
        }
        cout<<ans1<<" ";
        //cout<<t<<endl;
        sort(k+1,k+t+1,cmp);
        //int last=k[1].r,hblst=k[1].hbr;
    /*
        for(int i=1;i<=t;i++){
            cout<<k[i].l<<" "<<k[i].r<<":"<<k[i].hbl<<" "<<k[i].hbr<<endl;
        }*/
        int i=1,ans2=0;
        while(i<=t){
            int id=sceh(k[i].r,k[i].hbr);
            double px=p[id];
            while(i<=t){
                //cout<<i<<" ";
                if(k[i+1].hbl==true){
                    if(k[i+1].l<=px) i++;
                    else break;
                }
                else if(k[i+1].hbl==false){
                    if(k[i+1].l<px) i++;
                    else break;
                }
                else break;
            }
            ans2++;
            i++;
        }
        cout<<m-ans2<<endl;
    }
    return 0;
}
