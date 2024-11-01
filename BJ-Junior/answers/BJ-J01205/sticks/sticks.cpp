#include<bits/stdc++.h>
using namespace std;
int T;
int n;
int len,b;
int a[100010];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		a[100010]={0};
		b=0;len=0;
		if(n<2){
			cout<<-1<<endl;
			continue;
		} if(n==6){
			cout<<6<<endl;
			continue;
		} while(n){
			  while(n>=7&&n-7!=1){
				a[++len]=8;n-=7;
			} while(n>=6&&n-6!=1){
				a[++len]=0;n-=6;
			} while(n>=5&&n-5!=1){
				a[++len]=2;n-=5;
			} while(n>=4&&n-4!=1){
				a[++len]=4;n-=4;
			} while(n>=3&&n-3!=1){
				a[++len]=7;n-=3;
			} while(n>=2&&n-2!=1){
				a[++len]=1;n-=2;
			}
		}
		sort(a+1,a+len+1);
		for(int i=1;i<=len;i++){
			if(a[i]==0){b+=1;continue;}
			if(a[i]){
				cout<<a[i];
				for(int j=1;j<=b;j++)cout<<0;
			}
			
		}
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}