#include <bits/stdc++.h>
#define int long long

using namespace std;

void pushh(char c,set<int>&st){
	if(c>='2'&&c<='9'){
		int now=c-'0';
		st.insert(now);
	}else if(c=='T'){
		st.insert(10);
	}else if(c=='J'){
		st.insert(11);
	}else if(c=='Q'){
		st.insert(12);
	}else if(c=='K'){
		st.insert(13);
	}else{
		st.insert(1);
	}
}

signed main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	
	int n,ans=0;
	
	cin>>n;
	
	set<int>st1;
	set<int>st2;
	set<int>st3;
	set<int>st4;
	
	for(int i=1;i<=n;i++){
		string s;
		
		cin>>s;
		
		if(s[0]=='D'){
			pushh(s[1],st1);
		}else if(s[0]=='C'){
			pushh(s[1],st2);
		}else if(s[0]=='H'){
			pushh(s[1],st3);
		}else if(s[0]=='S'){
			pushh(s[1],st4);
		}
	}
	
	ans+=13-st1.size();
	ans+=13-st2.size();
	ans+=13-st3.size();
	ans+=13-st4.size();
	
	cout<<ans;
	
	return 0;
}
