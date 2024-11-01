#include<iostream>
#include<cstdio>
using namespace std;
const int N = 2e5+5;
int T,n,k,q;
struct node{
	int val,x,y;
	// the number a[i] is the yth number of the person No.x
	// the number a[i] = val
}a[N]; // sigma(l) <= 2e5
int tota,tote,head[N];
struct edge{
	int u,v,kind,nxt;
	// kind = 1 : the number u and v belong to the same person
	// kind = 2 : the number u and v belong to different person
}e[N*2];
void add(int u,int v,int kind){
	e[++tote].v = v;
	e[tote].kind = kind;
	e[tote].nxt = head[u];
	head[u] = tote;
}
bool f = 0;
//int past[N],index;
void dfs(int x,int walk,int jump,int r,int c){
	//cout<<past[1];
	//for(int i=2;i<=index;i++)cout<<"->"<<past[i];
	//cout<<" ";
	//cout<<jump<<endl;
	if(f)return;
	if(jump > r)return;
	if(walk > k)return;
	if(a[x].val == c){
		if(walk>=2 && jump == r){
			f = 1;
			return;
		}
	}
	for(int i=head[x];i;i=e[i].nxt){
		int v = e[i].v;
		int kind = e[i].kind;
		if(kind == 1){
			//past[++index] = v;
			dfs(v,walk+1,jump,r,c);
			//index--;
		}
		else if(kind == 2){
			if(walk < 2)continue;
			//past[++index] = v;
			dfs(v,1,jump+1,r,c);
			//index--;
		}
		if(f)return;
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	
	scanf("%d",&T);
	while(T--){
		tota = 0; tote = 0; f = 0;
		for(int i=1;i<=N-5;i++)head[i] = 0;
		scanf("%d%d%d",&n,&k,&q);
		for(int i=1;i<=n;i++){
			int l;
			scanf("%d",&l);
			for(int j=1;j<=l;j++){
				int x;
				scanf("%d",&x);
				a[++tota].val = x;
				a[tota].x = i;
				a[tota].y = j;
			}
			for(int j=2;j<=l;j++){ // create edge
				add(tota-l+j-1,tota-l+j,1);
				//add(tota-l+j,tota-l+j-1,1);
			}
		}
		for(int i=1;i<=tota;i++){
			for(int j=1;j<=i;j++){
				if(a[i].x!=a[j].x && a[i].val==a[j].val){
					add(i,j,2);
					add(j,i,2);
				}
			}
		}
		//
		while(q--){
			//cout<<"---\n";
			//index = 0;
			int r,c;
			f = 0;
			scanf("%d%d",&r,&c);
			for(int i=1;i<=tota;i++){
				if(f) break;
				if(a[i].val == 1){
					//past[1] = i;
					//index = 1;
					dfs(i,1,1,r,c);
				}
			}
			if(f)printf("1\n");
			else printf("0\n");
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
