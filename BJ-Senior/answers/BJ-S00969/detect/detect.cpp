#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,v2,d[100010],v[100010],a[100010];
bool f[100010];
struct Node{
    int dist,sum;
}p[100010];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    while(t--){
        int ans1=0,ans2=0;
        cin>>n>>m>>l>>v2;
        for(int i=1;i<=m;i++) p[i].sum=0;
        ans2=m;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=m;i++){
            cin>>p[i].dist;
        }
        for(int i=1;i<=n;i++){
            if(v[i]>v2){
                if(p[m].dist>=d[i]) ans1++;
                for(int j=1;j<=m;j++){
                    if(p[j].dist>=d[i]){
                        p[j].sum++;
                        break;
                    }
                }
            }
        }
        for(int i=2;i<=m;i++){
            p[i].sum+=p[i-1].sum;
        }
        cout<<ans1<<" ";
        if(ans1==0){
            cout<<m<<endl;
            continue;
        }
        for(int i=1;i<=n;i++){
            if(v[i]>v2&&d[i]<=p[m].dist){
                int maxnum=1,ma=0;
                for(int j=1;j<=m;j++){
                    if(p[j].dist>=d[i]){
                        if(ma<=p[j].sum){
                            maxnum=j;
                            ma=p[j].sum;
                        }
                    }
                }
                if(f[maxnum]==false){
                    ans2--;
                    f[maxnum]=true;
                }
                ans1--;
            }
            if(ans1==0) break;
        }
        cout<<ans2<<endl;
    }
    return 0;
}
