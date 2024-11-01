#include<bits/stdc++.h>
using namespace std;
bool l[100];
int ans,n;
string x;
int h(char a,char b){
    int c;
    if(a=='D')c=0;
    if(a=='C')c=1;
    if(a=='H')c=2;
    if(a=='S')c=3;

    c*=13;

    if(b>'0'&&b<='9')c+=b-'0';
    if(b=='A')c+=1;
    if(b=='T')c+=10;
    if(b=='J')c+=11;
    if(b=='Q')c+=12;
    if(b=='K')c+=13;
    return c;

}

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        l[h(x[0],x[1])]=true;
    }
    for(int i=1;i<=52;i++){
        if(l[i]==false)ans++;
    }
    cout<<ans;
    return 0;
}
