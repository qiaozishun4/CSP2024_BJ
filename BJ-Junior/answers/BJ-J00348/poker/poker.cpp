#include<bits/stdc++.h>
using namespace std;
int turn(char c){
    if(c=='A') return 1;
    if(c=='T') return 10;
    if(c=='J') return 11;
    if(c=='Q') return 12;
    if(c=='K') return 13;
    return c-'0';
}
int a1[20],a2[20],a3[20],a4[20];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans=0;
	cin>>n;
	while(n--){
	    string s;
        cin>>s;
        char a=s[0],b=s[1];
        if(a=='D'){
            a1[turn(b)]++;
        }
        if(a=='C'){
            a2[turn(b)]++;
        }
        if(a=='S'){
            a3[turn(b)]++;
        }
        if(a=='H'){
            a4[turn(b)]++;
        }
	}
	for(int i=1; i<=13; i++){
        if(a1[i]==0) ans++;
        if(a2[i]==0) ans++;
        if(a3[i]==0) ans++;
        if(a4[i]==0) ans++;
	}
	cout<<ans;
  return 0;
}
