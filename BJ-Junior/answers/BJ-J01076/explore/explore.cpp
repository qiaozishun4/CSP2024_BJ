#include<bits/stdc++.h>
using namespace std;
struct{
	int x,y,x2,y2,d;
}robot;
set<pair<int,int>> a;
char ditu[1005][1005];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	int n=0,m=0,k=0;
	for(int z=0;z<T;z++){
		cin>>n>>m>>k;
		cout<<k;
		cin>>robot.x>>robot.y>>robot.d;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				ditu[i][j]=getchar();
			}
		}
		a.clear();
		while(k--){
			robot.x2=robot.x+dx[robot.d];
			robot.y2=robot.y+dy[robot.d];
			if(robot.x2>=1&&robot.x2<=n&&robot.y2>=1&&robot.y2<=m&&ditu[robot.x2][robot.y2]=='.'){
				robot.x=robot.x2;
				robot.y=robot.y2;
				a.insert(pair<int,int>(robot.x,robot.y));
				continue;
			}
			robot.d=(robot.d+1)%4;
		}
		cout<<a.size()+1<<endl;
		
	}
	return 0;
}

