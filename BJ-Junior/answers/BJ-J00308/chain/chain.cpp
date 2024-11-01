#include<bits/stdc++.h>
using namespace std;
long long T,a[10005][10005],n,k,q,l,r,c;bool cc[100005];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--){memset(cc,sizeof(cc),0);
            cin>>n>>k>>q;
            for(int i=1;i<=n;i++){
                cin>>l;int o=0;
                for(int j=1;j<=l;j++){
                    cin>>a[i][j];
                    if(o>0 and j-o<k)cc[a[i][j]]=1;
                    if(a[i][j]==1)o=j;

                }

            }



            for(int i=1;i<=q;i++){
                cin>>r>>c;


                if(cc[c])cout<<1<<endl;
                else cout<<0<<endl;


            }


    }




   return 0;


}
