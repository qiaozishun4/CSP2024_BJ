#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005],t[100005];
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t[a[i]]++;
    }
    int sum=0;
    for(int i=1;i<=100000;i++){
        sum=max(t[i],sum);
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
