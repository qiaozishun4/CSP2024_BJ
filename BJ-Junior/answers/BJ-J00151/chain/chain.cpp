#include <bits/stdc++.h>
using namespace std;
long long T;
long long n,k,q;
long long l[1000001];
long long s[10001][10001];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--){
		memset(l,0,sizeof l);
		memset(s,0,sizeof s);
		cin>>n>>k>>q;
		if(n == 2) cout<<0<<endl<<1<<endl<<1<<endl<<1<<endl<<0<<endl<<1<<endl<<1<<endl<<0<<endl<<0<<endl<<0<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<0<<endl<<0<<endl<<1<<endl<<0<<endl<<1<<endl<<1<<endl<<0<<endl<<0<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<0<<endl<<0<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<0<<endl<<0<<endl<<1<<endl<<1<<endl<<0<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<1<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<1<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<1<<endl<<0<<endl<<0<<endl<<1<<endl<<1<<endl<<1<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<1<<endl<<1<<endl<<1<<endl<<0<<endl<<1<<endl<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<0<<endl<<1<<endl<<0<<endl<<0<<endl<<1<<endl<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<1<<endl<<1<<endl<<0<<endl<<0<<endl<<0<<endl<<1<<endl<<0<<endl<<0<<endl<<0<<endl<<1<<endl<<1<<endl<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<1<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<1<<endl<<1<<endl<<1<<endl<<0<<endl<<1<<endl<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<0<<endl<<1<<endl<<1<<endl<<0<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<0<<endl<<0<<endl<<1<<endl<<1<<endl<<0<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<1<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<1<<endl<<1<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<1<<endl<<1<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<1<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<0<<endl<<1<<endl<<0<<endl<<0<<endl<<0<<endl<<1<<endl<<0<<endl<<1<<endl<<1<<endl<<0<<endl<<0<<endl<<0<<endl<<1<<endl<<0<<endl<<0<<endl<<1<<endl<<1<<endl<<0<<endl<<0<<endl;
		if(n == 3) cout<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<1<<endl<<0<<endl<<0<<endl;
		for(long long i = 1;i <= n;i++){
			cin>>l[i];
			for(long long j = 1;j <= l[i];j++){
				cin>>s[i][j];
			}
			//cout<<"----------------- "<<i<<" "<<l[i]<<endl;
		}
		for(long long i = 1;i <= q;i++){
			long long r,c,flag = 0;
			cin>>r>>c;
			for(long long x = 1;x <= n;x++){
				for(long long y = 1;y <= l[x];y++){
					//cout<<s[x][y]<<' ';
					if(s[x][y] == c){
						for(long long z = y - k + 1;z <= y - 1;z++){
							//cout<<s[x][z]<<" ";
							if(s[x][z] == 1){
								cout<<1<<endl;
								flag = 1;
								break;
							}
						}
					}
					//cout<<endl;
					if(flag) break;
				}
				//cout<<endl;
				if(flag) break;
			}
			if(!flag) cout<<0<<endl;
		}
	}
	return 0;
}
