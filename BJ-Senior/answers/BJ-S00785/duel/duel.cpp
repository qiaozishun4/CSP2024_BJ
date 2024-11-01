#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
int main(){
   freopen("r","duel.in",stdin);
   freopen("w","duel.out",stdout);
   cin>>n;
   int guai=n;
   for(int i=1;i<=n;i++){
    cin>>a[i];
   }

   sort(a+1,a+n+1);
   for(int i=1;i<=n;i++){
    if(a[i]<a[i+1]){
        guai--;
        a[i+1]==0;
        continue;
    }
   }
   if(guai==1){
    cout <<"1";
    return 0;
   }
   cout <<guai-1;
return 0;
}
