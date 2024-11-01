#include <bits/stdc++.h>
using namespace std;
int t,n,cnt[20]={6,2,5,5,4,5,6,3,7,6};
int a[100],cn,maxn;
string dp[200000];
bool cmp(string a,string b){
    if(a.size()>b.size()) return 1;
    else if(a.size()<b.size()) return 0;
    else{
        return a>b;
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        maxn=max(maxn,n);
        a[++cn]=n;
    }
    string maxx="";
    for(int i=1;i<=20000;i++){
        maxx+='9';
    }
    for(int i=0;i<=maxn;i++){
        dp[i]=maxx;
    }
    for(int i=9;i>=1;i--){
       dp[cnt[i]]=i+'0';
    }
    for(int i=1;i<=maxn;i++){
        for(int j=0;j<=9;j++){
            if(i>=cnt[j]){
                string res=dp[i-cnt[j]]+char(j+'0');
                if(cmp(dp[i],res) && dp[i-cnt[j]]!=maxx){
                    dp[i]=res;
                }
            }
        }
    }
    for(int i=1;i<=cn;i++){
        if(dp[a[i]]==maxx){
            cout<<-1<<endl;
        }else{
            cout<<dp[a[i]]<<endl;
        }
    }
    return 0;
}

