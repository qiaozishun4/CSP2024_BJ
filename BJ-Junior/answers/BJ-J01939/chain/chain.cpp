#include<bits/stdc++.h>
using namespace std;

int n1,k1,q1;
int s1[100005][200005];
int l1[100005];
int r1[100005];
int c1[100005];

void reset(){
	if(true) return;
	//for(int i = 0;i < 100005;i++){
	//	for(int j; j < 200005;j++){
	//		s[i][j] = 0;
	//	}
	//}
	//this can be removed
}

void scn(){
	scanf("%d %d %d\n",&n1,&k1,&q1);
	for(int i = 0;i< n1;i++){
		scanf("%d",&l1[i]);
		for(int j = 0;j < l1[i];j++){
			scanf("%d",&s1[i][j]);
		}
	}
	for(int i = 0;i < q1;i++){
		scanf("%d %d\n",&r1[i],&c1[i]);
	}
}

bool recur(int remain,int lastnum,int lastperson,int j){
	if(remain == 0){
		if(lastnum == c1[j]) return true;
	}

	for(int i = 0;i < n1;i++){
		if(i == lastperson) continue;
		vector<int> validIdx;
		for(int loop2 = 0;loop2 < l1[i];loop2++){
			if(s1[i][loop2] == lastnum){
				validIdx.push_back(loop2);
			}
		}

		for(int loop2 = 0;loop2 < validIdx.size();loop2++){
			for(int loop3 = validIdx[loop2];loop3 < l1[i];loop3++){
				if(recur(remain-1,s1[i][loop3],i,j)) return true;
			}
		}
	}
	return false;
}

void solve(){
	for(int i = 0;i < q1;i++){
		if(recur(r1[i],1,-1,i)){
			printf("1\n");
		}else{
			printf("0\n");
		}
	}
}

int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);

	int bigN;
	cin >> bigN;
	for(int i = 0;i < bigN;i++){
		reset();
		scn();
	}

	return 0;
}