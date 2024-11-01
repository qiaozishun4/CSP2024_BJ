#include<bits/stdc++.h>
using namespace std;
int r[100005]={0};
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,a,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        r[a]++;
    }
    for(int i=1;i<100000;i++){
        if(r[i]>r[i+1]){
            ans=ans+r[i+1];
            r[i+1]=r[i];
        }
        else{
            ans=ans+r[i];
        }
    }
    cout<<n-ans<<endl;
    return 0;
}
