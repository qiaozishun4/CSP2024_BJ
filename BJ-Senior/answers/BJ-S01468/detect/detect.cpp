#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,cnt,l1[100010],l2[100010],q,lenl[100010],lenr[100010],b,c;
struct f{
    int d,u,p;
}a[100010];
signed main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    ios::sync_with_stdio(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
            cnt=0;
        memset(l1,0,sizeof l1);
        memset(l2,0,sizeof l2);
        memset(lenl,0,sizeof lenl);
        memset(lenr,0,sizeof lenr);
        memset(a,0,sizeof a);
        b=0,c=0;
        int n,m,l,v;
        cin>>n>>m>>l>>v;
        for(int i=1;i<=n;i++){
            cin>>a[i].d>>a[i].u>>a[i].p;
        }
        //for(int i=1;i<=cnt;i++){
          //  cout<<lenl[i]<<" "<<lenr[i]<<endl;
        //}
        for(int i=1;i<=m;i++){
            cin>>l1[i];
        }
        sort(l1+1,l1+m+1);
        for(int i=1;i<=n;i++){
            if(a[i].u>v&&a[i].d<=l1[m]){
                cnt++;
            }
        }
        cout<<cnt<<" ";
        cout<<m-1<<endl;
    }
    return 0;
}
