#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    int x,sum=0;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(a[x]==0){
            b[++sum]=x;
        }
        a[x]++;
    }
    int ans=a[b[1]];
    sort(b+1,b+sum+1);
    for(int i=2;i<=sum;i++){
        if(a[b[i]]>ans)ans=a[b[i]];
    }
    cout<<ans;
    return 0;
}
