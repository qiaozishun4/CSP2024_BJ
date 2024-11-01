#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n,a[100010];
    queue <int> b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
        }
    }
    for(int i=0;i<n;i++){
        b.push(a[i]);
    }
    int sum=0;
    for(int i=0;;a[i]<a[n-1]){
        sum++;
    }
    cout<<sum;
    fclose(stdout);
return 0;}
