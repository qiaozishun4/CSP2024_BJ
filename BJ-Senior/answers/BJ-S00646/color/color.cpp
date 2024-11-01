#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;
int t,n;
int a[N];
bool c[N];
int ma=0;

void cul(){
    int ans=0;
    for(int i=2;i<=n;i++){
        for(int j=i-1;j>=1;j--){
            if(c[i]==c[j]){
                if(a[i]==a[j]){
                    ans+=a[i];
                }
                break;
            }
        }
    }
    ma=max(ma,ans);
}

void dfs(int x){
    if(x>=n+1){
        cul();
        return;
    }
    c[x]=false;
    dfs(x+1);
    c[x]=true;
    dfs(x+1);
}

int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        ma=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(n==1){
            cout<<0<<endl;
            continue;
        }
        dfs(2);
        cout<<ma<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
