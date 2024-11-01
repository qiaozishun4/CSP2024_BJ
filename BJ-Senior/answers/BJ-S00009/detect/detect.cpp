#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m,l,v,d[100001],vv[100001],a[100001];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    cin>>t;
    cin>>n>>m>>l>>v;
    for(int i=0;i<n;i++){
        cin>>d[i]>>vv[i]>>a[i];
    }
    for(int i=0;i<m;i++)cin>>p[i];
    int cnt=0;
    for(int i=0;i<n;i++){
        if(vv[i]>v)cnt+=1;
    }cout<<cnt<<" "<<m-1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}