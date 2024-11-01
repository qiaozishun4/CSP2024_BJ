#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+10;
string f[maxn];
ll t,n;
//int dx[]={2,3,4,5,6,7};
//string dy[]={"1","7","4","2","0","8"};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	/*for(int i=1;i<=maxn;i++){
		f[i]="A";
	}
	f[2]="1";
	f[6]="0";
	f[5]="2";
	f[4]="4";
	f[3]="7";
	f[7]="8";
	for(int i=8;i<=maxn;i++){
		for(int j=0;j<6;j++){
			int p=i-dx[j];
			if(f[p]=="A")continue;
			if(dx[i]==6&&f[p]=="0"){
				string t="60";
				f[i]=min(f[i],t);
			}
			else{
				string t1=dy[j]+f[p];
				string t2=f[p]+dy[j];
				f[i]=min(f[i],min(t1,t2));
			}
		}
	}*/
	while(t--){
		cin>>n;
		if(n<=20){
			if(n==1)cout<<-1<<endl;
			if(n==2)cout<<1<<endl;
			if(n==3)cout<<7<<endl;
			if(n==4)cout<<4<<endl;
			if(n==5)cout<<2<<endl;
			if(n==6)cout<<0<<endl;
			if(n==7)cout<<8<<endl;
			if(n==9)cout<<24<<endl;
			if(n==10)cout<<23<<endl;
			if(n==11)cout<<20<<endl;
			if(n==12)cout<<60<<endl;
			if(n==13)cout<<80<<endl;
			if(n==14)cout<<88<<endl;
			if(n==15)cout<<23<<endl;
			if(n==16)cout<<188<<endl;
			if(n==17)cout<<200<<endl;
			if(n==18)cout<<280<<endl;
			if(n==19)cout<<288<<endl;
			if(n==20){
				cout<<688<<endl;
			}
		}
		else if(n%7==0){
			ll p=n/7;
			for(int i=1;i<=p;i++){
				cout<<'8';
			}
			cout<<endl;
		}
		else if((n-1)%7==0){
			cout<<'1';
			cout<<'0';
			ll p=(n-8)/7;
			for(int i=1;i<=p;i++){
				cout<<'8';
			}
			cout<<endl;
		}
		else{
			cout<<-1<<endl;
		}
	}
	return 0;
}
