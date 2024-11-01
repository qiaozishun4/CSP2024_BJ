#include <iostream>
#include <algorithm>
using namespace std;
int cnt,cc,c,cnt1,cnt2;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    int a[n+1]={};
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1){
            cnt1++;
        }
        else{
            cnt2++;
        }
    }
    cnt=n;
    sort(1+a,1+a+n);
    for(int i=1;i<=n;i++){
        if(a[i]!=a[i-1]){
            cc=c;
            c=1;
        }
        else{
            c++;
        }
        if(cc){
            cnt--;
            cc--;
        }

    }
    cout<<cnt;
    return 0;




}
