#include<bits/stdc++.h>
using namespace std;
int T;
int n,k,q;
int r[1005][2005];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;++i){
            int tmp;
            cin>>tmp;
            for(int j=1;j<=tmp;++j){
                cin>>r[i][j];
                r[i][j+1]=-1;
            }
        }
        while(q--){
            int tmp1,tmp2;
            cin>>tmp1>>tmp2;
            int tmp3=114514,tmp4=0;
            bool flag=0;
            for(int i=1;i<=n;++i){
                for(int j=1;r[i][j]!=-1;++j){
                    if(r[i][j]==1)tmp3=j;
                    if(r[i][j]==tmp2){
                        if(j-tmp3<=k){
                            cout<<1<<endl;
                            flag=1;
                            break;
                        }
                    }
                }
                if(flag)break;
                tmp3=114514;
            }
            if(!flag)cout<<0<<endl;
        }
    }
    return 0;
}
