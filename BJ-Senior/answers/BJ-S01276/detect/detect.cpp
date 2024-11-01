#include<bits/stdc++.h>
using namespace std;
struct car{
    int a;
    int v;
    int d;
}c[100010];
car c1[100010];
int tv[100010],b[100010];
int main(){
    ios::sync_with_stdio;
    cin.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,L,V;
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>c[i].d>>c[i].v>>c[i].a;
        }
        for(int i=1;i<=m;i++){
            cin>>tv[i];
        }
        int ans1=0,ans2=0;
        int pp=0;
        int Mmax=0;
        for(int i=1;i<=n;i++){
            int out=10001000;
            if(c[i].a<0){
                out=(0-c[i].v*c[i].v)/(2*c[i].a);
                out+=c[i].d;
            }
            int flag=1;
         for(int j=1;j<=m;j++){
                    int s=0,num=0,vt=0;
                if(c[i].d<tv[j]&&out>tv[j]){
                    int s=tv[j]-c[i].d;
                    int num=c[i].v*c[i].v+2*c[i].a*s;
                    double vt=sqrt(num);
                    if(vt>V){
                        c1[++pp]=c[i];
                        if(flag==1){
                            ans1++;
                            flag=0;
                        }
                        b[tv[j]]++;
                        Mmax=max(Mmax,b[tv[j]]);
                    }
                }
            }
        }
 /*       for(int i=1;i<=n;i++){
            if(c1[i].a<0){
                int out=10001000;
                int in=0;
                if(c1[i].a<0){
                    out=(V*V-c1[i].v*c1[i].v)/(2*c1[i].a);
                    out+=c1[i].d;
                    Mmax=max(Mmax,out);
                    cout<<"Mmax="<<Mmax<<endl;
                    flag1=1;
                }else if(c1[i].a>0){
                    in=(V*V-c1[i].v*c1[i].v)/(2*c1[i].a);
                    in+=c1[i].d;
                    Mmin=min(Mmin,in);
                    cout<<"Mmin="<<Mmin<<endl;
                    flag2=1;
                }else if(c1[i].a==0){
                    in=c1[i].d;
                    Mmin=min(Mmin,in);
                }
            }
        }
        if(flag1==0&&flag2==0){
            ans2=0;
        }
        if(flag1==0&&flag2==1){
            for(int j=1;j<=m;j++){
                if(tv[j]<Mmin){
                    ans2++;
                }
            }
        }for(int j=1;j<=m;j++){
                if(tv[j]<Mmin){
                    ans2++;
                }
            }
        if(flag1==1&&flag2==0){
            for(int j=1;j<=m;j++){
                if(tv[j]>Mmax){
                    ans2++;
                }
            }
        }
        if(flag1==1&&flag2==1){
            for(int j=1;j<=m;j++){
                if(tv[j]>Mmax){
                    ans2++;
                }
            }
            for(int j=1;j<=m;j++){
                if(tv[j]<Mmin){
                    ans2++;
                }
            }
        }*/
        ans2=ans1-(ans1-Mmax)+1;
        cout<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}

