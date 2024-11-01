#include<bits/stdc++.h>
using namespace std;
int n,a[100010];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[x]++;
    }sort(a,a+n,greater<int>());
    cout<<a[0];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
