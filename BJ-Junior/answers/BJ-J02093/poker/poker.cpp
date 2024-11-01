#include<iostream>
using namespace std;
int a[100];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		//cout<<n;
		char N,Tc;
		char Ps;
		cin>>N;
		//cout<<"QWQ";
		//cout<<N<<endl;
		cin>>Tc;
		//cout<<"QWQ";
		//cout<<N<<' '<<Tc<<endl;
		if(N=='D')Ps=0;
		if(N=='C')Ps=13;
		if(N=='H')Ps=26;
		if(N=='S')Ps=39;
		if(Tc=='A')Tc='1';
		if(Tc=='T')Tc=':';
		if(Tc=='J')Tc=';';
		if(Tc=='Q')Tc='<';
		if(Tc=='K')Tc='=';
		//cout<<(int)Ps<<' '<<(int)Tc-'1'<<endl;
		//cout<<(int)Ps+Tc-'1'<<endl;
		a[(int)((char)Ps+Tc-'1')]++;
	}
	int ans=52;
	for(int i=0;i<52;i++)ans-=(bool)a[i];
	cout<<ans;
        // ^v^ want to see my code?no way~
}
