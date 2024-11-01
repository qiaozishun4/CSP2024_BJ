#include <bits/stdc++.h>
using namespace std;

const int N=1e5+5,num[10]={6,2,5,5,4,5,6,3,7,6};
int ans[N];
bool flag;
void dfs(int x,int now) {
    //cout<<"ok"<<endl;
    if(x==0) {
        for(int i=1;i<now;i++) cout<<ans[i];
        cout<<endl;
        flag=true;
        return;
    }
    int st=0;
    if(now==1) st=1;
    for(int i=st;i<10;i++) {
        if(x-num[i]!=1) {
            ans[now]=i;
            dfs(x-num[i],now+1);
            if(flag) return;
        }
    }
    return;
}
int main() {
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int T,n;
    cin>>T;
    while(T--) {
       flag=false;
       cin>>n;
       dfs(n,1);
       if(!flag) cout<<-1<<endl;
    }
    return 0;
}
