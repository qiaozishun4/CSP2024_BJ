#include<bits/stdc++.h>
using namespace std;
int a[4][30];
int fn(char c){
    if(c=='D')return 0;
    if(c=='C')return 1;
    if(c=='H')return 2;
    if(c=='S')return 3;
}
int fn1(char c){
    if(c=='A')return 1;
    if(c=='2')return 2;
    if(c=='3')return 3;
    if(c=='4')return 4;
    if(c=='5')return 5;
    if(c=='6')return 6;
    if(c=='7')return 7;
    if(c=='8')return 8;
    if(c=='9')return 9;
    if(c=='T')return 10;
    if(c=='J')return 11;
    if(c=='Q')return 12;
    if(c=='K')return 13;
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    char x,y;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        a[fn(x)][fn1(y)]++;
    }
    int ans=0;
    for(int i=0;i<4;i++)for(int j=1;j<=13;j++)if(a[i][j]==0)ans++;
    cout<<ans;
    return 0;
}
