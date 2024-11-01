#include<iostream>
#include<algorithm>
using namespace std;
class car{
	public:
	double d,v,a;
	double getrd(int spd){
		return d+((double)(spd*spd)-v*v)/(2.0*a);
	}
}c[100005];
double p[100005];
struct pts{
	double x=0,y=0;
}ara[100005];
bool cmp(pts a,pts b){
	return a.x<b.x;
}
int main(){
	int T;
	cin>>T;
freopen("detect.in","r",stdin);
freopen("detect.out","w",stdout);
	for(int sogan=0;sogan<T;sogan++){
		int n,m,L,V,ans1=0,ans2=0;
		cin>>n>>m>>L>>V;
		for(int i=0;i<n;i++){
			cin>>c[i].d>>c[i].v>>c[i].a;
		}
		for(int i=0;i<m;i++){
			cin>>p[i];
		}
		for(int i=0;i<n;i++){
			if(c[i].a>(double)0&&c[i].getrd(V)<=(double)p[m]){
				ans1++;
				ara[i].x=c[i].d;
				ara[i].y=min(c[i].getrd(V),(double)L);
				//cout<<"ans++"<<endl;
			}
			if(c[i].a<(double)0&&c[i].getrd(V)>=(double)p[0]){
				ans1++;
				ara[i].x=c[i].d;
				ara[i].y=max((double)0,c[i].getrd(V));
				//cout<<"ans++"<<endl;
			}
			if(c[i].a==(double)0&&c[i].v>V){
				ans1++;
				ara[i].x=c[i].d;
				ara[i].y=L;
				//cout<<"ans++"<<endl;
			}
		}
		cout<<ans1;
		sort(ara,ara+n,cmp);
		int now=0;
		double miny=1000000.0;
		/*for(int i=0;i<m;i++){
			cout<<p[i]<<endl;
			cout<<ara[now].x<<endl;
			cout<<ara[i].y<<endl;
		}*/
		for(int i=0;i<m;i++){
			//cout<<ara[now].x<<endl;
			while(ara[now].x<p[i]&&now<=n){
				miny=min(miny,ara[now].y);
				//cout<<ara[now].x<<endl;
				//cout<<'<'<<p[i]<<endl;
				cout<<now<<':'<<ara[now].x<<' '<<ara[now].y<<endl;
				now++;
			}
			if(p[i]>miny){
				ans2++;
			}
		}
		cout<<' '<<ans2<<endl;
	}
}