#include <bits/stdc++.h>
using namespace std;
typedef double db;
struct point{
    db d,v,a;
};
point ca[100005];
int p[100005];
int fa[100005];
int spa,spb,spc;
db dv(db v0,db a,db s){
    return sqrt(v0*v0+2*a*s);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        spa=0;
        spb=0;
        spc=0;
        int cnt=0;
        int n,m,l,v;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            cin>>ca[i].d>>ca[i].v>>ca[i].a;
            if(ca[i].a!=0){
                spa=1;
            }
            if(ca[i].a<0){
                spb=1;
            }
            if(ca[i].a>0){
                spc=1;
            }
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
//        cout<<spa<<spb<<spc<<endl;
        if(spa==0){
            int flag=0;
            for(int i=1;i<=n;i++){
                if(ca[i].d<=p[m]&&ca[i].v>v){
                    flag++;
                }
            }
            cout<<flag<<" ";
            if(flag==0){
                cout<<m;
            }
            else{
                cout<<m-1;
            }
            cout<<endl;
            continue;
        }
        if(spb==0){
            int flag=0;
            for(int i=1;i<=n;i++){
                if(ca[i].d<=p[m]){
                    if(dv(ca[i].v,ca[i].a,p[m]-ca[i].d)>v){
                        flag++;
                    }
                }
            }
            cout<<flag<<" ";
            if(flag==0){
                cout<<m;
            }
            else{
                cout<<m-1;
            }
            cout<<endl;
            continue;
        }
   //     for(int i=1;i<=n;i++){
//
     //       for(int j=1;j<=m;j++){
      //          if(p[j]<ca[i].d){
     //               continue;
      //          }
        //    }
   //     }
    }
    return 0;
}
