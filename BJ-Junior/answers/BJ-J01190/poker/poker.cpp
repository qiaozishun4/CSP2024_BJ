#include <bits/stdc++.h>
using namespace std;
bool have[205];
int cti(char c){
    if(c>='0'&&c<='9')return c-'1';
    else{
        if(c=='A')return 0;
        else if(c=='T')return 9;
        else if(c=='J')return 10;
        else if(c=='Q')return 11;
        else if(c=='K')return 12;
        else return 100;
    }
}
int pti(string s){
    if(s.size()==2){
        char hs=s[0],num=s[1];
        if(hs=='D')return cti(num);
        else if(hs=='C')return 13+cti(num);
        else if(hs=='H')return 26+cti(num);
        else return 39+cti(num);
    }else return 100;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        have[pti(s)]=true;
    }
    int ans=0;
    for(int i=0;i<52;i++){
        if(!have[i])ans++;
    }
    cout<<ans;
    return 0;
}
