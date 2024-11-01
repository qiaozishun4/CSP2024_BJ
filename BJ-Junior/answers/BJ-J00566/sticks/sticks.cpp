#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

long long t,n,a[10]={6,2,5,5,4,5,6,3,7,6};
string ans;

bool f(string s1,string s2){
    if(s1.size()==s2.size()){
        return s1>s2;
    }
    return s1.size()>s2.size();
}

void dfs(long long ind,long long c,string s){
    if(c>n){
        return ;
    }
    if(ans!="-1"&&f(s,ans)){
        return ;
    }
    if(c==n){
        if(ans=="-1"||f(ans,s)){
            ans=s;
        }
        return ;
    }
    for(long long i=0;i<10;i++){
        if(ind==1&&i==0){
            continue;
        }
        dfs(ind+1,c+a[i],s+char(i+'0'));
    }
}

int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        ans="-1";
        dfs(1,0,"");
        cout<<ans<<endl;
    }
    return 0;
}
