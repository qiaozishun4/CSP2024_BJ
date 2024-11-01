#include<bits/stdc++.h>
using namespace std;
int a[109],b[109],c[109],d[109];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		char x,y;
		int e;
		cin>>x>>y;
		if(y=='A') e=1;
		else if(y=='T') e=10;
		else if(y=='J') e=11;
		else if(y=='Q') e=12;
		else if(y=='K') e=13;
		else e=y-'0';
		if(x=='S'){
            a[e]++;
		}else if(x=='H'){
            b[e]++;
		}else if(x=='D'){
            c[e]++;
		}else{
            d[e]++;
        }
	}
	int ans=0;
	for(int i=1;i<=13;i++){
        if(a[i]==0) ans++;
        if(b[i]==0) ans++;
        if(c[i]==0) ans++;
        if(d[i]==0) ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
