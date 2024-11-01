#include<bits/stdc++.h>
using namespace std;

bool mapp[1005][1005];
bool vis[1005][1005];
int n,m,k,startLin,startCol,startDir;

void reset(){
	for(int i = 0;i < 1005;i++){
		for(int j = 0;j < 1005;j++){
			mapp[i][j] = false;
			vis[i][j] = false;
		}
	}
	n = -1;
	m = -1;
	k = -1;
	startLin = -1;
	startCol = -1;
	startDir = -1;
	//printf("DEBUG RESETPASS\n");
}

void scn(){
	char c;
	scanf("%d %d %d\n%d %d %d\n",&n,&m,&k,&startLin,&startCol,&startDir);

	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			scanf("%c",&c);
			if(c == 'x'){
				mapp[i][j] = true;
			}
		}
		scanf("\n");
	}
	//printf("DEBUG SCANPASS\n");
}

bool isLocValid(int x,int y){
	if(x <= n && x >= 1 && y <= m && y >= 1 && !mapp[x][y]) return true;
	return false;
}

int solv(){
	//haha solv goes burrrrrrrrr
	int curDir = startDir;
	int curLin = startLin;
	int curCol = startCol;
	int nexLin,nexCol;


	for(int i = 0;i < k;i++){
		vis[curLin][curCol] = true;
		nexLin = curLin;
		nexCol = curCol;
		switch(curDir){
			case 0:
				nexCol++;
				break;
			case 1:
				nexLin++;
				break;
			case 2:
				nexCol--;
				break;
			case 3:
				nexLin--;
				break;
		}

		if(isLocValid(nexLin,nexCol)){
			curLin = nexLin;
			curCol = nexCol;
			//printf("[Debug] Move to %d,%d\n",curLin,curCol);
		}else{
			curDir = (curDir + 1) %4;
			//printf("[Debug] Turn to %d\n",curDir);
		}
	}
	vis[curLin][curCol] = true;

	//count how much vis
	int ans = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(vis[i][j]){
				ans++;
			}
		}
	}
	return ans;
}

int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);

	int bigN;
	scanf("%d\n",&bigN);

	for(int cas = 0;cas < bigN;cas++){
		reset();
		scn();
		printf("%d\n",solv());
	}

	return 0;
}