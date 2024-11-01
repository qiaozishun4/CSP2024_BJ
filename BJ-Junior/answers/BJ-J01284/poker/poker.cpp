#include<iostream>
#include<cstdio>
using namespace std;
bool a[5][20];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        char c,v;
        cin>>c>>v;
        int x;
        if(v=='A')x=1;
        if('2'<=v&&v<='9'){
            x=v-'0';
        }
        else{
            if(v=='T')x=10;
            if(v=='J')x=11;
            if(v=='Q')x=12;
            if(v=='K')x=13;
        }
        if(c=='D'){
            a[1][x]=1;
        }
        if(c=='C'){
            a[2][x]=1;
        }
        if(c=='H'){
            a[3][x]=1;
        }
        if(c=='S'){
            a[4][x]=1;
        }
    }
    int cnt=0;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!a[i][j])cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
