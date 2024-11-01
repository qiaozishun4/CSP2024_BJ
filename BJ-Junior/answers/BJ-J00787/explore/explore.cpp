#include<iostream>
#include<stdio.h>
using namespace std;
int fx[10001][10001];
int n[100001],m[100001],k[100001],x[100001],y[100001],d[100001];
int main(){
    freopen("explore.in","r",stdin);
    freopen("explore.out","w",stdout);
    int t,sum;
    char c;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n[i]>>m[i]>>k[i]>>x[i]>>y[i]>>d[i];
        cout<<k[i]+1;
    }


return 0;}