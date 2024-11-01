#include<bits/stdc++.h>
using namespace std;

struct vroom{
	int pos;
	int vel;//velocity
	int acc;//accerlation
};

struct path{
	int start;
	int end; 
};

path newpath(int s,int e){
	path p;
	p.start = s;
	p.end = e;
	return p;
}


int carN; //cars amn
int decN; //detectors amn
int rodN; //road length
int limN; //f(x) = lim -> speed
//c++ need document comments
//the weel on the bus goes round and round
vroom cars[100005]; //copyright disney
int traps[100005];
bool vis[100005];

void scn(){
	scanf("%d %d %d %d\n",&carN,&decN,&rodN,&limN);
	for(int i = 0;i < carN;i++){
		scanf("%d %d %d\n",&cars[i].pos,&cars[i].vel,&cars[i].acc);
		//all i want for christmas is you
	}
	int t;
	for(int i = 0;i < decN;i++){
		scanf("%d",&t);
	}
	for(int i = rodN;i >= 0;i--){
		//create search index
		traps[i] += traps[i+1];
	}
}

bool cameraBetween(int a,int b){
	if(b < 0) b = 0;
	if(traps[a+1] < traps[b]) return true;
	return false;
}

void solve(){
	//orteil.dashnet.org/cookieclicker
	int NGalr = 0;
	vector<path> paths;

	for(int i = 0;i < carN;i++){
		if(cars[i].vel > limN){
			if(cars[i].acc >= 0){
				if(cameraBetween(cars[i].pos,0)){ 
					NGalr++;
					paths.push_back(newpath(cars[i].pos,0));
				}
				continue;
			}

			//car below limit at idk + 1
			//t = (vel - limN) / acc
			float t = float(cars[i].vel - limN) / cars[i].acc;
			//s = vel * t + 0.5 * acc * t^2
			float s = cars[i].vel * t + 0.5f * cars[i].acc * t * t;
			int idk = cars[i].pos - floor(s) - 1;

			if(cameraBetween(cars[i].pos,idk)){
				NGalr++;
				paths.push_back(newpath(cars[i].pos,idk));
			}
		}else{
			if(cars[i].acc <= 0) continue;

			//car exceed limit at `pos-s` (int exceed)

			//limN = vel + acc * t
			//t = (vel - limN) / acc
			//limN + 0.01 modifier to make the speed not equal to it
			float t = abs(cars[i].vel - limN - 0.01f) / cars[i].acc;
			//s = vel * t + 0.5 * acc * t^2
			float s = cars[i].vel * t + 0.5f * cars[i].acc * t * t;
			int exceed = cars[i].pos - ceil(s);
			if(exceed < 0) continue;

			if(cameraBetween(exceed,0)){
				NGalr++;
				paths.push_back(newpath(exceed,0));
			}
		}
	}

	//chuguchu bam bam
	//try closing cameras, we need at least 1 camera inside each path
	//???
	printf("%d ",NGalr);
	vector<int> inc[114514];
	for(int i = 0;i < paths.size();i++){
		for(int j = paths[i].start;j <= paths[i].end;j++){
			inc[j].push_back(i);
		}
	}

	int superchats = 0;

	for(int i = rodN;i >= 0;i--){
		if(traps[i+1] > traps[i]){
			bool seewo = true;
			for(int j = 0;j < inc[i+1].size();j++){
				if(!vis[inc[i+1][j]]){
					vis[inc[i+1][j]] = true;
					seewo = false;
				}
			}
			if(seewo) superchats++;
		}
	}
	printf("%d\n",superchats);
}

int main(){
	//lonely halloween
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	//what is happening i cant make any output
	
	int bigN; //im not gay, sir
	scanf("%d\n",&bigN);
	for(int cas = 0;cas < bigN;cas++){
		scn();
		solve();
	} //ill just put random stuff i thought about
//in the comments while coding

	return 0;
}