#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i = 0;i<n;i++){
        int t;
        cin>>t;
        a[t]++;
    }
    int s = 0;
    for(int i = 0;i<=10000;i++){
        s-=a[i];
        if(s<0){
            s = 0;
        }
        s+=a[i];
    }
    cout<<s;
    return 0;
}