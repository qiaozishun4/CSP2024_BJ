#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],to[N],n;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],to[a[i]]++;
    int should_be_eaten=0;
    int ans=0;
    for(int i=1;i<=100003;i++){
        should_be_eaten+=to[i-1];
        ans+=min(should_be_eaten,to[i]);
        if(should_be_eaten>to[i]){
            should_be_eaten-=to[i];
        }
        else{
            should_be_eaten=0;
        }
    }
    cout<<n-ans<<endl;
    return 0;
}
