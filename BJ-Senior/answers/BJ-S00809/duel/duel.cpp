#include <bits/stdc++.h>
using namespace std;
int n,a[100005],ans;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
cin>>n;
for(int i=0;i<n;i++){
    cin>>a[i];
}
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(a[j]<a[j-1]){
            swap(a[j],a[j-1]);
        }
    }
}
for(int i=0;i<n;i++){
if(a[i]<a[i+1]){
    ans++;
}
}
cout<<n-ans;
return 0;

}
