#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int val,co=0;
}a[N];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		int c=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].val;
		}
		for(int i=1;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(a[j].val==a[i].val){
					c+=a[i].val;
					a[i].co=a[j].co;
					for(int k=j+1;k<i;k++){
						if(a[k].co==a[i].co) a[k].co=!a[k].co;
					}
					break;
				}
			}
		}
		cout<<c<<endl;
	}
	return 0;
}
