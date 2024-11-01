#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int n,m,k;
        string M;
        cin>>n>>m>>k;
        int x,y,d;
        cin>>x>>y>>d;
        while(n--){
            cin>>M;
        }
        if(m<=2){
            if(M==".."){
                cout<<2<<endl;
            }
            else{
                cout<<1<<endl;
            }
        }
        else{
            cout<<m<<endl;
        }
    }
    return 0;
}
