#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
bool f2[100005];
bool h2[100005];
int fb(){
    int ans=n;
    int s=1;
    for(int i=n;i>0;i--){
        if(a[i]==a[n])continue;
        if(a[i]>a[s]&&f2[i]&&h2[s]){
            f2[i]=false;
            h2[s]=false;
            s++;
            ans--;
        }
    }
    for(int i=n;i>0;i--){
        if(a[i]!=a[n])break;
        for(int j=1;j<=n;j++){
            if(a[i]>a[j]&&f2[i]&&h2[j]){
                f2[i]=false;
                h2[j]=false;
                ans--;
            }
        }

    }
    return ans;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f2[i]=true;
        h2[i]=true;
    }
    sort(a+1,a+n+1);
    //for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    cout<<fb()<<endl;
    return 0;
}
