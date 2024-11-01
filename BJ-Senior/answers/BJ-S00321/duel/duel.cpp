#include<bits/stdc++.h>
using namespace std;
struct A{
	int val,num,h;
}b[100005]={};
int a[100005];
int n,ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int lenb=0,p=-1;
	for(int i=1;i<=n;i++){
		if(a[i]!=p){
			b[++lenb].val=a[i];
			b[lenb].num=1;
			b[lenb].h=1;
			p=a[i];
		}
		else{
			b[lenb].num++;
			b[lenb].h++;
		}
	}
	for(int i=2;i<=lenb;i++){
		if(b[i-1].num>=b[i].num){
			b[i-1].num-=b[i].num;
			b[i].h=0;
		}
		else{
			b[i].h-=b[i-1].num;
			b[i-1].num=0;
			for(int j=1;j<i;j++){
				if(b[j].num<=b[i].h){
					b[i].h-=b[j].num;
					b[j].num=0;
				}
				else{
					b[j].num-=b[i].h;
					b[i].h=0;
				}
			}
		}
	}
	
	for(int i=1;i<=lenb;i++){
		ans+=b[i].num;
	}
	cout<<ans<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
