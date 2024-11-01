//code by:757326
//time 17:00
#include<bits/stdc++.h>
using namespace std;
long long t,n,m,l,V;//cheshu,ceshu,chang,xiansu
double d[1000005],v[1000005],a[1000005],p[1000005];
long long overv;
double chaoju;
long long stp;
long long book[1000005];//save
bool wei;
bool outt;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>l>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		for(int i=1;i<=n;i++){
			if(a[i]==0){//匀直
				if(v[i]>V){//超速
					for(int j=1;j<=m;j++){
						if(p[j]>=d[i]){
							book[j]=1;//save
							overv++;
							break;
						}
					}
				}
			}
			else if(a[i]>0){//匀加
				chaoju=(V*V-v[i]*v[i])/(2*a[i]*1.0);
				chaoju+=d[i];
				
				for(int j=1;j<=m;j++){
					if(p[j]>chaoju){
						overv++;
						book[j]=1;
						break;
					}
				}
				chaoju=0;
			}
			else if(a[i]<0){//匀减
				chaoju=(V*V-v[i]*v[i])/(2*a[i]*1.0);
				chaoju+=d[i];
				if(v[i]>V){//初速度超速
					for(int j=1;j<=m;j++){
						if(p[j]>=d[i]&&p[j]<chaoju){
							overv++;
							book[j]=1;
							break;
						}
					}
				}
				chaoju=0;
			}
		}
		for(int i=1;i<=m;i++){
			if(!book[i]){
				stp++;
			}
		}
		cout<<overv<<" "<<stp<<endl;
		overv=0;
		stp=0;
		for(int i=1;i<=m;i++)book[i]=0;
	}
	
	return 0;
}
/*
 * 关掉一些仪器让超速的车仍被判出
 * 测的速度为瞬时速度
 * 
 * 
 * 
1
5 5 15 3 
0 3 0
12 4 0
1 1 4
5 5 -2
6 4 -4
2 5 8 9 15
 * 
 * 5 8 9 15
*/
