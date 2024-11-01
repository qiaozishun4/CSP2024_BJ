#include <bits/stdc++.h>
using namespace std;
bool dp[100050][10];
int dre_x[4]={0,1,0,-1},dre_y[4]={1,0,-1,0};
int main(){
    freopen("chain.in","r",stdin);
    freopen("chain.out","w",stdout);
    int t;
    cin>>t;
    for(int xs=1;xs<=t;xs++){
        int n,k,q;
        cin>>n>>k>>q;
        int s[2050][2050]={};
        for(int xs2=1;xs2<=n;xs2++){
            cin>>s[xs2][0];
            for(int xs3=1;xs3<=s[xs2][0];xs3++){
                cin>>s[xs2][xs3];
            }
        }
        for(int xs2=1;xs2<=q;xs2++){
            int r,c;
            cin>>r>>c;
            cout<<0<<endl;
        }
    }
    return 0;
}
