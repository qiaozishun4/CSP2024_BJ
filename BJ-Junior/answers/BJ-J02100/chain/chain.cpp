#include <bits/stdc++.h>
using namespace std;
int T;
int p[1005][1005],l[1005];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        int n,k,q,sum=0;
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            sum+=l[i];
            for(int j=1;j<=l[i];j++){
                cin>>p[i][j];
            }
        }
        for(int i=1;i<=q;i++){
            int r,c;
            cin>>r>>c;
            if(r==1){
                if(c==1){
                    bool flag=false;
                    for(int i=1;i<=n;i++){
                        for(int j=1;j<=l[i];j++){
                            if(p[i][j]==1){
                                flag=true;
                                break;
                            }
                        }
                    }
                    if(flag)cout<<1<<endl;
                    else cout<<0<<endl;
                }else cout<<0<<endl;
            }else if(sum/2<r){
                cout<<0<<endl;
            }else if(int(to_string(c).size())>k){
                cout<<0<<endl;
            }else{
                bool flag=false;
                for(int i=1;i<=n;i++){
                    for(int j=1;j<=l[i];j++){
                        if(p[i][j]==c){
                            flag=true;
                            break;
                        }
                    }
                }
                if(flag)cout<<1<<endl;
                else cout<<0<<endl;
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
