#include<bits/stdc++.h>
using namespace std;
const long long N=1000001;
long long n[N],m[N],k[N];
long long x[N],y[N],d[N];
long long t,s[1001]={0};
int ji[1001][1001],f[1001],g[1001];
int wz[1001],fx[1001];
long long c[10];
long long b[6][1001][1001];
char a[1001];
int f1[1001]={1};
int main(){
	cin>>t;
	for(int j=0;j<t;j++){
		c[j]=b[j][m[j]][n[j]];
		cin>>n[j]>>m[j]>>k[j];
		cin>>x[j]>>y[j]>>d[j];
		for(int j=0;j<n[j];j++)
		//for(int i=0;i<m[j];i++){
			cin>>a[j];
		//}
	}
	for(int i=0;i<t;i++){
		for(int j=0;j<int(strlen(a));j++){
			if(a[j]=='x') f1[i]=0;
		}
	}
	
	for(int j=0;j<t;j++){
		wz[j]=ji[x[j]][y[j]];
		fx[j]=d[j];
	
		for(int i=0;i<k[j];i++){
			if(d[j]==0) {
				wz[j]=ji[x[j]][y[j]+1];
				f[j]=x[j];
				g[j]=y[j]+1;
			}
			else if(d[j]==1){
				wz[j]=ji[x[j]+1][y[j]];
				f[j]=x[j]+1;
				g[j]=y[j];
				} 
			else if(d[j]==2){
				wz[j]=ji[x[j]][y[j]-1];
				f[j]=x[j];
				g[j]=y[j]-1;
				} 
			else if(d[j]==3) {
				wz[j]=ji[x[j]-1][y[j]];
				f[j]=x[j]-1;
				g[j]=y[j];
			}
			if((f[j]<=m[j] && g[j]<=m[j])&&f1[i]){
				g[j]=y[j]+1;
				s[j]++;
			}
			else {
				d[j]=(d[j]+1)%4;
				s[j]++;
				}
		}
		
		cout<<s[j]<<endl;
	}
	
	
	
	return 0;
}
