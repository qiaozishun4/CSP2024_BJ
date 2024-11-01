#include <bits/stdc++.h>
using namespace std;
int vis[10][20];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    char tp,num;
    while(n--){
        cin>>tp>>num;
        int t=0,t2=0;
        if(tp=='D')t=0;
        else if(tp=='C')t=1;
        else if(tp=='H')t=2;
        else if(tp=='S')t=3;
        if(num=='T')t2=10;
        else if(num=='A')t2=0;
        else if(num=='J')t2=11;
        else if(num=='Q')t2=12;
        else if(num=='K')t2=13;
        else t2=num-'0';
        vis[t][t2]=1;
    }
    int ans=52;
    for(int i=0;i<4;i++){
        for(int j=0;j<14;j++){
            if(vis[i][j]==1)ans--;

        }
    }
    cout<<ans;
    return 0;
}
