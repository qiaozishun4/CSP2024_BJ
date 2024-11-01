#include<iostream>
#include<cstdio>
using namespace std;
int t,n,k,q,l[100005],s[1005][2005];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++) cin>>s[i][j];
        }
        while(q--){
            int r,c;
            cin>>r>>c;
            if(r==1){
                bool flag=false;
                for(int i=1;i<=n;i++){
                    for(int p1=1;p1<=l[i];p1++){
                        if(s[i][p1]==1) for(int pc=p1+1;pc<=min(p1+k-1,l[i]);pc++) if(s[i][pc]==c){flag=true;break;}
                        if(flag) break;
                    }
                    if(flag) break;
                }
                cout<<flag<<endl;
            }else cout<<0<<endl;//bu4 ke3 yi3 , zong3 si1 ling4
        }
    }
    return 0;
}