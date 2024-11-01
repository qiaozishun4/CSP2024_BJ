#include<bits/stdc++.h>
using namespace std;
int pk[20][20],h,nu,le=52;
long long int n;
string s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        if(s[0]=='D') h=1;
        else if(s[0]=='C') h=2;
        else if(s[0]=='H') h=3;
        else if(s[0]=='S') h=4;
        if(s[1]<='9'&&s[1]>='2'){
            nu=s[1]-'0';
        }else if(s[1]=='T') nu=10;
        else if(s[1]=='J') nu=11;
        else if(s[1]=='Q') nu=12;
        else if(s[1]=='K') nu=13;
        else if(s[1]=='A') nu=1;
        if(pk[h][nu]==0){
            pk[h][nu]++;
            le--;
            //cout<<h<<" "<<nu<<" "<<pk[h][nu]<<endl;
        }
    }
    cout<<le;
    return 0;
}
/*
D 代表方片,字符 C 代表草花,字符 H 代表红
桃,字符 S 代表黑桃
*/
