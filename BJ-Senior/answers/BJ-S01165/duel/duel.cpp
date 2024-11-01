#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	int m=n,r[n],mx=0;
	for (int i=0;i<n;i++){
        cin>>r[i];
        if (r[i]>=mx) mx=r[i];
	}
	int a[mx+1]={};
	for (int i=0;i<n;i++){
        a[r[i]]++;
	}
	for (int i=2;i<=mx;i++){
	    int p=i-1;
        for (int j=1;j<=a[i];j++){
            while (!a[p]){
                p--;
                if (p==0) break;
            }
            if (p==0) break;
            a[p]--;
            m--;
        }
	}
	cout<<m;
	return 0;
}