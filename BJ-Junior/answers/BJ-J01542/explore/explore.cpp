// 100pts ?
// baosou
// tianwanggaidihu,js350
// baotazhenheyao,dabiaochushengyao hhha.............
#include <bits/stdc++.h>
using namespace std;
namespace a{
	int movement[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	int L,N,M,K,ANSWER=0,x00,y00,d00;
	bool vs[1145][1145],mp[1145][1145];
	char c;
}
void dfs(int axx,int axy,int dir,int step){
	for(int EIGIEAIIR=0;EIGIEAIIR<a::K;EIGIEAIIR++){
		dir%=4;
		if(!a::vs[axx][axy]){
			a::vs[axx][axy]=true;
			a::ANSWER++;
			//printf("%d %d is new\n",axx,axy);
		} 
		if(axx+a::movement[dir][0]>a::N || axx+a::movement[dir][0]<1 || axy+a::movement[dir][1]>a::\
		M || axy+a::movement[dir][1]<1 || a::mp[axx+a::movement[dir][0]][axy+a::movement[dir][1]]) {
			dir=(dir+1)%4;
			//printf("in the %d %d rotates\n",axx,axy);
		}
		else {
			axx+=a::movement[dir][0];
			axy+=a::movement[dir][1];
			//printf("%d %d is moved to\n",axx,axy);
		}
	}
	if(!a::vs[axx][axy]){
		a::vs[axx][axy]=true;
		a::ANSWER++;
		//printf("%d %d is new\n",axx,axy);
	} 
}
int main(void){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	ios::sync_with_stdio(true);
	cin >> a::L;
	for(int i=0;i<a::L;i++){
		memset(a::vs,0,sizeof(a::vs));
		memset(a::mp,0,sizeof(a::mp));
		a::ANSWER=a::K=a::M=a::N=a::d00=a::x00=a::y00=0;
		cin >> a::N >> a::M >> a::K >> a::x00 >> a::y00 >> a::d00;
		for(int j=1;j<=a::N;j++){
			for(int k=1;k<=a::M;k++){
				cin >> a::c;
				if(a::c=='x') a::mp[j][k]=true;
				else a::mp[j][k]=false;
			}
		}
		dfs(a::x00,a::y00,a::d00,0);
		cout << a::ANSWER << endl;
	}
}
