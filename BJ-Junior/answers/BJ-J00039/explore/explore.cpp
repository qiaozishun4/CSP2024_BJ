#include<iostream>
using namespace std;

int main(){
	int T;
	cin>>T;
	int n,m,k;
	int x,y,d;
	int ans[6];
	char s[1005][1005];
	for(int a=1;a<=T;a++){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int i=1;i<=n;i++){cin>>s[i];}
		int place[1000000];
		int len=0;
		for(int i=1;i<=k;i++){
			if(d==0){
				if(((y+1)<=n)&&(s[x][y+1]=='.')){
					y+=1;
					int f=0;
					for(int j=1;j<i;j++){
						if(place[j]==(x*10+y)){
							f=1;
							break;
						}
					}
					if(f==0){
						place[i]=x*10+y;
						len++;
					}
				}
				else{d=(d+1)%4;}
			}
			else if(d==1){
				if(((x+1)<=n)&&(s[x+1][y]=='.')){
					x+=1;
					int f=0;
					for(int j=1;j<i;j++){
						if(place[j]==(x*10+y)){
							f=1;
							break;
						}
					}
					if(f==0){
						place[i]=x*10+y;
						len++;
					}
				}
				else{d=(d+1)%4;}
			}
			else if(d==2){
				if(((y-1)>0)&&(s[x][y-1]=='.')){
					y-=1;
					int f=0;
					for(int j=1;j<i;j++){
						if(place[j]==(x*10+y)){
							f=1;
							break;
						}
					}
					if(f==0){
						place[i]=x*10+y;
						len++;
					}
				}
				else{d=(d+1)%4;}
			}
			else if(d==3){
				if(((x-1)>0)&&(s[x-1][y]=='.')){
					x-=1;
					int f=0;
					for(int j=1;j<i;j++){
						if(place[j]==(x*10+y)){
							f=1;
							break;
						}
					}
					if(f==0){
						place[i]=x*10+y;
						len++;
					}
				}
				else{d=(d+1)%4;}
			}
		}
		ans[a]=len;
	}
	for(int i=1;i<=T;i++){cout<<ans[i]<<endl;}
}