#include<bits/stdc++.h>
using namespace std;
int a[100005],x[100005];
bool cmp(int p,int b){
    return p<b;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    int p=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        x[a[i]]++;
        p=max(p,a[i]);
    }
    sort(a,a+n,cmp);
    int j=0;
    for(int i=1;i<n-1;i++){
      //      cout<<"be "<<x[a[i]]<<" ";
        if(a[i-1]!=a[i]){
            x[a[i-1]]+=j-x[a[i]];
            if(x[a[i-1]]<0){
                x[a[i-1]]=0;
            }
            j=x[a[i-1]];
        }
   //         cout<<"kn "<<x[a[i]]<<"\n";
    }
    long long ans=0;
    for(int i=0;i<=n;i++){
    //    cout<<x[a[i]]<<"\n";
        if(a[i-1]!=a[i]){
            ans+=x[a[i]];
        }
    }
    cout<<ans;
    return 0;
}
