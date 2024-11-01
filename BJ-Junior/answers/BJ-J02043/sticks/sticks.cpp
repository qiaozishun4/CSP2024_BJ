#include <bits/stdc++.h>
using namespace std;
long long n,a=0,ans=INT_MAX,flag=-1;
vector<long long int> va;
vector<long long int> num;
void dfs(long long k){
    if(k==0){
        flag=1;
        string s=to_string(a);
        for(int i=1;i<s.size();i++){
            if(s[i]=='6'){
                s[i]='0';
            }
        }
        long long b=0;
        for(int i=0;i<s.size();i++){
            b=b*10+s[i]-'0';
        }
        if(b<ans)ans=b;
        return;
    }
    for(int i=0;i<va.size();i++){
        a=a*10+num[i];
        if(va[i]<=k)dfs(k-va[i]);
        a/=10;
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    va.push_back(2);
    va.push_back(3);
    va.push_back(4);
    va.push_back(5);
    va.push_back(6);
    va.push_back(7);

    num.push_back(1);
    num.push_back(7);
    num.push_back(4);
    num.push_back(2);
    num.push_back(6);
    num.push_back(8);
    long long t;
    cin>>t;
    while(t--){
        cin>>n;
        if(n-7*(n/7)==1&&n!=1){
            cout<<10;
            for(int i=0;i<(n-8)/7;i++)cout<<8;
            cout<<'\n';
        }else if(n-7*(n/7)==0){
            for(int i=0;i<(n/7);i++)cout<<8;
            cout<<'\n';
        }else if(n<=50){
            flag=-1;
            ans=INT_MAX;
            dfs(n);
            if(flag==-1)cout<<-1<<'\n';
            else cout<<ans<<'\n';
        }

    }
    return 0;
}