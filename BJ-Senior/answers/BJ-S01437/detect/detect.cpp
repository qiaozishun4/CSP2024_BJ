#include<bits/stdc++.h>
using namespace std;
int t,n,m,l,vlim,minde=1e9,ans;
int d[100005],v[100005],a[100005],det[100005];
bool dp[100005],check[100005],use[100005];
set<int> st;
vector<int> vc[100005];

void dfs(int step){
    if(st.size()==ans){
        minde=min(minde,step);
        //cout<<"step="<<step<<endl;
        //out<<"-------"<<endl;
        return;
    }
    for(int i=1;i<=m;i++){

        if(use[i] || vc[i].size()==0) continue;
        //cout<<i<<":";
        for(auto x:vc[i]){
            st.insert(x);
            //cout<<x<<" ";
        }
        use[i]=1;
        //cout<<endl;
        dfs(step+1);
        for(auto x:vc[i]){
            st.erase(x);
        }
        use[i]=0;
    }
    return;
}

int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    for(int p=1;p<=t;p++){
        st.clear();
        cin>>n>>m>>l>>vlim;
        bool flag=0;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>v[i]>>a[i];
            if(a[i]) flag=1;
        }
        for(int i=1;i<=m;i++){
            cin>>det[i];
            use[i]=0;
            vc[i].clear();
        }
        if(flag==0){
            int last=0;
            for(int j=1;j<=m;j++){
                last=max(last,det[j]);
            }
            ans=0;
            for(int i=1;i<=n;i++){
                if(d[i]<=last && v[i]>vlim) ans++;
            }
            cout<<ans<<" ";
            if(ans==0) cout<<m<<endl;
            else cout<<m-1<<endl;
        }
        else{
            ans=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(det[j]<d[i]) dp[j]=0;
                    else if(v[i]*v[i]+2*a[i]*(det[j]-d[i]) > vlim*vlim) dp[j]=1;
                    else dp[j]=0;
                    //cout<<dp[j]<<" ";
                    if(dp[j]==1){
                        check[i]=1;
                        vc[j].push_back(i);
                    }
                }
                //cout<<endl;
            }
            for(int i=1;i<=n;i++){
                if(check[i]==1) ans++;
            }
            cout<<ans<<" ";
            dfs(0);
            cout<<m-minde<<endl;
        }
    }
    return 0;
}


