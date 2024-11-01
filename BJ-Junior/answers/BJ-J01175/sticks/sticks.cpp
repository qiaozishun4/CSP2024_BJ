#include <iostream>
#include <string>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6},v[1000000],flag=1,q=0;
void dfs(int f,int k){
	if(k==0){
		q=1;
		return;
	}
	for(int i=k/a[f];i>=0;i--){
		v[f]+=i;
		dfs(f+1,k-i*a[f]);
		if(q==1){
			break;
		}
		v[f]-=i;
		dfs(f+1,k);
		if(q==1){
			break;
		}
	}
}void ze(){
	if(v[0]>0){
		for(int i=1;i;i++){
			if(v[0]==0) break;
			cout<<0;
		}
	}
}
int main(){
    int n,z;
    cin>>n;
    for(int i=1;i<=n;i++){
		q=0;
		flag=1;
		cin>>z;
		dfs(0,z);
		for(int j=1;j<=10;j++){
			if(v[j]>=1){
				cout<<j;
				v[j]--;
				ze();
				flag=0;
			}
		}
		if(flag==1){
			if(v[0]>0){
				cout<<6;
				v[0]--;
				ze();
			}
			else{
				cout<<-1;
			}
		}
			
	}
    return 0;
}

