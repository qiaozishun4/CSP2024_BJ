#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("poker.in","r",stdin);
freopen("poker.out","w",stdout);
int ans=52;
int n;
int a[100];
cin>>n;
for (int i=0;i<n;i++)
{
cin>>a[i];
ans--;
}

for (int j=0;j<n;j++){
for (int i=1;i<n;i++){
if (a[j]==a[i]){
ans++;
}
}
}

cout <<ans<<endl;
return 0;
}
