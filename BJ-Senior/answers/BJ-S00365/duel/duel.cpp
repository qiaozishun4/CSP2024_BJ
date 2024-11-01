#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N*2];int n;
int main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    cin>>n;for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int it1=1;int ans=0;
    for(int i=1;i<=n;i++){
        while(it1<=n&&a[it1]<=a[i]) it1++;
        if(it1<=n){
            it1++;
        }else{
            ans++;
        }
    }cout<<ans;
    fclose(stdin);fclose(stdout);
    return 0;
}//jp8akioi