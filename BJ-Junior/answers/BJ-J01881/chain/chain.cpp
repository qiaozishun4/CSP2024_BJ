#include<bits/stdc++.h>
using namespace std;
int t;
int n,k,q,l[100005],s[100005][200005];
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    cin>>t;
    for(int pt=1;pt<=t;pt++){
        cin>>n>>k>>q;
        for(int i=1;i<=n;i++){
            cin>>l[i];
            for(int j=1;j<=l[i];j++){
                cin>>s[i][j];
            }
        }
        for(int i=1;i<=q;i++){
            int r,c;
            cin>>r>>c;
            if(r==1){
                int pan=0;
                for(int j=1;j<=n;j++){
                    for(int op=1;op<=l[j];op++){
                        if(s[j][op]==1){
                            for(int oop=2;oop<=k;oop++){
                                if(s[j][op+oop-1]==c){
                                    cout<<1<<"\n";
                                    pan=1;
                                    break;
                                }
                            }
                        }
                        if(pan==1){
                            break;
                        }
                    }
                    if(pan==1){
                            break;
                        }
                }
            }
        }
    }
    return 0;
}
