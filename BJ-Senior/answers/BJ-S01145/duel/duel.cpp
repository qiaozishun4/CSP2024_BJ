#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,a[100001];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int m=0,k=0;
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
    if(m>=ceil(n/2)){
        cout<<m;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(k>=ceil(n/2)){
        cout<<k;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
