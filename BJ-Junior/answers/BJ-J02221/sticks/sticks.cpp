#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string goans="-1";
bool flag=1;
ll counts[10]={6,2,5,5,4,5,6,3,7,6};
ll countx(ll x){
    ll sum=0;
    string sx=to_string(x);
    for(int i=0;i<sx.size();i++){
        sum+=(counts[(sx[i]-'0')]);
    }
    return sum;
}
ll less7(ll x){
    ll ans;
    if(x==1) ans=-1;
    if(x==2) ans=1;
    if(x==3) ans=7;
    if(x==4) ans=4;
    if(x==5) ans=2;
    if(x==6) ans=6;
    if(x==7) ans=8;
    return ans;
}
ll digit1(ll x){
    ll ans;
    if(x==2) ans=1;
    if(x==3) ans=7;
    if(x==4) ans=4;
    if(x==5) ans=2;
    if(x==6) ans=6;
    return ans;
}
ll stick2digit(ll x){
    return (ceil(1.0*x/7));
}
void dfs(ll step,string nows,ll nowcnt,ll maxcnt,ll maxdigit){
    if(flag==0)return;
    if(step>maxdigit){
        goans=nows;
        flag=0;
        return;
    }
    if(step==maxdigit){
        ll addi=-1;
        ll nowrest=maxcnt-nowcnt;
        if(nowrest==2) addi=1;
        if(nowrest==3) addi=7;
        if(nowrest==4) addi=4;
        if(nowrest==5) addi=2;
        if(nowrest==6) addi=0;
        if(nowrest==7) addi=8;
        if(addi==-1)return;
        dfs(step+1,nows+(char)(addi+'0'),nowcnt+counts[addi],maxcnt,maxdigit);
    }
    for(ll addi=0;addi<=9;addi++){
        if(addi==0 && step==1)continue;
        if(stick2digit(maxcnt-nowcnt-counts[addi])>(maxdigit-step)){
            continue;
        }
        dfs(step+1,nows+(char)(addi+'0'),nowcnt+counts[addi],maxcnt,maxdigit);
    }

}
void calc(){
    flag=1;
    ll n;
    cin>>n;
    if(n<=7){
        cout<<less7(n)<<endl;
        return;
    }
    dfs(1,"",0,n,stick2digit(n));
    cout<<goans<<endl;
    return;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ll T;
    cin>>T;
    while(T--)calc();
    return 0;
}