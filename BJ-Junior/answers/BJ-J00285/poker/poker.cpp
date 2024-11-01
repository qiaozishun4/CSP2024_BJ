#include<bits/stdc++.h>

using namespace std;
int n,cnt;
int h[106];
string a;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a[1]=='A'){
			int x=0;
			if(a[0]=='D'){
				h[x+1]++;
			}else if(a[0]=='C'){
				h[x+2]++;
			}else if(a[0]=='H'){
				h[x+3]++;
			}else{
				h[x+4]++;
			}
		}else if(a[1]=='2'){
			int x=4;
			if(a[0]=='D'){
				h[x+1]++;
			}else if(a[0]=='C'){
				h[x+2]++;
			}else if(a[0]=='H'){
				h[x+3]++;
			}else{
				h[x+4]++;
			}
		}else if(a[1]=='3'){
			int x=8;
			if(a[0]=='D'){
				h[x+1]++;
			}else if(a[0]=='C'){
				h[x+2]++;
			}else if(a[0]=='H'){
				h[x+3]++;
			}else{
				h[x+4]++;
			}
		}else if(a[1]=='4'){
			int x=12;
			if(a[0]=='D'){
				h[x+1]++;
			}else if(a[0]=='C'){
				h[x+2]++;
			}else if(a[0]=='H'){
				h[x+3]++;
			}else{
				h[x+4]++;
			}
		}else if(a[1]=='5'){
			int x=16;
			if(a[0]=='D'){
				h[x+1]++;
			}else if(a[0]=='C'){
				h[x+2]++;
			}else if(a[0]=='H'){
				h[x+3]++;
			}else{
				h[x+4]++;
			}
		}else if(a[1]=='6'){
			int x=20;
			if(a[0]=='D'){
				h[x+1]++;
			}else if(a[0]=='C'){
				h[x+2]++;
			}else if(a[0]=='H'){
				h[x+3]++;
			}else{
				h[x+4]++;
			}
		}else if(a[1]=='7'){
			int x=24;
			if(a[0]=='D'){
				h[x+1]++;
			}else if(a[0]=='C'){
				h[x+2]++;
			}else if(a[0]=='H'){
				h[x+3]++;
			}else{
				h[x+4]++;
			}
		}else if(a[1]=='8'){
			int x=28;
			if(a[0]=='D'){
				h[x+1]++;
			}else if(a[0]=='C'){
				h[x+2]++;
			}else if(a[0]=='H'){
				h[x+3]++;
			}else{
				h[x+4]++;
			}
		}else if(a[1]=='9'){
			int x=32;
			if(a[0]=='D'){
				h[x+1]++;
			}else if(a[0]=='C'){
				h[x+2]++;
			}else if(a[0]=='H'){
				h[x+3]++;
			}else{
				h[x+4]++;
			}
		}else if(a[1]=='T'){
			int x=36;
			if(a[0]=='D'){
				h[x+1]++;
			}else if(a[0]=='C'){
				h[x+2]++;
			}else if(a[0]=='H'){
				h[x+3]++;
			}else{
				h[x+4]++;
			}
		}else if(a[1]=='J'){
			int x=40;
			if(a[0]=='D'){
				h[x+1]++;
			}else if(a[0]=='C'){
				h[x+2]++;
			}else if(a[0]=='H'){
				h[x+3]++;
			}else{
				h[x+4]++;
			}
		}else if(a[1]=='Q'){
			int x=44;
			if(a[0]=='D'){
				h[x+1]++;
			}else if(a[0]=='C'){
				h[x+2]++;
			}else if(a[0]=='H'){
				h[x+3]++;
			}else{
				h[x+4]++;
			}
		}else{
			int x=48;
			if(a[0]=='D'){
				h[x+1]++;
			}else if(a[0]=='C'){
				h[x+2]++;
			}else if(a[0]=='H'){
				h[x+3]++;
			}else{
				h[x+4]++;
			}
		}
	}
	for(int i=1;i<=52;i++){
		if(h[i]==0){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}	