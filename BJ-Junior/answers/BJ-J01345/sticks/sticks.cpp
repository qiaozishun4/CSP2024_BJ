#include<bits/stdc++.h>
using namespace std;
int n=10,c,w[11]={-1,6,2,5,5,4,5,6,3,7,6};
string v[11]={"-1","0","1","2","3","4","5","6","7","8","9"};
string dfs(int n,int c){
    if(c==0) return 0;
    if(c<0) return "no";
    if(n<=0) return 0;
    return min((dfs(n-1,c),dfs(n,c-w[n])+v[n]),dfs(n-1,c-w[n])+v[n]);
}
void solve(){
    cin>>c;
    cout<<dfs(n,c)<<endl;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}