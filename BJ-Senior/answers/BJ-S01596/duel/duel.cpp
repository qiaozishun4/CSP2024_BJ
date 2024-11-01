#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int s[N]={0};
int main(){
freopen("duel.in","r",stdin);
freopen("duel.out","w",stdout);
int n,x;
cin>>n;
for(int i=0;i<n;i++){
	cin>>x;
	s[x]++;
	}
int ans=0;
for(int i=1;i<=100000;i++){
	ans=max(ans,s[i]);
}
cout<<ans;
fclose(stdin);
fclose(stdout);
return 0;
}