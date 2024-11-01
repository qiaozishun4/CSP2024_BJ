#include<bits/stdc++.h>
using namespace std;
int l[100010];
bool dp[110][200010];
int work(int a,int b){
    if(a%b!=0)return a%b;
    else return b;
}
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        vector<int> s[100010];
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++){
                int x;
                cin>>x;
                s[i].push_back(x);
            }
        }
        for(int i=0;i<l[1];i++)
            dp[1][s[1][i]]=1;
        for(int i=2;i<=100;i++){
            for(int j=0;j<l[work(i,n)];j++)
                for(int p=0;p<=j;p++)
                    if(dp[i-1][s[work(i,n)][p]])dp[i][j]=1;
        }
        for(int i=1;i<=q;i++){
            int r,c;
            cin>>r>>c;
            cout<<dp[r][c]<<endl;
        }
    }
    return 0;
}
