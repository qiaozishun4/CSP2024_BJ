#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin>>t;
    for(int z=1;z<=t;z++){
		int n,a;
		cin>>n;
		if(n<2)cout<<"-1"<<endl;
		else if(n%7==0){
			a=n/7;
			for(int i=1;i<=a;i++)cout<<"8";
			cout<<endl;
		}
		else if(n%7==1){
			a=n/7-1;
			cout<<"10";
			for(int i=1;i<=a;i++)cout<<"8";
			cout<<endl;
		}
		else if(n==2)cout<<"1"<<endl;
		else if(n==3)cout<<"7"<<endl;
		else if(n==4)cout<<"4"<<endl;
		else if(n==5)cout<<"2"<<endl;
		else if(n==6)cout<<"6"<<endl;
		else if(n==9)cout<<"18"<<endl;
		else if(n==10)cout<<"22"<<endl;
		else if(n==11)cout<<"20"<<endl;
		else if(n==12)cout<<"28"<<endl;
		else if(n==13)cout<<"68"<<endl;
		else if(n==16)cout<<"188"<<endl;
		else if(n==17)cout<<"200"<<endl;
		else if(n==18)cout<<"208"<<endl;
		else if(n==19)cout<<"288"<<endl;
		else if(n==20)cout<<"688"<<endl;
		else if(n%7==2){
			a=n/7;
			cout<<"1";
			for(int i=1;i<=a;i++)cout<<"8";
			cout<<endl;
		}
		else if(n%7==3){
			a=n/7-2;
			cout<<"200";
			for(int i=1;i<=a;i++)cout<<"8";
			cout<<endl;
		}
		else if(n%7==4){
			a=n/7-1;
			cout<<"20";
			for(int i=1;i<=a;i++)cout<<"8";
			cout<<endl;
		}
		else if(n%7==5){
			a=n/7;
			cout<<"2";
			for(int i=1;i<=a;i++)cout<<"8";
			cout<<endl;
		}
		else if(n%7==6){
			a=n/7;
			cout<<"6";
			for(int i=1;i<=a;i++)cout<<"8";
			cout<<endl;
		}
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}