#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
bool s[N][N];
int cnt=52;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string t;
        cin>>t;
        char a=t[1],b=t[0];
        int c=0,d=0;
        if(a=='A')c=1;
        else if(a=='T')c=10;
        else if(a=='J')c=11;
        else if(a=='Q')c=12;
        else if(a=='K')c=13;
        else c=a-'0';
        if(b=='D')d=1;
        else if(b=='C')d=2;
        else if(b=='H')d=3;
        else if(b=='S')d=4;
        if(s[c][d]==0)cnt--;
        s[c][d]=1;
    }
    cout<<cnt;
    return 0;
}
