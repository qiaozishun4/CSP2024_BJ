#include <bits/stdc++.h>
using namespace std;
long long int n;
vector<vector<int>> a;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    a.resize(4,vector<int>(13,0));
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(s[0]=='D'){
            s[0]='0';
        }else if(s[0]=='C'){
            s[0]='1';
        }else if(s[0]=='S'){
            s[0]='2';
        }else if(s[0]=='H'){
            s[0]='3';
        }
        if(s[1]=='A'){
            a[s[0]-'0'][0]=1;
        }
        else if(s[1]=='T'){
            a[s[0]-'0'][9]=1;
        }else if(s[1]=='J'){
            a[s[0]-'0'][10]=1;
        }else if(s[1]=='Q'){
            a[s[0]-'0'][11]=1;
        }else if(s[1]=='K'){
            a[s[0]-'0'][12]=1;
        }else{
            a[s[0]-'0'][s[1]-'1']=1;
        }
    }
    long long ans=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            ans+=a[i][j];
        }
    }
    cout<<52-ans<<'\n';
    return 0;
}