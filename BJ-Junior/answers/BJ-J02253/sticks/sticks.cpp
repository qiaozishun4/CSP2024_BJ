#include<bits/stdc++.h>
#define f(i,a,b) for(int i = a ; i<=b ; i++)
using namespace std;
int n,k;
const int s[] = {6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>k;
		if(k == 1) cout<<-1;
		else{
			for(int i = 1 ; ; i++){
				int tmp = i,cur = 0;
				while(tmp){
					int kkk = tmp%10;
					cur+=s[kkk];
					tmp/=10;
				}
				if(cur == k){
					cout<<i;
					break;
				}
			}
		}
		
	}
	
    return 0;
}
