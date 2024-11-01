#include<bits/stdc++.h>
using namespace std;

int l[10000],qian[10000],hou[100000];
int mp[1000005];
int n;
int sum=0;
int dfs(int p,int r,int b){
    if(p>n)
        return sum;
    int ans=sum;
    if(l[qian[p]]==l[b]&&qian[p]){
        sum+=l[b];
        ans=dfs(p+1,r,p);
        sum-=l[b];
        return ans;
    }
    if(l[qian[p]]==l[r]&&qian[p]){
        sum+=l[r];
        ans=dfs(p+1,p,b);
        sum-=l[r];
        return ans;
    }

    if(hou[r]==0)
        return dfs(p+1,p,b);
    if(hou[b]==0)
        return dfs(p+1,r,p);

    return max(dfs(p+1,r,p),dfs(p+1,p,b));
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        memset(qian,0,sizeof(qian));
        memset(hou,0,sizeof(hou));
        memset(mp,0,sizeof(mp));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            if(mp[l[i]]){
                qian[i]=mp[l[i]];
                hou[mp[l[i]]]=i;
            }
            mp[l[i]]=i;
        }
        cout<<dfs(2,1,0)<<endl;
    }
    return 0;
}
