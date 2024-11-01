#include <bits/stdc++.h>
using namespace std;
int a[15],b[15],c[15],d[15];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	int n,ans=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		if(s[0]=='D'){
			if(s[1]=='A') a[1]++;
			else if(s[1]>='2'&&s[1]<='9'){
				char cao=s[1];
				a[cao-'0']++;
			}
			else if(s[1]=='T'){
				a[10]++;
			}
			else if(s[1]=='J'){
				a[11]++;
			}
			else if(s[1]=='Q'){
				a[12]++;
			}
			else if(s[1]=='K'){
				a[13]++;
			}
		}
		if(s[0]=='C'){
			if(s[1]=='A') b[1]++;
			else if(s[1]>='2'&&s[1]<='9'){
				char cao=s[1];
				b[cao-'0']++;
			}
			else if(s[1]=='T'){
				b[10]++;
			}
			else if(s[1]=='J'){
				b[11]++;
			}
			else if(s[1]=='Q'){
				b[12]++;
			}
			else if(s[1]=='K'){
				b[13]++;
			}
		}
		if(s[0]=='H'){
			if(s[1]=='A') c[1]++;
			else if(s[1]>='2'&&s[1]<='9'){
				char cao=s[1];
				c[cao-'0']++;
			}
			else if(s[1]=='T'){
				c[10]++;
			}
			else if(s[1]=='J'){
				c[11]++;
			}
			else if(s[1]=='Q'){
				c[12]++;
			}
			else if(s[1]=='K'){
				c[13]++;
			}
		}
		if(s[0]=='S'){
			if(s[1]=='A') d[1]++;
			else if(s[1]>='2'&&s[1]<='9'){
				char cao=s[1];
				d[cao-'0']++;
			}
			else if(s[1]=='T'){
				d[10]++;
			}
			else if(s[1]=='J'){
				d[11]++;
			}
			else if(s[1]=='Q'){
				d[12]++;
			}
			else if(s[1]=='K'){
				d[13]++;
			}
		}
	}
	for(int i=1;i<=13;i++){
		if(a[i]==0) ans++;
		if(b[i]==0) ans++;
		if(c[i]==0) ans++;
		if(d[i]==0) ans++;
	}
	cout<<ans;
	return 0;
}
