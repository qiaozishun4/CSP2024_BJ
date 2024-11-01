#include<bits/stdc++.h>
using namespace std;
long long n;
char a[10000];
char b[10000];
long long cnt,t;
int main(){
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        t++;
    }
    for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j){
				if(a[i]==a[j]){
					if(b[i]==b[j]){
						cnt++;
						a[i]=cnt+12345;
					}
				}
			}
		}
	}
	cout<<52+cnt-t;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
