#include<bits/stdc++.h>
using namespace std;

vector<int> r;
int n;

void scn(){
	scanf("%d",&n);

	int t;
	for(int i = 0;i < n;i++){
		scanf("%d",&t);
		r.push_back(t);
	}
}

void solv(){
	std::sort(r.begin(),r.end());

	int small = 0;
	int same = 1;
	int killed = 0;
	for(int i = 1;i < n;i++){
		if(r[i-1] < r[i]){
			small += same;
			same = 0;
		}
		same++;

		if(small > 0){
			small--;
			killed++;
		}
	}

	printf("%d",n-killed);
}

void debug(){
	for(int i = 0;i < n;i++){
		//printf("%d ",r[i]);
	}
}

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);

	scn();
	solv();
	//debug();

	return 0;
}