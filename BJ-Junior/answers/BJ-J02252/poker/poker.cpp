#include<bits/stdc++.h>
using namespace std;
bool check[5][14];
int ans=52;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,ta,tb;
    char a,b;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        if(a=='D')ta=1;
        else if(a=='C')ta=2;
        else if(a=='H')ta=3;
        else if(a=='S')ta=4;
        if(b=='T')tb=10;
        else if(b=='J')tb=11;
        else if(b=='Q')tb=12;
        else if(b=='K')tb=13;
        else if(b=='A')tb=1;
        else tb=int(b-'0');
        if(!check[ta][tb])ans--,check[ta][tb]=1;
    }
    cout<<ans;
    return 0;
}
