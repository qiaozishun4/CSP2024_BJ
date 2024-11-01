#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int d[N],vs[N],a[N],p[N];
int n,m,l,v;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int f=0,f1=0,f2=0,maxn=0;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&d[i],&vs[i],&a[i]);
            if(a[i]<0){
                f=1;
            }
            if(a[i]>0) f1=1;
            if(a[i]==0) f2=1;
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&p[i]);
            maxn=max(maxn,p[i]);
        }
        int cnt=0;
        if(f==0&&f1==0){
            for(int i=1;i<=n;i++){
                if(vs[i]>v&&maxn>=d[i]){
                    cnt++;
                }
            }
            if(cnt==0) cout<<cnt<<" "<<m<<endl;
            else cout<<cnt<<" "<<m-1<<endl;
            continue;
        }else if(f==0&&f2==0){
            for(int i=1;i<=n;i++){
                if(maxn<d[i]) continue;
                if(maxn==d[i]&&vs[i]<=v) continue;
                double y=(double)(v*v-vs[i]*vs[i])/(2*a[i]);
                double c=(double)y+d[i];
                if(c<maxn){
                    cnt++;
                }
            }
            if(cnt==0) cout<<cnt<<" "<<m<<endl;
            else cout<<cnt<<" "<<m-1<<endl;
            continue;
        }
    }
    return 0;
}
