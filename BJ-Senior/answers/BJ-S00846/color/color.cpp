#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int T;
int n,a[N];
map<int,int>mp;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--){
        mp.clear();
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(!mp[a[i]]){
                mp[a[i]]=1;
            }else{
                ans+=a[i];
                mp[a[i]]=0;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
