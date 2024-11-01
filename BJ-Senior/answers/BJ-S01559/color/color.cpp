#include <bits/stdc++.h>
using namespace std;
const int N = 214514;
int T;
int ff(int s,int c,int n){
    int res=0;
    if(s==n) return res;
    for(int i=s;i>=1;i--){

    }

    ff(s+1,c,n);ff(s+1,-c,n);
    ff(s-1,c,n);ff(s-1,-c,n);
}
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>T;
    while(T--){
        int n,a[N],visb[N],visr[N];
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(n<=15){
            cout<<max(ff(1,1,n),ff(1,-1,n))<<'\n';
        }


    }
    return 0;
}
