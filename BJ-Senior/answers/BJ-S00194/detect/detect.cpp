#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,m,L,V;
bool A=true,B=true;
struct car{
    ll d,v,a;
};
car a[int(1e5)+100];
ll s[int(1e6)+100];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>m>>L>>V;
        A=true,B=true;
        bool u=0;
        for(int i=1;i<=n;i++){
            cin>>a[i].d>>a[i].v>>a[i].a;
            if(a[i].a!=0)A=false;
            if(a[i].a<=0)B=false;
            if(a[i].v>V)u=true;
        }
        for(int i=1;i<=m;i++){
            cin>>s[i];
        }
        if(a[1].d>s[m]){
            cout<<0<<endl;
            for(int i=1;i<=m;i++)s[i]=0;
            for(int i=1;i<=n;i++){
                a[i].d=0,a[i].v=0,a[i].a=0;
            }
            continue;
        }
        if(A){
            u==true&&a[1].d<=s[m]?cout<<1<<endl:cout<<0<<endl;
            for(int i=1;i<=m;i++)s[i]=0;
            for(int i=1;i<=n;i++){
                a[i].d=0,a[i].v=0,a[i].a=0;
            }
            continue;
        }
        if(B){
            ll las=0x3fffffff;
            for(int i=1;i<=n;i++){
                ll num=ceil((V*V-(a[i].v*a[i].v))/(2*a[i].a))+a[i].d;
                las=min(las,num);
            }
            if(las>s[m]){
                cout<<0<<endl;
            }
            else{
                cout<<1<<endl;
            }
            for(int i=1;i<=m;i++)s[i]=0;
            for(int i=1;i<=n;i++){
                a[i].d=0,a[i].v=0,a[i].a=0;
            }
            continue;
        }
    }

    return 0;
}
