#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#define For(v,s,e) for(int v=s;v<=e;v++)
using namespace std;
map<string,int> s;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    vector<string> w;
    cin>>n;
    For(i,1,n){
        string p;
        cin>>p;
        if(s[p]==0)
        w.push_back(p),s[p]=1;
    }
    cout<<52-w.size();
    return 0;
}
