//code by:757326
//first 15:12
#include<bits/stdc++.h>
using namespace std;
long long n,r[1000005],cnt[1000005],ge=1,tot=1;
long long ans,guai,si;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	guai=n;
	
	for(int i=1;i<=n;i++)cin>>r[i];
	sort(r+1,r+n+1);
	
	for(int i=1;i<=n;i++){//fenzu
		if(r[i]==r[i+1]){
			ge++;
		}else{
			cnt[tot]=ge;
			tot++;
			ge=1;
		}
	}
	
	tot--;//zushu
	
	while(si!=tot){//hainengda
		si=0;
		for(int i=1;i<=tot;i++){//jilu
			if(cnt[i]!=-1){//si
				si++;
			}
		}
		
		for(int i=1;i<tot;i++){
			if(cnt[i]<=cnt[i+1]&&cnt[i]!=-1&&cnt[i+1]!=-1){
				guai-=cnt[i];
				cnt[i]=-1;//si
				cnt[i+1]-=cnt[i];
			}else if(cnt[i]>cnt[i+1]&&cnt[i]!=-1&&cnt[i+1]!=-1){
				guai-=cnt[i+1];
				cnt[i+1]=-1;//si
				cnt[i]-=cnt[i+1];
			}
		}
	}
	
	cout<<guai<<endl;
	return 0;
}
/*
 * 10
   136 136 136 2417 136 136 2417 136 136 136
 * 
 * 
 * 
 * 1 2 3 1 2
 * cnt: 2 2 1
 * idx: 1 2 3
 * 
 * ans: 
 * 
136 136 136 2417 136 136 2417 136 136 136
* sort:
136 136 136 136 136 136 136 136 2417 2417 
* 

*/ 
