#include<bits/stdc++.h>
using namespace std;
int main(){
int n,r[1010101]={},t[1010101]={},s=0,o[1000010]={},f=0;
freopen("duel.in","r",stdin);
freopen("duel.out","w",stdout);
cin>>n;
for(int i=0;i<n;i++){
	cin>>r[i];
	t[r[i]]++;
}
for(int i=0;i<111111;i++){
	if(r[i])o[f++]=i;
}
sort(o,o+f);
for(int i=1;i<n-1;i++){
	for(int j=i+1;j<n;j++){
		for(int k=0;k<o[j];k++){
			if(t[o[i]]==0)break;
			t[o[i]]--;
		}
	}
}
for(int i=0;i<n;i++){
	if(t[i])s+=t[i];
}
cout<<s;
return 0;
}
