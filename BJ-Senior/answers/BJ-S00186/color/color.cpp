#include<bits/stdc++.h>
using namespace std;
long long t,n,jsq,maxn=0;
long long a[1000005];
long long book[1000005];
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        jsq=0;
        for(int i=1;i<=500005;i++){
            book[i]=0;
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
            book[a[i]]++;
            maxn=max(maxn,a[i]);
        }
        //cout<<maxn<<endl;
        for(int i=1;i<=maxn;i++){
            if(book[i]){
                jsq+=(book[i]-1)*i;
                //cout<<jsq<<endl;
            }
        }
        cout<<jsq<<endl;
    }
    return 0;
}
