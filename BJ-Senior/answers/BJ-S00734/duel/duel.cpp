#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
bool cmp(int c,int d){
    return c<d;
}
bool vis[N],used[N];
int n,a[N],ans,xxx,kkk/*,t=1,j=1*/;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1)xxx++;
        if(a[i]==2)kkk++;
    }
    if(xxx+kkk==n){
        //cout<<"kkk: "<<kkk<<" xxx: "<<xxx<<endl;
        cout<<max(kkk,xxx)<<endl;
        exit(0);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(!used[i]){
            for(int j=i;j>=1;j--){
                if(a[i]>a[j]&&!vis[i]&&!used[j]){
                    used[j]=1,vis[i]=1;
                    //cout<<"i: "<<i<<" j: "<<j<<endl;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(!used[i])ans++;
    }
    cout<<ans<<endl;
    return 0;
}
