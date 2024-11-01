
#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;
const int maxl=1e6+5;
int t,n,m,l,V,d[maxn],v[maxn],a[maxn],p[maxn];

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&n,&m,&l,&V);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&d[i],&v[i],&a[i]);
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&p[i]);
        }

        int ans=0;
        bool flag1=0,flag2=0,flag3=0;
        for(int i=1;i<=n;i++){
            if(a[i]!=0){
                flag1=1;
                break;
            }
        }
        for(int i=1;i<=n;i++){
            if(a[i]<=0){
                flag2=1;
                break;
            }
        }
        for(int i=1;i<=n;i++){
            if(a[i]>=0){
                flag3=1;
                break;
            }
        }
        if(!flag1){
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(v[i]>V && d[i]<=p[m]) cnt++;
            }
            if(cnt==0) ans=m;
            else ans=m-1;
            printf("%d %d\n",cnt,ans);
        }
        else if(!flag2){
            int cnt=0;
            for(int i=1;i<=n;i++){
                int dis=p[m]-d[i];
                if(dis>=0 && (long long)v[i]*v[i]+(long long)2*a[i]*dis>(long long)V*V) cnt++;
            }
            if(cnt==0) ans=m;
            else ans=m-1;
            printf("%d %d\n",cnt,ans);
        }
    }
    return 0;
}