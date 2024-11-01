#include<bits/stdc++.h>
using namespace std;
const int N=1e7+5;
int s[N],b[N];
int n;
int dfs(int x,int cnt){
    if(x==n+1)return cnt;
    int Max=0;
    for(int i=0;i<2;i++){
        b[x]=i;
        int p=0;
        for(int j=x-1;j>=1;j--){
            if(b[j]==i){
                if(s[j]==s[x]){
                    p=s[x];
                }
                break;
            }
        }
        Max=max(Max,dfs(x+1,cnt+p));
        b[x]=0;
    }
    return Max;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>s[i];
        }
        memset(b,-1,sizeof(b));
        cout<<dfs(1,0)<<endl;
    }
    return 0;
}
