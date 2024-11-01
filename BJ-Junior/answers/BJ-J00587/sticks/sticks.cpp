#include<bits/stdc++.h>
using namespace std;
int t,n;
long long mi;
int f[10]={-1,-1,1,7,4,2,6,8};
vector<int> v;
void dfs(int k,int l){

    if(k==0){
        vector<int> t=v;
        sort(t.begin(),t.end());
        long long cnt=t[0];
        for(int i=1;i<t.size();i++){
            if(t[i]==6){
               t[i]=0;
            }
            cnt=cnt*10+t[i];
        }
        mi=min(abs(cnt),mi);
    }
    for(int i=l;i<=7;i++){
        if(k>=i){
            v.push_back(f[i]);
            dfs(k-i,i);
            v.pop_back();
        }
    }
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        mi=LONG_LONG_MAX;
        if(n<=7){
            printf("%d\n",f[n]);
        }else{
            v.clear();
            dfs(n,2);
            printf("%lld\n",mi);
        }
    }
    return 0;
}
