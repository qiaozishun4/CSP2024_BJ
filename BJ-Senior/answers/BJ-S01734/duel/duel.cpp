#include<bits/stdc++.h>
using namespace std;

int a[114514];

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    int now=0;
    for(int i=1;i<n;i++)
        if(a[i]>a[now])
            now++;
    cout<<n-now<<endl;
    return 0;
}