#include<bits/stdc++.h>
using namespace std;

int sticks;
int corAmount[10];
vector<int> buffer[100005];

void scn(){
	scanf("%d\n",&sticks);
}

bool isSmallerThan(vector<int> a,vector<int> b){
	if(a[0] == -1) return true;
	if(a.size() > b.size()) return true;
	return false;
}

vector<int> recur(int n,int layer){
	if(buffer[n][0] == -2){

		int i = 0;
		
		if(layer == 0){
			i++;
		}
		vector<int> ans;
		ans.push_back(-1);

		for(;i < 10;i++){ //i = the current trying number
			if(n < corAmount[i]){
				continue;
			}

			vector<int> tmp;
			tmp.push_back(i);

			if(n != corAmount[i]){
				vector<int> tmp2;
				
				tmp2 = recur(n - corAmount[i],layer+1);
				
				if(tmp2[0] == -1){
					continue;
				}
				
				for(int j = 0;j < tmp2.size();j++){
					tmp.push_back(tmp2[j]);
				}
			}
			
			if(isSmallerThan(ans,tmp)) ans = tmp;
		}

		buffer[n] = ans;
	}

	return buffer[n];
}

void solveAndPrint(){
	vector<int> ans = recur(sticks,0);
	for(int i = 0;i < ans.size();i++){
		printf("%d",ans[i]);
	}
	printf("\n");
}

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);

	corAmount[0] = 6;
	corAmount[1] = 2;
	corAmount[2] = 5;
	corAmount[3] = 5;
	corAmount[4] = 4;
	corAmount[5] = 5;
	corAmount[6] = 6;
	corAmount[7] = 3;
	corAmount[8] = 7;
	corAmount[9] = 6;


	vector<int> notdef;
	notdef.push_back(-2);
	for(int i = 0;i< 100005;i++){
		buffer[i] = notdef;
	}
	vector<int> invalidNum;
	invalidNum.push_back(-1);
	buffer[0] = invalidNum;

	int bigN;
	scanf("%d\n",&bigN);
	for(int i = 0;i < bigN;i++){
		scn();
		solveAndPrint();
	}

	return 0;
}