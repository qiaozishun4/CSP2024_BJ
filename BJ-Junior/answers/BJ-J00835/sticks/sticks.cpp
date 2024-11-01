#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e7;
ll db=2;
ll d[10]={6,2,5,5,4,5,6,3,7,6};
ll f(ll x){
    ll ans=0;
    while(x>0){
        ans+=d[x%10];
        x/=10;
    }
    return ans;
}
void solve1(ll n){
    ll ans=-1;
    for(ll i=1;i<=N;i++){
        ll x=f(i);
        if(x==n){
            ans=i;
            break;
        }
    }
    cout<<ans<<"\n";
}
bool cmp(string a,string b){
    if(a.length()<b.length())return 1;
    if(a.length()>b.length())return 0;
    for(ll i=a.length()-1;i>=0;i--)if(a[i]<b[i])return 1;
    return 1;
}
void dfs(ll y,string &s,ll n,string &ans){
    if(y>n)return;
    if(y==n){//qia hao yong wan
        if(s[s.length()-1]=='0')return;
        if(ans=="-1"||cmp(s,ans))ans=s;//geng xiao
        if(db&2)printf(":y=%lld:n=%lld:s=%s:ans=%s\n",y,n,s.c_str(),ans.c_str());
        return;
    }
    else{
        for(ll i=0;i<=9;i++){
            string ss=s+("0"+i);
            dfs(y+d[i],ss,n,ans);
        }
    }
}
void solve(ll n){
    string s="";
    string ans="-1";
    dfs(0,s,n,ans);
    cout<<ans<<"\n";
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        if(n<=50)solve1(n);
        else solve(n);
    }
    return 0;
}
