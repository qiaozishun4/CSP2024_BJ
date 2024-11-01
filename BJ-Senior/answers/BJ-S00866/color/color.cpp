#include<bits/stdc++.h>
using namespace std;
int mp[1000010];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);

    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,cnt=0;
        cin>>n;
        memset(mp,0,sizeof(mp));
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
            mp[x]++;
        }
        for(int j=1;j<=1000000;j++){
            if(mp[j])cnt+=(mp[j]-1)*j;
        }
        cout<<cnt;
        if(i<t) cout<<endl;
    }
    return 0;
}