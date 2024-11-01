#include<bits/stdc++.h>
using namespace std;
int n;
int a[100010];
int f[100010],usable[100010];
int cnt;
int ptr=1;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[a[i]]++;
	}
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-a-1;
	for(int i=1;i<=100000;i++)usable[i]=f[i];
	for(int i=1;i<=n;i++){
		if(ptr>n)break;
		while(ptr<=i)ptr++;
		while(ptr<=n&&f[a[i]]){
			int num=min(f[a[i]],usable[a[ptr]]);
			f[a[i]]-=num;
			usable[a[ptr]]-=num;
			if(usable[a[ptr]]==0)ptr++;
		}
	}
	for(int i=1;i<=n;i++)cnt+=f[a[i]];
	cout<<cnt;
}