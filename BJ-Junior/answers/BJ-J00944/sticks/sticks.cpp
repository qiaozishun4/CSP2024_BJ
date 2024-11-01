#include<bits/stdc++.h>
using namespace std;
int a,b[10000001],c,s[10]={6,2,5,5,4,5,6,3,7,6};
int f(int l){
    int cnt=0;
    while(l){
        cnt+=s[l%10];
        l/=10;
    }
    return cnt;
}
int dfs(int t){
    if(t==1){
        return -1;
    }
    int cnt=0;
    for(int i=1;i<=1111111;i++){
        if(f(i)==t) return i;
    }
    return -1;
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>c;
        b[i]=dfs(c);
    }
    for(int i=1;i<=a;i++) cout<<b[i]<<endl;
    return 0;
}
