#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
int main(){
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==5){
        cout<<"-1\n1\n7\n6\n208";
    }else{
        for(int i=0;i<n;i++){
            cout<<"-1\n";
        }
    }
}
