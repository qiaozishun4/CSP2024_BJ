#include<bits/stdc++.h>
using namespace std;
int ANS,T,n;
string MAXN,a,s;
bool cmp(string x,string y){
    return((x.size()!=y.size())?(x.size()>y.size()):(x>y));
}
void dfs(bool f,int x){
    if(x<2){
        if(x==0&&cmp(a,s))a=s;
        return;
    }
    if(x>=2)s+='1',dfs(0,x-2),s.pop_back();
    if(x>=3)s+='7',dfs(0,x-3),s.pop_back();
    if(x>=4)s+='4',dfs(0,x-4),s.pop_back();
    if(x>=5)s+='2',dfs(0,x-5),s.pop_back();
    if(x>=6)s+=(f?'6':'0'),dfs(0,x-6),s.pop_back();
    if(x>=7)s+='8',dfs(0,x-7),s.pop_back();

}
int main(){
    freopen("sticks1.in","r",stdin),freopen("sticks.out","w",stdout);
    for(int i=0;i<50000;i++)MAXN+='1';
    cin>>T;
    while(T--){
        a=MAXN,cin>>n,dfs(1,n);
        if(a==MAXN)cout<<"-1\n";
        else cout<<a<<"\n";
    }
    return 0;
}
