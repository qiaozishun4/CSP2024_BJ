#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
struct car{
    double l,r;
    bool catc=0;
}c[N];

struct pa{
    int p,num;
}ca[N];

int n,m,L,V,ans1,ans2,T;

bool cmp(car x,car y){
    return x.l<y.l;
}

bool cmp2(pa x,pa y){
    return x.num>y.num;
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
    cin>>n>>m>>L>>V;
    ans1=0;
    ans2=0;
    for(int i=1;i<=n;i++){
        int d,v,a;
        cin>>d>>v>>a;
        if(a==0){
            if(v>V){
                c[i].l=d;
                c[i].r=L;
            }else{
                c[i].l=-1;
                c[i].r=-1;
            }


        }else if(a<0){
            if(v<V){
                c[i].l=-1;
                c[i].r=-1;
            }else{
                double x=(V*V-v*v)/(2.0*a);
                c[i].l=d;
                c[i].r=d+x;
            }
        }else if(a>0){
            if(v>V){
                c[i].l=d;
                c[i].r=L;
            }else{
                double x=(V*V-v*v)/(2.0*a);
                c[i].l=d+x;
                c[i].r=L;
            }
        }
    }
    sort(c+1,c+n+1,cmp);
    //for(int i=1;i<=n;i++){
   //     cout<<c[i].l<<" "<<c[i].r<<endl;
   // }
    for(int i=1;i<=m;i++){
        cin>>ca[i].p;
        ca[i].num=0;
        for(int j=1;j<=n;j++){
                //cout<<c[j].catc<<" ";
            if(c[j].l<=ca[i].p&&c[j].r>=ca[i].p){
                if(!c[j].catc){
                    ans1++;
                }
                c[j].catc=1;
                ca[i].num++;
            }
        }
    }
    sort(ca+1,ca+m+1,cmp2);
    int cnt=ans1,t=1;
    while(cnt!=0){
        int f=0;
        for(int i=1;i<=n;i++){
            if(c[i].catc==0) continue;
             if(c[i].l<=ca[t].p&&c[i].r>=ca[t].p){
                c[i].catc=0;
                cnt--;
                f=1;
                for(int j=1;j<=m;j++){
                    if(c[i].l<=ca[j].p&&c[i].r>=ca[j].p){
                        ca[j].num--;
                    }

                }
            }
        }
        if(f){
            ans2++;
        }
        ca[t].num=0;
        sort(ca+1,ca+m+1,cmp2);
    }
    ans2=m-ans2;
    cout<<ans1<<" "<<ans2<<endl;
    }
    return 0;
}
