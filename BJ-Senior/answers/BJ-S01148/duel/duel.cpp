#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[100001];
int h[100001];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        h[a[i]]++;
    }
    int maxn=0;
    for(int i=1;i<=100000;i++){
        maxn=max(maxn,h[i]);
    }
    cout<<maxn<<endl;
    return 0;
}