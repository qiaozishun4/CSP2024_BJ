#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		long long n;
		cin>>n;
		if(n<=1)cout<<"-1";
		else if(n==2)cout<<"1";
		else if(n==3)cout<<"7";
		else if(n==4)cout<<"4";
		else if(n==5)cout<<"2";
		else if(n==6)cout<<"6";
		else if(n==8)cout<<"10";
		else if(n==9)cout<<"18";
		else{
			int p=n%7;
			int s=(n-p)/7;
			switch(p){
				case 1:{cout<<"10";s--;break;}
				case 2:{cout<<"1";break;}
				case 3:{cout<<"22";s--;break;}
				case 4:{cout<<"20";s--;break;}
				case 5:{cout<<"2";break;}
				case 6:{cout<<"6";break;}
			}
			for(int i=0;i<s;i++)cout<<"8";
		}
		cout<<"\n";
	}
	return 0;
}
				
			
