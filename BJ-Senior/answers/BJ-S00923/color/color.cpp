#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int M=1e6+5;
int n,a[N],cn[M];
bool f[N];
long long ans;
int check(int x,int y){
    if (x==y) return x;
    return 0;
}
void DFS(int step,long long cnt,int r,int b){
    if (step>n){
        ans=max(ans,cnt);
        return ;
    }
    DFS(step+1,cnt+check(a[step],r),a[step],b);
    DFS(step+1,cnt+check(a[step],b),r,a[step]);
}
bool chec(int u,int x){
    for (int i=1;i<=u;i++){
        if (a[i]==x) return true;
    }
    return false;
}
void MAIN(){
    ans=0;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        cn[a[i]]++;
    }
    if (n<=20){
        DFS(1,0,-1,-1);
        cout<<ans<<endl;
    }
    else if (n<=2000){
        for (int i=1;i<=n;i++){
            for (int j=i-1;j>=1;j--){
                if (f[j] && chec(j,a[i])){
                    if (a[j]*cn[a[j]]>=a[i]*cn[a[i]]) break;
                    else{
                        for (int k=1;k<=i;k++){
                            if (a[k]==a[j]) f[k]=false;
                        }
                    }
                }
                if (a[i]==a[j]) f[i]=f[j]=true;
            }
        }
        int nowa=-1,nowb=-1;
        for (int i=1;i<=n;i++){
            if (f[i]){
                if (nowa==a[i]) ans+=a[i];
                nowa=a[i];
            }
            else{
                if (nowb==a[i]) ans+=a[i];
                nowb=a[i];
            }
        }
        cout<<ans<<endl;
    }
    else cout<<0<<endl;
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    int t;
    cin>>t;
    while(t--) MAIN();
    return 0;
}
