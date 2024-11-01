#include<bits/stdc++.h>
using namespace std;
int n;
int Min=1e9;
int cnt;
const int N=3e6;
int k[N];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>k[i];
        if(k[i]<Min){Min=k[i],cnt=1;}
        else if(k[i]==Min)cnt++;
    }
    cout<<max(n-cnt,cnt);
    fclose(stdin);
    fclose(stdout);
}
