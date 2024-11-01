#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int t, n, f[100005];
int s[]={6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int dfs(int stk, int num){
    if(stk>n) return 2e9;
    if(stk==n) return num;
    int v=2e9;
    for(int i=0;i<=9;i++){
        if(i==0&&stk==0)
            continue;
        v=min(v, dfs(stk+s[i], num*10+i));
    }
    return v;
}

int main(){
    freopen("sticks.in", "r", stdin);
    freopen("sticks.out", "w", stdout);
    cin>>t;
    for(int h=1;h<=t;h++){
        cin>>n;
        if(n<=20){
            int x=dfs(0, 0);
            if(x==2e9) cout<<-1<<endl;
            else cout<<x<<endl;
            continue;
        }
        memset(f, 0, sizeof f);
        for(int i=0;i<=9;i++)
            for(int j=s[i];j<=n;j++)
                f[j]=max(f[j], f[j-s[i]]*10+i);
        if(f[n]>=1e9) cout<<-1<<endl;
        else cout<<f[n]<<endl;
    }
    return 0;
}
