#include<bits/stdc++.h>
using namespace std;
int n;
int r[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>r[i];
    }
    sort(r+1,r+1+n);
    int j=1;
    for(int i=1;i<=n;i++){
        if(j<i&&r[j]<r[i]){
            //cout<<i<<" "<<j<<endl;
            j++;
        }
    }
    cout<<n-j+1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
