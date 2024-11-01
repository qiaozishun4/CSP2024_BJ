#include <bits/stdc++.h>
using namespace std;
long long n,r[100005],d[100005],k=0;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>r[i];
        d[i]=0;
    }
    sort(r,r+n);
    for(int i = 0;i<n;i++){
        for(int j = k;j<i;j++){
            if(r[j]<r[i]&&d[j]!=1){
                d[j]=1;
                k++;
                break;
            }
        }
    }
    cout<<n-k<<endl;
    return 0;
}
