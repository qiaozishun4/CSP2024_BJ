#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
//          0 1 2 3 4 5 6 7 8 9
int cost[]={6,2,5,5,4,5,6,3,7,6};
string dp[114514];
int nn[114514];
string minn(string a,string b){
    if(a=="inf")return b;
    if(b=="inf")return a;
    if(a.size()>b.size())return b;
    if(b.size()>a.size())return a;
    if(a>b)return b;
    return a;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T;
    cin>>T;
    int maxn=0;
    for(int i=1;i<=T;i++)cin>>nn[i],maxn=max(maxn,nn[i]);

    for(int i=0;i<=maxn;i++)dp[i]="inf";
    dp[0]="";
    for(int i=2;i<=maxn;i++)
        for(int j=0;j<10;j++)
            if(cost[j]<=i&&dp[i-cost[j]]!="inf")
                dp[i]=minn(dp[i],\
                    minn((j==0?"inf":(char)(j+'0')+dp[i-cost[j]]),\
                         (j==0&&dp[i-cost[j]]==""?"inf":dp[i-cost[j]]+(char)(j+'0'))));

    for(int i=1;i<=T;i++){
        int n=nn[i];
        if(dp[n]==""||dp[n]=="inf")cout<<-1<<'\n';
        else cout<<dp[n]<<'\n';
    }
    return 0;
}
/*
5
1
2
3
6
18

*/
