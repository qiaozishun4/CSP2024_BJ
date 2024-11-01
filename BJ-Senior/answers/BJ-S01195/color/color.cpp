#include <bits/stdc++.h>

using namespace std;

struct node{
    int w,a;
} a[1000005];
int pre[1000005];
long long c[1000005];

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int T;
    cin>>T;
    long long maxn=-1;
    while(T--){
        int n;
        cin>>n;
        memset(pre,-1,sizeof(pre));
        memset(c,0,sizeof(c));
        int cnt=0;
        for(int i=1;i<=n;i++){
            int a;
            cin>>a;
            if(pre[a]==-1){
                c[i]=c[i-1];
                pre[a]=i;
                continue;
            }
            if(pre[a]==i-1)c[i]=c[pre[a]]+a;
            else c[i]=max(max(c[pre[a]],c[pre[a]+1])+a,c[i-1]);
            pre[a]=i;
            maxn=max(c[i],maxn);
        }
        cout<<maxn<<endl;
    }
    return 0;
}
