#include<bits/stdc++.h>
using namespace std;
map<int,int>mp[6][200010];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    for(int p=1;p<=t;p++){
        int n,k,q;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            int l;
            cin>>l;
            for(int j=1;j<=l;j++){
                int x;
                cin>>x;
                mp[p][i][x]=1;
            }
        }
        while(q--){
            int c,r,d=1,la=0;
            cin>>r>>c;
            for(int i=1;i<=r;i++){
                int f=0;
                int an=-1,ma=0;
                for(int i=1;i<=n;i++){
                    if(i==la)continue;
                    int j,k1=0;
                    for(j=d;j<=c;j++){
                        k1++;
                        if(k1==k)break;
                        if(mp[p][i][j]==1){
                            f=1;
                            continue;
                        }
                        break;
                    }
                    if(j>=ma){
                        ma=j;
                        an=i;
                    }
                }
                if(ma==c){
                    cout<<1<<endl;
                    break;
                }
                if(f==0){
                    cout<<0<<endl;
                    break;
                }
                d+=ma;
                la=an;
                if(i==r&&ma<c){
                    cout<<0<<endl;
                    break;
                }
                if(i==r)cout<<1<<endl;
            }
        }
    }
    return 0;
}
