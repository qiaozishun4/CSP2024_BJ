#include<bits/stdc++.h>
using namespace std;
int t;
int main()
{
	ifstream fin("explore.in",ios::in);
	ofstream fout("explore.out",ios::out);
	fin >> t;
	int cnt=0;
	for(int i=1;i<=t;i++){
		int n,m,k;
		fin >> n >> m >> k;
		char c[n+1][m+1];
		bool b[n+1][m+1]={0};
		int x,y,d,num[n+1][m+1];
		fin >> x >> y >> d;
		b[x][y]=1;
		for(int j=1;j<=n;j++){
			for(int v=1;v<=m;v++){
				fin >> c[j][v];
				num[j][v]=int(c[j][v]);
			}
		}
		for(int j=1;j<=k;j++){
			if(d==0){
				if(num[x][y+1]=='x'||y+1>m){
					d=(d+1)%4;
					continue;
				}
				else{
					y++;
					b[x][y]=1;
				}
			}
			else if(d==1){
				if(num[x+1][y]=='x'||x+1>n){
					d=(d+1)%4;
					continue;
				}
				else{
					x++;
					b[x][y]=1;
				}
			}
			else if(d==2){
				if(num[x][y-1]=='x'||y-1==0){
					d=(d+1)%4;
					continue;
				}
				else{
					y--;
					b[x][y]=1;
				}
			}
			else{
				if(num[x-1][y]=='x'||x-1==0){
					d=(d+1)%4;
					continue;
				}
				else{
					x--;
					b[x][y]=1;
				}
			}
		}
		for(int j=1;j<=n;j++)
			for(int v=1;v<=m;v++)
				if(b[j][v]==1)
					cnt++;
		fout << cnt << endl;
		cnt=0;
	}
	return 0;
}
