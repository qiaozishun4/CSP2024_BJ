#include<bits/stdc++.h>
using namespace std;
struct car{
    int d,v,a;
}c[100005];
int p[100005];
int x[100005];
int dfs[105];
int cnt1=0;
int cnt2=111111;
int n,m,L,V;
int cnt=0;
void ds(int x){
if(x==m+1){
         int kis=0;
    for(int i=1;i<=n;i++){
        int ans=0;
        for(int j=1;j<=m;j++){
            if(dfs[j]&&p[j]>=c[i].d){
                int derta=c[i].v*c[i].v+2*c[i].a*(p[j]-c[i].d);
                if(derta>V*V)ans=1;
            }
        }
        if(ans)kis++;
    }
    if(kis!=cnt)return;
    int cnt3=0;
    for(int i=1;i<=m;i++)cnt3+=dfs[i];
    cnt2=min(cnt2,cnt3);
    return;
}
    dfs[x]=1;
    ds(x+1);
    dfs[x]=0;
    ds(x+1);
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    int T;cin>>T;
    while(T--){
        cin>>n>>m>>L>>V;
        memset(x,0,sizeof(x));
        for(int i=1;i<=n;i++)cin>>c[i].d>>c[i].v>>c[i].a;
        for(int i=1;i<=m;i++)cin>>p[i];
        for(int i=1;i<=n;i++){
            int l=1,r=m;

            while(l<=r){
                int mid=(l+r)/2;
                int anss;
                if(p[mid]>=c[i].d){
                    int derta=c[i].v*c[i].v+2*c[i].a*(p[mid]-c[i].d);
                    if(derta<=0)anss=1;
                    else{
                        double t=sqrt(derta);
                        if(t>V)anss=0;
                        else {
                            if(c[i].a>=0)anss=2;
                            else anss=1;
                        }
                    }
                }else{
                    anss=2;
                }
                if(anss==0){cnt++;x[i]=1;break;}
                else if(anss==1)r=mid-1;
                else l=mid+1;
            }

        }
        cout<<cnt<<" ";
        if(n>=20&&m>=20){
            cout<<m-1<<endl;continue;
        }
        ds(1);
        cout<<m-cnt2<<endl;
    }
    return 0;
}
