#include<iostream>
#include<cstdio>
#include<unordered_map>
using namespace std;
unordered_map<string,bool> mp;
string a="A23456789TJQK";
string b="DCSH";
string c[60];
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int len=0;
    for(int i=0;i<13;i++){
        for(int j=0;j<4;j++){
            c[++len]=b[j];
            c[len]+=a[i];
        }
    }
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        string str;
        cin>>str;
        mp[str]=true;
    }
    int cnt=0;
    for(int i=1;i<=len;i++){
        if(!mp[c[i]])cnt++;
    }
    cout<<cnt<<'\n';
    return 0;
}
