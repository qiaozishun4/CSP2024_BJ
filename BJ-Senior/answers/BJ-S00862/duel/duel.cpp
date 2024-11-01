#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n,a[N],b[N],sum[N];
map<int,int> mp;
void subtask3(){
    sort(a+1,a+n+1);
    int ans=0,cnt=0,tot=0;
    b[++cnt]=a[1];
    mp[a[1]]++;
    for(int i=2;i<=n;i++){
        if(a[i]!=a[i-1]){
            b[++cnt]=a[i];
        }
        mp[a[i]]++;
    }
    for(int i=1;i<=cnt;i++){
        sum[i]=sum[i-1]+mp[b[i]];
    }
    for(int i=1;i<=cnt;i++){
        if(mp[b[i]]<(sum[i-1]-tot)){
            ans=ans+mp[b[i]];
            tot=tot+mp[b[i]];
        }
        else{
            ans=ans+(sum[i-1]-tot);
            tot=tot+(sum[i-1]-tot);
        }
    }
    cout<<n-ans<<endl;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    subtask3();
    return 0;
}