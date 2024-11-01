#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
string s[57];
bool cmp(string x,string y){
    if(x[0]!=y[0]) return x[0]<y[0];
    else{
        return x[1]<y[1];
    }
}
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>s[i];
    sort(s+1,s+1+n,cmp);
    int cnt=1;
    for(int i=2;i<=n;i++)
        if(s[i]!=s[i-1]) cnt++;
    cout<<52-cnt<<endl;
    return 0;
}
