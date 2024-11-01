#include<bits/stdc++.h>
using namespace std;
const int N=1e5 + 5;
int n,ans,a[N],r[N],b[N];
void DFS(int x,int lr,int lb){
    if(x>n){
        int sum=0;
        for(int i=1;i<lr;++i){
            if(r[i]==r[i+1])sum+=r[i];
        }
        for(int i=1;i<lb;++i){
            if(b[i]==b[i+1])sum+=b[i];
        }
        ans=max(ans,sum);
        return;
    }
    r[++lr]=a[x];
    DFS(x+1,lr,lb);
    r[lr--]=0;
    b[++lb]=a[x];
    DFS(x+1,lr,lb);
    b[lb--]=0;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    for(int j=1;j<=t;++j){
        cin>>n;
        for(int i=1;i<=n;++i){
            cin>>a[i];
        }
        DFS(1,0,0);
        cout<<ans<<'\n';
        ans=0;
    }
    return 0;
}
