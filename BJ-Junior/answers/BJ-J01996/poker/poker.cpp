#include<bits/stdc++.h>
using namespace std;
int poke[9][19],n,ans=52;
map<char,int>a;
char x,y;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cin>>n;
    a['A']=1;
    a['2']=2;
    a['3']=3;
    a['4']=4;
    a['5']=5;
    a['6']=6;
    a['7']=7;
    a['8']=8;
    a['9']=9;
    a['T']=10;
    a['J']=11;
    a['Q']=12;
    a['K']=13;
    a['D']=1,a['C']=2,a['H']=3,a['S']=4;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        poke[a[x]][a[y]]=1;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            ans-=poke[i][j];
        }
    }
    cout<<ans;
    return 0;
}
