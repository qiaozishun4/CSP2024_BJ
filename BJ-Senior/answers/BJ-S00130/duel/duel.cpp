#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,minpre,dpre=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    minpre=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>minpre){
            minpre=a[++dpre];
        }
    }
    cout<<n-dpre;
    return 0;
}
