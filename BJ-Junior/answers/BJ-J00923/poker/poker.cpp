#include<bits/stdc++.h>
using namespace std;
map<char,int>p;
string s;
int n,cnt,a[5][50];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    p['D']=1;
    p['C']=2;
    p['H']=3;
    p['S']=4;
    p['A']=1;
    p['2']=2;
    p['3']=3;
    p['4']=4;
    p['5']=5;
    p['6']=6;
    p['7']=7;
    p['8']=8;
    p['9']=9;
    p['T']=10;
    p['J']=11;
    p['Q']=12;
    p['K']=13;
    cin>>n;
    while(n--){
        cin>>s;
        a[p[s[0]]][p[s[1]]]=1;
    }
    for(int i=1;i<5;i++)
        for(int j=1;j<14;j++)
            if(!a[i][j])cnt++;
    cout<<cnt;
    return 0;
}