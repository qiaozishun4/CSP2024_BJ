#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    map<pair<char,int>,bool>mp;
    for(int i=1;i<=4;++i){
        pair<char,int>p;
        if(i==1) p.first='D';
        if(i==2) p.first='C';
        if(i==3) p.first='H';
        if(i==4) p.first='S';
        for(int i=1;i<=13;++i){
            p.second=i;
            mp[p]=false;
        }
    }
    for(int i=0;i<n;++i){
        string s;
        cin>>s;
        pair<char,int>p;
        p.first=s[0];
        if(s[1]<='9'){
            p.second=int(s[1]-'0');
        }else if(s[1]=='A'){
            p.second=1;
        }else if(s[1]=='J'){
            p.second=11;
        }else if(s[1]=='Q'){
            p.second=12;
        }else if(s[1]=='K'){
            p.second=13;
        }else{
            p.second=10;
        }

        mp[p]=true;
    }
    int cnt=0;
    for(auto e:mp){
        if(e.second==false){
            ++cnt;
        }
    }
    cout<<cnt;
}
