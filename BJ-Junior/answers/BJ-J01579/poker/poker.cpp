#include <bits/stdc++.h>
using namespace std;
map<string,bool> m;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n,c=0;scanf("%d",&n);
    string a="DCHS",b="A23456789TJQK";
    for(int i=1;i<=n;++i){
        string s;cin >> s;
        m[s]=1;
    }
    for(auto i:a){
        for(auto j:b){
            string s="";
            s+=i;s+=j;
            if(!m[s])++c;
        }
    }
    printf("%d",c);
    return 0;
}