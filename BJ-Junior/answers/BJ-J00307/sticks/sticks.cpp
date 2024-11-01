#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,a[1000010],ed;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n==1){cout<<"-1\n";continue;}
		if(n==2){cout<<"1\n";continue;}
		if(n==3){cout<<"7\n";continue;}
		if(n==4){cout<<"4\n";continue;}
		if(n==5){cout<<"2\n";continue;}
		if(n==6){cout<<"6\n";continue;}
		if(n==7){cout<<"8\n";continue;}
		if(n==8){cout<<"10\n";continue;}
		if(n==9){cout<<"18\n";continue;}
		if(n==10){cout<<"22\n";continue;}
		if(n==11){cout<<"20\n";continue;}
		if(n==12){cout<<"28\n";continue;}
		if(n==13){cout<<"68\n";continue;}
		if(n==14){cout<<"88\n";continue;}
		n-=14;
		a[1]=a[2]=8,ed=2;
		for(int i=1;i<=n;i++){
			if(a[ed]==8){
				a[ed]=0;
				ed++;
				a[ed]=1;
			}else if(a[ed]==1&&a[ed-1]==0) a[ed-1]=8;
			else if(a[ed]==1&&a[ed-1]==8&&a[ed-2]==8) a[ed]=2,a[ed-1]=a[ed-2]=0;
			else if(a[ed]==2&&a[ed-1]==0&&a[ed-2]==0) a[ed-2]=8;
			else if(a[ed]==2&&a[ed-1]==0&&a[ed-2]==8) a[ed-1]=8;
			else if(a[ed]==2&&a[ed-1]==8&&a[ed-2]==8) a[ed]=6;
			else if(a[ed]==6) a[ed]=8;
		}for(int i=ed;i>=1;i--) cout<<a[i];
		cout<<endl;
	}
	return 0;
}