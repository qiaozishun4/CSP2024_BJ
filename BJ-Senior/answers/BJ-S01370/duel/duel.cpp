#include<bits/stdc++.h>
using namespace std;

int n,a[1234456];

int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int p=n;
    sort(a+1,a+n+1);
    int l=1,r=2;
    while(r<=n){
        if(a[l]<a[r])l++,r++,p--;
        else r++;
    }
    cout<<p;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
