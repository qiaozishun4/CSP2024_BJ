#include<iostream>
using namespace std;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int c;
	cin>>c;
	for(int i=0;i<c;i++){
		int n,m,k,nn,mm,h,ans=1;
		char a[1001][1001];
		cin>>n>>m>>k>>nn>>mm>>h;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		a[nn][mm]=char(h+'0');
		for(int i=0;i<k;i++){
			cout<<'Q';
			if(h==0){
				if(a[nn][mm+1]=='x'||mm+1>m) h=1;
				else{
					mm++;
					if(a[nn][mm]=='.') ans++;
				}
            a[nn][mm]=char(h+'0');
			}else if(h==1){
				if(a[nn+1][mm]=='x'||nn+1>n) h=2;
				else{
					nn++;
					if(a[nn][mm]=='.') ans++;
				}
				a[nn][mm]=char(h+'0');
			}else if(h==2){
				if(a[nn][mm-1]=='x'||mm-1<1) h=3;
				else{
					mm--;
					if(a[nn][mm]=='.') ans++;
				}
				a[nn][mm]=char(h+'0');
			}else if(h==3){
				if(a[nn-1][mm]=='x'||nn-1<1) h=0;
				else{
					nn--;
					if(a[nn][mm]=='.') ans++;
				}
				a[nn][mm]=char(h+'0');
			}
			if(a[nn][mm]==char(h+'0')) break;
		}
		cout<<ans<<endl;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}