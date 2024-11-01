#include<bits/stdc++.h>
using namespace std;
bool b[10][15];
int n,sum;
map<char,int> t;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    t['A']=1,t['2']=2,t['3']=3,t['4']=4,t['5']=5;
    t['6']=6,t['7']=7,t['8']=8,t['9']=9,t['T']=10;
    t['J']=11,t['Q']=12,t['K']=13;
    t['D']=1,t['C']=2,t['H']=3,t['S']=4;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        b[t[s[0]]][t[s[1]]]=1;
    }
    for(int i=1;i<=4;i++){
        for(int j=1;j<=13;j++){
            if(!b[i][j]){
                sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}

