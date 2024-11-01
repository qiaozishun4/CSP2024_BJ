#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
int n;
char c1[5];
char c2[14];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    c1[1]='D';
    c1[2]='C';
    c1[3]='H';
    c1[4]='S';
    c2[1]='A';
    c2[2]='2';
    c2[3]='3';
    c2[4]='4';
    c2[5]='5';
    c2[6]='6';
    c2[7]='7';
    c2[8]='8';
    c2[9]='9';
    c2[10]='T';
    c2[11]='J';
    c2[12]='Q';
    c2[13]='K';
    for(int i=1;i<=n;++i){
        string s;
        cin>>s;
        mp[s]++;
    }
    int ans=0;
    for(int i=1;i<=4;++i)
        for(int j=1;j<=13;++j){
            string s="";
            s+=c1[i];
            s+=c2[j];
            if(!mp[s]) ++ans;
        }
    cout<<ans;
    return 0;
}
