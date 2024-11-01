#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int hsh(char a,char b){
    int ret=0;
    if(a=='D')ret+=0;
    else if(a=='C')ret+=14;
    else if(a=='H')ret+=28;
    else if(a=='S')ret+=42;
    
    if('1'<=b&&b<='9')ret+=b-'0';
    else if(b=='T')ret+=10;
    else if(b=='J')ret+=11;
    else if(b=='Q')ret+=12;
    else if(b=='K')ret+=13;
    return ret;    
}
bool vis[77];
signed main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    int IL=0;
    while(n--){
        char A,B;
        cin>>A>>B;
        int t=hsh(A,B);
        if(!vis[t])IL++;
        vis[t]=1;
    }
    cout<<52-IL<<endl;
    return 0;
}