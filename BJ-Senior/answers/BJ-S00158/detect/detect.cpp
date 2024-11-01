#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,v,ans;
int r[100005];
int d[100005],vi[100005],a;
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    for(int k=1;k<=t;k++){
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>vi[i]>>a;
        }
        for(int i=1;i<=m;i++){
            cin>>r[i];
        }
        sort(r,r+m+1);
        for(int i=1;i<=n;i++){
            if(vi[i]>v&&d[i]<=r[m]){
                ans++;
            }
        }
        cout<<ans<<" "<<m-1<<endl;
        ans=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
