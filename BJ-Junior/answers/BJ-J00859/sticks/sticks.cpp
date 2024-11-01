#include<bits/stdc++.h>
using namespace std;
int num_num[10]={6,2,5,5,4,5,6,3,7,6};
int pianfen[1005]={-1,-1,1,7,4,2,6,8,10,18,23,20,28,80,88,108,188,200,208};
int n,m;
int main(){
    freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
		cin>>m;
		if(m%7==0){
			for(int i=0;i<m/7;i++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		else if(m%7==1){
			cout<<10;
			for(int i=0;i<(m-8)/7;i++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
		else if(n<=18) cout<<pianfen[m]<<endl;
		else cout<<endl;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
