#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
bool c[N];//0red 1blue
int T,n,a[N],w[N],ans[N];
void DFS(int x){
    if(x>n){
        return;
    }
    c[x]=1;
    for(int i=n;i>=1;i--){
        if(c[x]!=c[i]){
            w[x]=0;
        }
        else{
            if(a[x]==a[i]){
                w[x]=a[x];
                ans[x]+=w[x];
            }
        }
    }
    DFS(x+1);
    return;
}
void Main(){
    memset(w,0,sizeof w);
    memset(c,0,sizeof c);
    memset(ans,0,sizeof ans);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    DFS(1);
    int mx=0;
    for(int i=1;i<=n;i++){
        if(ans[i]>=mx)mx=ans[i];
    }
    cout<<mx<<endl;

}
int main(){
    freopen("color1.in","r",stdin);
    //freopen("color.out","w",stdout);
    cin>>T;
    while(T--){
        Main();
    }
    return 0;
}
