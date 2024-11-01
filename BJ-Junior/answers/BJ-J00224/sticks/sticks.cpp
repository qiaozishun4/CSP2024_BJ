#include<bits/stdc++.h>
#include<string>
using namespace std;
int shu[10]={6,2,5,5,4,5,6,3,7,6};
int sqzchu(int a,int b){
	if(a%b==0) return a/b;
	else return a/b+1;
}
void solve(int x){
	if(x<2){cout<<-1;return;}
	if(x==2){cout<<1;return;}
	if(x==3){cout<<7;return;}
	if(x==4){cout<<4;return;}
	if(x==5){cout<<2;return;}
	if(x==6){cout<<6;return;}
	if(x==7){cout<<8;return;}
	int w=sqzchu(x,7);
	for(int i=1;i<=9;i++){
		if(shu[i+1]!=2&&x-shu[i]>=2&&sqzchu(x-shu[i],7)==w-1){
			x-=shu[i];cout<<i;break;
		}
	}
	w-=1;
	while(x>7){
		for(int i=0;i<=9;i++){
			if(x-shu[i]>=2&&sqzchu(x-shu[i],7)==w-1){
				x-=shu[i];cout<<i;break;
			}
		}
		w-=1;
	}
	if(x==2) cout<<1;
	if(x==3) cout<<7;
	if(x==4) cout<<4;
	if(x==5) cout<<2;
	if(x==6) cout<<6;
	if(x==7) cout<<8;
}

int main(){
    freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int q;
	cin>>q;
	while(q--){
		int a;
		cin>>a;
		solve(a);
		cout<<"\n";
	}
	return 0;
}	
