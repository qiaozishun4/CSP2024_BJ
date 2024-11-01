#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb emplace_back
bool a[5][15];
int cnt;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    char c,d;
    int x,y;
    while(n--){
        cin>>c>>d;
        if(c=='D') x=1;
        else if(c=='C') x=2;
        else if(c=='H') x=3;
        else x=4;
        if(d=='A') y=1;
        else if(d=='T') y=10;
        else if(d=='J') y=11;
        else if(d=='Q') y=12;
        else if(d=='K') y=13;
        else y=d-'0';
        a[x][y]=1;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!a[i][j]) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
