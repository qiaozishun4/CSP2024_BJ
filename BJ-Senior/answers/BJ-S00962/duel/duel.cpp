#include<bits/stdc++.h>
using namespace std;

int a[100005];

int main()
{
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    if(n==1){
        cout<<1;
        return 0;
    }
    int l=1,r=2;
    while(r<=n){
        if(a[l]<a[r]&&l<r){
            a[l]=-1;
            l++,r++;
        }
        else{
            r++;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i]!=-1) cnt++;
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}