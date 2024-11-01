#include<bits/stdc++.h>
using namespace std;
struct node{
    int d,A,v;
};
int n,m,l,V;
node a[100005];
node D;
int p[100005];
int ans[100005];
int vis[3005][3005];
int book[100005];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    D.A=-1;D.d=-1;D.v=-1;
    int t;
    cin>>t;
    while(t--){
        int n,m,l,V;
        cin>>n>>m>>l>>V;
        int flag=1;
        for(int i=1;i<=n;i++){
            cin>>a[i].d>>a[i].v>>a[i].A;
            if(a[i].A!=0){
                flag=0;
            }
            if(a[i].v<=V&&a[i].A<=0){
                a[i]=D;
            }
        }
        for(int i=1;i<=m;i++){
            cin>>p[i];
        }
        int ans;
        int cnt2=0;
        if(flag==1){
            for(int i=1;i<=n;i++){
                if(a[i].v>V){
                    int x=upper_bound(p+1,p+1+m,a[i].d)-p;
                    for(int j=x;j<=m;j++){
                        vis[i][j]=1;
                    }
                    ans++;
                }
            }

            for(int k=1;k<=n;k++){
                int maxx=-1,maxx_i;
                for(int i=1;i<=n;i++){
                    int cnt=0;
                    for(int j=1;j<=n;j++){
                        cnt+=vis[j][i];
                    }
                    if(cnt>maxx){
                        maxx=cnt;
                        maxx_i=i;
                    }
                }
                int flag2=1;
                for(int i=1;i<=n;i++){
                    if(vis[i][maxx_i]==1){
                        if(book[i]==1)flag=0;
                        book[i]=1;
                    }
                }
                if(flag2==1){
                    break;
                }
                else{
                    cnt2++;
                }
            }
        }
        cout<<ans<<" "<<cnt2<<endl;
    }
    return 0;
}
