#include<bits/stdc++.h>
using namespace std;
bool f[6][15];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        char a,b;
        cin>>a>>b;
        if(b=='A')b='1';
        else if(b=='T')b='9'+1;
        else if(b=='J')b='9'+2;
        else if(b=='Q')b='9'+3;
        else if(b=='K')b='9'+4;
        if(a=='D')a='1';
        else if(a=='C')a='2';
        else if(a=='H')a='3';
        else a='4';
        f[(int)a-'0'][(int)b-'0']=1;
    }
    int s=52;
    for(int i=1;i<=4;i++)
        for(int j=1;j<=13;j++)
            if(f[i][j])s--;
    cout<<s;
    return 0;
}