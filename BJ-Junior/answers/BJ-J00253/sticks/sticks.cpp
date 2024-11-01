#include<bits/stdc++.h>
using namespace std;
int a[101]={6,2,5,5,4,5,6,3,7,6};

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		bool f=0;
		cin>>n;
		int m=0;
		if(n<=1){
			cout<<"-1\n";
			continue;
		}
		if(n%7==0){
			f=1;
			for(int i=1;i<=n/7;i++){
					cout<<"8";
			}
			cout<<"\n";
		}else if(n%7==1){
				f=1;
				cout<<"10";
				for(int i=1;i<=n/7-1;i++){
						cout<<"8";
				}
				cout<<"\n";
		}
		if(f){
			continue;
		}
		for(int i=1;i<=9;i++){
			if(a[i]==n){
				cout<<i<<"\n";
				f=1;
				break;
			}
		}
		if(f){
			continue;
		}
		for(int i=1;i<=9;i++){
			for(int j=0;j<=9;j++){
				if(a[i]+a[j]==n&&f==0){
					cout<<i<<j<<"\n";
					f=1;
					break;
				}
			}
		}
		if(f){
			continue;
		}
		for(int i=1;i<=9;i++){
			for(int j=0;j<=9;j++){
				for(int k=0;k<=9;k++){
					if(a[i]+a[j]+a[k]==n&&f==0){
						m=i*100+j*10+k;
						if(to_string(m).size()==3){
							cout<<m<<"\n";
							f=1;
							continue;
						}
					}
				}
			}
		}
		if(f){
			continue;
		}
		for(int i=1;i<=9;i++){
			for(int j=0;j<=9;j++){
				for(int k=0;k<=9;k++){
					for(int x=0;x<=9;x++){
						if(a[i]+a[j]+a[k]+a[x]==n&&f==0){
							m=i*1000+j*100+k*10+x;
							if(to_string(m).size()==4){
								cout<<i<<j<<k<<x<<"\n";
								f=1;
								continue;
							}
						}
					}
				}
			}
		}
		if(f){
			continue;
		}
		for(int i=1;i<=9;i++){
			for(int j=0;j<=9;j++){
				for(int k=0;k<=9;k++){
					for(int x=0;x<=9;x++){
						for(int y=0;y<=9;y++){
							if(a[i]+a[j]+a[k]+a[x]+a[y]==n&&f==0){
								m=i*10000+j*1000+k*100+x*10+y;
								if(to_string(m).size()==5){
									cout<<i<<j<<k<<x<<y<<"\n";
									f=1;
									continue;
								}
							}
						}
					}
				}
			}
		}
		if(!f){
			cout<<"-1"<<"\n";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}