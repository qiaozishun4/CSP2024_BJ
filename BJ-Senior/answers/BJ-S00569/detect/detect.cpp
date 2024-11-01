#include<bits/stdc++.h>
using namespace std;
typedef double db;
const int N=1e5+5;
db n,m,l,V,t;
//n表示车辆数量，m表示测速仪数量，l表示主干道长度，V表示道路限速
db d[N],a[N],v[N],p[N],con[N];
//d表示进入位置，a表示加速度，v表示加速度，p表示测速仪位置
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		map <int,int> mp1;
		int ans;
		memset(con,0,sizeof(con));
		vector <int> vec[N];
		cin>>n>>m>>l>>V;
		ans=m;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
			for(int j=1;j<=n;j++){
				if(d[j]>p[i]) continue;
				if(a[j]==0){
					if(V<v[j]){
						vec[i].push_back(j);
						mp1[j]++;
					}
					continue;
				}
				if((v[j]*v[j])+(2*a[j]*(p[i]-d[j]))<0) continue;
				db s=sqrt((v[j]*v[j])+(2*a[j]*(p[i]-d[j])));
				//cout<<s<<' ';
				if(s>V){
					vec[i].push_back(j);
					mp1[j]++;
				}
			}
			//cout<<endl;
		}
		for(int i=1;i<=m;i++){
			map <int,int> mp2;
			if(!vec[i].size()){
				ans--;
				continue;
			}
			con[i]=1;
			for(int j=1;j<=m;j++){
				if(con[j]) continue;
				for(unsigned int k=0;k<vec[j].size();k++){
					mp2[vec[j][k]]++;
					//cout<<vec[j][k]<<' ';
				}
				//cout<<endl;
			}
			//cout<<endl<<endl;
			//cout<<mp1.size()<<' '<<mp2.size()<<'\n';
			if(mp2.size()!=mp1.size()){
				con[i]=0;
			}
			else ans--;
		}
		cout<<mp1.size()<<' '<<m-ans<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}