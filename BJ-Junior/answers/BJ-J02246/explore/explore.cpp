#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int T;cin>>T;
    while(T--){
        int n,m,k;
        int x,y,d;
        cin>>n>>m>>k>>x>>y>>d;
        if(d==2||d==3||d==0){cout<<n*m-(n-2)*(m-2)-1<<endl;continue;}
        if(d==1){cout<<m-y<<endl;}

    }
    return 0;
}
