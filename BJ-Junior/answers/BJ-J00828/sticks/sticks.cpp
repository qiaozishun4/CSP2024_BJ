#include<bits/stdc++.h>
using namespace std;

int t,n; int cost[]={6,2,5,5,4,5,6,3,7,6};
string s,mins;

string cmp(string a,string b){
    if(a.size()!=b.size()) return a.size()<b.size()?a:b;
    else return a<b?a:b;
}

void dfs(int top,int now,string s){
    if(now>top) return;
    if(now==top){mins=cmp(s,mins);return;}
    if(!s.size())
        for(int i=1;i<10;i++)
            dfs(top,now+cost[i],s+string(1,cost[i]+'0'));
    else
        for(int i=0;i<10;i++)
            dfs(top,now+cost[i],s+string(1,cost[i]+'0'));
}

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin >>t;
    while(t--){
        mins="9999999999999999999999999999999";
        scanf("%d",&n);
        if(n%7==0){
            for(int i=1;i<=n/7;i++) cout <<8;
            puts(""); return 0;
        }if(n%7==1){
            cout << "10"; n-=8;
            for(int i=1;i<=n/7;i++) cout <<8;
            puts(""); return 0;
        }
        s="";
        dfs(n,0,"");
        cout << (mins!="9999999999999999999999999999999"?mins:"-1") <<'\n';
    }
    return 0;
}
