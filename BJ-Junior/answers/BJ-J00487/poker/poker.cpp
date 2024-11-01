#include<bits/stdc++.h>
using namespace std;

long long n;
char a[10005],b[10005];

long long j,i;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    long long ans=0;
    ans+=52-n;



for(i=1;i<=2*n;i++) {

        cin>>a[i];
        a[i]=b[j];
        while(a[i]!=b[j]) {
            j++;
            ans++;
        }


}
cout<<ans;

return 0;
}
