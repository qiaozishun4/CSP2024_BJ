#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i]>a[i-n]){
                ans++;
            }
        }
    }
    cout<<ans<<endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}