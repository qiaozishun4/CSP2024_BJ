#include<iostream>
using namespace std;
#define int long long
bool a[4][13];
int n;
char b[2];
void inst(int x){
    int y;
    if(b[1]>='2'&&b[1]<='9') y=b[1]-'0';
    else if(b[1]=='A') y=0;
    else if(b[1]=='T') y=1;
    else if(b[1]=='J') y=10;
    else if(b[1]=='Q') y=11;
    else if(b[1]=='K') y=12;
    a[x][y]=1;
}

void fun(){
    cin>>n;
    while(n--){
        getchar();
        scanf("%c%c",&b[0],&b[1]);
        if(b[0]=='D') inst(0);
        else if(b[0]=='C') inst(1);
        else if(b[0]=='H') inst(2);
        else if(b[0]=='S') inst(3);
    }
}
signed main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    fun();
    int ans=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            if(a[i][j]==0) ans++;
        }
    }
    cout<<ans;
    return 0;
}
