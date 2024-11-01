#include<iostream>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int a,n[55];
	cin>>a;
	for(int i=0;i<a;i++) cin>>n[i];
	for(int i=0;i<a;i++){
		int m=0;
		if(n[i]%7==0){
			for(int j=0;j<n[i]/7;j++) cout<<'8';
			m=1;
		}
		else if(n[i]<2) cout<<"-1";
		else if(n[i]==2) cout<<'1';
		else if(n[i]==3) cout<<'7';
		else if(n[i]==4) cout<<'4';
		else if(n[i]==5) cout<<'2';
		else if(n[i]==6) cout<<'6';
		else if(n[i]==8) cout<<"10";
		else if(n[i]==9) cout<<"18";
		else if(n[i]==10) cout<<"22";
		else if(n[i]==11) cout<<"20";
		else if(n[i]==12) cout<<"28";
		else if(n[i]==13) cout<<"68";
		if(m==0&&n[i]>14){
			int y=n[i]%7;
			if(y==1) cout<<"108";
			else if(y==2) cout<<"188";
			else if(y==3) cout<<"200";
			else if(y==4) cout<<"208";
			else if(y==5) cout<<"288";
			else if(y==6) cout<<"688";
			for(int j=2;j<(n[i]-y)/7;j++) cout<<'8';
		}
		cout<<endl;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}