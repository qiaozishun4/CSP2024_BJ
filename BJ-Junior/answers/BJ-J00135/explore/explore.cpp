#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,xx,yy,d0,as;
bool ff[1005][1005];
string s[1005];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
void sv(){
	cin >> n >> m >> k >> xx >> yy >> d0;
	as=1;
	xx--;
	yy--;
	for(int i=0;i<n;i++){
		cin >> s[i];
		for(int j=0;j<m;j++){
			ff[i][j]=0;
		}
	}
	ff[xx][yy]=1;
	for(int i=1;i<=k;i++){
		int nx=xx+dx[d0];
		int ny=yy+dy[d0];
		if(nx<0||ny<0||nx>=n||ny>=m||s[nx][ny]=='x'){
			d0=(d0+1)%4;
		}else{
			as++;
			if(ff[nx][ny]==1){
				as--;
			}else{
				ff[nx][ny]=1;
			}
			xx=nx;
			yy=ny;
		}
	}
	cout << as << "\n";
	return;
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		sv();
	}
	return 0;
}
