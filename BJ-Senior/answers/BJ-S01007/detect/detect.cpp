#include<bits/stdc++.h>
using namespace std;
int d[100000];
int v[100000];
int i[100000];
int main(){
    freopen("detect.in","r",stdin);
    freopen("detect.out","w",stdout);
    int T;
    int count = 0;
    cin>>T;
    for(int i = 0;i<T;i++){
        cin>>d[i]>>v[i]>>a[i];
    }
    if((v[i]<V||v[i]==V)&&(a[i]<0||a[i]==0)){
        count++;
    }
    cout<<count<<2;
    return 0;
    }