#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	
	int t,m[7]={0,0,1,7,4,2,6};
	
	cin>>t;
	
	while(t--){
		int n;
		string ans="";
		vector<int>vec;
		
		cin>>n;
		
		if(n<2){
			cout<<-1<<endl;
			
			continue;
		}else if(n<7){
			cout<<m[n]<<endl;
			
			continue;
		}else if(n%7==0){
			n/=7;

			for(int i=1;i<=n;i++){
				ans+='0'+8;
			}
			
			cout<<ans<<endl;
			
			continue;
		}else if(n%7==1){
			n=(n-8)/7;
						
			vec.push_back(1);
			vec.push_back(0);
			
			for(int i=1;i<=n;i++){
				vec.push_back(8);
			}
			
			sort(vec.begin(),vec.end());
			
			swap(vec[0],vec[1]);
		}else if(n%7==2){
			n=(n-9)/7;
						
			vec.push_back(1);
			vec.push_back(8);
			
			for(int i=1;i<=n;i++){
				vec.push_back(8);
			}
			
			sort(vec.begin(),vec.end());
		}else if(n%7==3){
			n=(n-10)/7;
						
			vec.push_back(2);
			vec.push_back(2);
			
			for(int i=1;i<=n;i++){
				vec.push_back(8);
			}
			
			sort(vec.begin(),vec.end());
		}else if(n%7==4){
			n=(n-11)/7;
			
			vec.push_back(2);
			vec.push_back(0);
			
			for(int i=1;i<=n;i++){
				vec.push_back(8);
			}
			
			sort(vec.begin(),vec.end());
			
			swap(vec[0],vec[1]);
		}else if(n%7==5){
			n=(n-12)/7;
			
			if(n==0){
				vec.push_back(6);
			}else{
				vec.push_back(0);
			}
			vec.push_back(0);
			
			for(int i=1;i<=n;i++){
				vec.push_back(8);
			}
			
			sort(vec.begin(),vec.end());
			
			if(n==0){
				swap(vec[0],vec[1]);
			}else{
				swap(vec[0],vec[2]);
			}
		}else if(n%7==6){
			n=(n-13)/7;
			
			vec.push_back(8);
			vec.push_back(0);
			
			for(int i=1;i<=n;i++){
				vec.push_back(8);
			}
			
			sort(vec.begin(),vec.end());
			
			swap(vec[0],vec[1]);
		}
		
		int len=vec.size();
			
		for(int i=0;i<len;i++){
			ans+='0'+vec[i];
		}
			
		cout<<ans<<endl;
	}
	
	return 0;
}
