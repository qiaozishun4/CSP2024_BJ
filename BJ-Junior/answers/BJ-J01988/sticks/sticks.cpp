#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
// T [1,50]
// n [1,1e5]
int T,n;
int use[15] = {6,2,5,5,4,5,6,3,7,6}; // 0~9
const int N = 5e4+10;
int ans[N];
bool f = 0; // find answer
void dfs(int st,int dig,int mdig){
	//cout<<"---\n";
	//for(int i=1;i<=dig;i++)cout<<ans[i];
	//cout<<endl;
	//cout<<st<<" "<<dig<<" "<<mdig<<endl;
	if(f)return;
	if(st == 0){
		if(dig == mdig+1){
			f = 1;
			return;
		}
		return;
	}
	if(dig == mdig+1){ // && st!=0
		return;
	}
	if(st < (mdig-dig+1)*2)return;
	if(st > (mdig-dig+1)*7)return;
	
	if(dig == 1){ // ans[1] != 0
		for(int i=1;i<=9;i++){
			if(f)break;
			if(use[i] > st)continue;
			ans[dig] = i;
			dfs(st-use[i],dig+1,mdig);
		}
	}else{
		for(int i=0;i<=9;i++){
			if(f)break;
			if(use[i] > st)continue;
			ans[dig] = i;
			dfs(st-use[i],dig+1,mdig);
		}
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	
	scanf("%d",&T);
	while(T--){
		f = 0;
		scanf("%d",&n);
		if(n < 2){
			printf("-1\n");
			continue;
		}
		int mdig = ceil(1.0*n/2);
		for(int i=1;i<=mdig;i++){
			dfs(n,1,i);
			if(f){
				for(int j=1;j<=i;j++){
					printf("%d",ans[j]);
				}
				printf("\n");
				break;
			}
		}
		if(!f)printf("-1\n");
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
