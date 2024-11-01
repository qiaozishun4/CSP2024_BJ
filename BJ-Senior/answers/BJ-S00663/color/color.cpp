#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2000+10,N2=200000+10,M=1e6;
int a[N2],lst[N2],dp[N2],dp3[N2],vis[M],n;
int ans;

void dfs(int u,int num,int lst1,int lst2){
    //cout<<u<<": "<<lst1<<','<<lst2<<": "<<num<<endl;
    if(u>n){
        ans=max(ans,num);return;
    }
    dfs(u+1,num+(lst1==lst[u]?a[u]:0),u,lst2);
    dfs(u+1,num+(lst2==lst[u]?a[u]:0),lst1,u);
}

int calc(int l,int r){
    if(l>=r)return 0;
    return dp[r]-dp[l];
}

void test(){
    map<int,int>t;
    cin>>n;for(int i=1;i<=n;i++){
        cin>>a[i];
        lst[i]=t[a[i]];t[a[i]]=i;
    }
    if(n<=15){
        ans=0;
        dfs(2,0,1,-1);
        cout<<ans<<'\n';
    }else{
        int cnt=0;
        int num=0;
        for(int i=1;i<=n;i++){
            if(a[i]==a[i-1])cnt++,num+=a[i];
            else a[i-cnt]=a[i];
        }
        map<int,int>tt;
        n-=cnt;
        for(int i=1;i<=n;i++){
            lst[i]=tt[a[i]];tt[a[i]]=i;
        }
        for(int k=2;k<=n;k++){
            dp[k]=dp[k-1]+(lst[k]==k-1?a[k]:0);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            dp3[i]=max(dp[i],dp3[i-1]);
            if(lst[i]){
                dp3[i]=max(dp3[i],dp3[lst[i]+1]+calc(lst[i]+1,i-1)+a[i]);
                dp3[i]=max(dp3[i],dp3[lst[i]]+calc(lst[i]+1,i-1)+a[i]);
            }
            ans=max(ans,dp3[i]);
            //cout<<dp3[i]<<" ";
        }
        //cout<<"\n\n";
        cout<<ans+num<<'\n';
    }
}

signed main(){
    /****************************************************************************************************************/
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)test();
    return 0;
}
