#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,m,L,V,ans=0,num1=0,num2=0,s;
double maxn1=0,minn1=1e6+5,maxn2=0,minn2=1e6+5;
double d[N],v[N],a[N],p[N],cs[N][3],vis[N];
void tx(int d,int v,int a,int i){
    if(v>V&&a>=0){
        cs[i][1]=d;
        cs[i][2]=L;
        return;
    }
    else if(v<V&&a>0){
        int x=(9-v*v)/(2*a);
        cs[i][1]=d+x+0.01;
        cs[i][2]=L;
        return;
    }
    else if(v>V&&a<0){
        int x=(9-v*v)/(2*a);
        cs[i][1]=d;
        cs[i][2]=d+x-0.01;
        return;
    }
    else if(v<=V&&a<=0){
        cs[i][1]=0;
        cs[i][2]=0;
        return;
    }
}
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m>>L>>V;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
            tx(d[i],v[i],a[i],i);
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j]>=cs[i][1]&&p[j]<=cs[i][2]){
                    vis[i]=1;
                }
            }
            if(vis[i]==1){
                ans++;
            }
        }
        cout<<ans<<" ";
        for(int i=1;i<=n;i++){
            if(vis[i]==1){
                minn1=min(minn1,cs[i][1]);
                maxn1=max(maxn1,cs[i][2]);
                minn2=min(minn2,cs[i][2]);
                maxn2=max(maxn2,cs[i][1]);
            }
        }
        for(int i=1;i<=m;i++){
            if(p[i]>=minn1&&p[i]<=minn2){
                num1++;
            }
            else if(p[i]>=maxn2&&p[i]<=maxn1){
                num2++;
            }
        }
        s=m;
        if(num1!=0) s--;
        if(num2!=0) s--;
        cout<<s<<endl;
    }
    return 0;
}
