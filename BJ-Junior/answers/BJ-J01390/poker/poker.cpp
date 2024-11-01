#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("poker.in","r",stdin);
freopen("poker.out","w",stdout);
int n,sum=0;
char a[60],b[60],c[60],d[60];
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i]>>b[i];
    for(int j=1;j<=sum;j++){
        if(a[i]==c[j]&&b[i]==d[j])continue;
        else {
        c[sum]=a[i];
        d[sum]=b[i];
        sum++;
        }
    }
}
cout<<52-sum;
return 0;
}
