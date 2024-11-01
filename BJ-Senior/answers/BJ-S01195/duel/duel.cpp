#include <bits/stdc++.h>

 using namespace std;

 int a[100005];

 int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int l=0;
    int cnt=n;
    for(int i=1;i<n;i++){
        if(a[l]<a[i]){
            l++;
            cnt--;
        }
    }
    cout<<cnt<<endl;
    return 0;
 }
