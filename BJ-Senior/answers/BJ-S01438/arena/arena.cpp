#include<iostream>
#include<cmath>
#include<set>
#include<string>
using namespace std;

#define ll long long
const int maxn=1e5+10,lg=20;
int n,m,ci[maxn],decide[lg][maxn],players[maxn],T,online[4];
unsigned power[maxn],tmppower[maxn],usepower[maxn];
set<int> possible;

int get(int x){
    int k=0,v=1;
    while(v<x)v*=2,k++;
    return v;
}
int Get(int x){
    int k=0,v=1;
    while(v<x)v*=2,k++;
    return k;
}
int solve(int c, unsigned* power){
    for(int i=1;i<=c;i++)players[i]=i;
    for(int r=1,amount=c;r<=Get(c);r++,amount/=2){
        for(int g=1;g<=amount/2;g++){
            if(power[players[g*2-1+decide[r][g]]]>=r)players[g]=players[g*2-1+decide[r][g]];
            else players[g]=players[g*2-1+(decide[r][g]^1)];
        }
    }
    return players[1];
}
void solve2(int cur, int stop, int lim){
    if(cur==stop+1){
        possible.insert(solve(stop,usepower));
        return;
    }
    for(int i=0;i<=lim;i++)usepower[cur]=i,solve2(cur+1,stop,lim);
}
int main(){
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>tmppower[i];
    for(int i=1;i<=m;i++)cin>>ci[i];
    for(int i=1,amount=get(n)/2;i<=Get(n);i++,amount/=2){
        string s; cin>>s;
        for(int j=1;j<=amount;j++)decide[i][j]=s[j-1]-'0';
    }
    cin>>T;
    while(T--){
        for(int i=0;i<4;i++)cin>>online[i];
        for(int i=1;i<=n;i++)power[i]=tmppower[i]^online[i%4];
        if(n>8){
            ll gans=0;
            for(int i=1;i<=m;i++)gans^=(ll)i*solve(ci[i],power);
            cout<<gans<<endl;
        }else{
            int gans=0;
            for(int i=1;i<=m;i++){
                possible.clear();
                for(int j=1;j<=ci[i];j++)usepower[j]=power[j];
                solve2(ci[i]+1,get(ci[i]),Get(ci[i]));
                int ans=0;
                for(auto it=possible.begin();it!=possible.end();it++)ans+=*it;
                gans^=ans*i;
            }
            cout<<gans<<endl;
        }
    }
}