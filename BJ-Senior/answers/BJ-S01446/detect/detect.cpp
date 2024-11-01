#include <algorithm>//解法没问题，但是超时，差点死机
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#include <set>
using namespace std;
set<int>s;//记录超速车编号
int T,n,m;
double mn=2147483647;
double L,V;
struct CAR{
	double d,v,a;
	int stsize;
	set<double>st;//存检测到此车超速的测速仪编号
	double getv(double t){
		return sqrt(v*v+2*a*(t-d));//到达测速仪时速度
	}
}c[100010];
double p[100010];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		s.clear();
		int cnt=0,cnt1=0,cnt2=0;
		mn=2147483647;
		cin>>n>>m>>L>>V;
		bool A=true;
		for(int i=1;i<=n;i++){
			scanf("%lf%lf%lf",&c[i].d,&c[i].v,&c[i].a);
			mn=min(mn,c[i].d);
			if(c[i].a!=0)A=false;
			c[i].st.clear();
		}
		if(A==true){
			memset(p,0,sizeof p);
			for(int i=1;i<=m;i++)
			scanf("%lf",p+i);
			for(int i=1;i<=n;i++){
				if(c[i].v-V>0.0001){
					cnt1++;
					int pos=upper_bound(p+1,p+1+m,c[i].d)-p;
					if(pos==m+1)cnt1--;
					pos=n-pos+1;
					if(pos==1){//只有一个摄像头测到
						cnt2--;
					}
				}
			}
			if(cnt1==0)cnt2++;
			cout<<cnt1<<' '<<m+cnt2-1<<endl;
			continue;
		}		
		for(int i=1;i<=m;i++)
			scanf("%lf",p+i);
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(c[i].d>p[j])continue;
				if(c[i].getv(p[j])>V){//超速了
					c[i].st.insert(j);
					s.insert(i);
					//cout<<i<<endl;
				}
				else{
					if(c[i].a<=0){break;}//不超速且一直减速，直接停止判断
				}
			}
		}
		cout<<s.size()<<' ';
		
		//思考：删除测速仪的条件？
		//1：在这个测速仪中超速的车《都》被别的测速仪记录过超速 （样例1删[3]=8，[4]=9，不删[2]=5，[5]=15）
		//2：这个测速仪没有检测到任何的超速 （样例1删除[1]=2）
		
		//puts("");
		//for(int i=1;i<=m;i++)cout<<p[i]<<' ';
		//puts("");
		for(int i=1;i<=n;i++){
			c[i].stsize=c[i].st.size();
			//cout<<c[i].stsize<<"   ";
			//for(auto it:c[i].st)cout<<it<<' ';
			//puts("");
		}
		//puts("\n");
		for(int i=1;i<=m;i++){
			bool flag=true;
			for(int j=1;j<=n;j++){//1.   如果每个超速的车都有被别的摄像头检测到，那么这个摄像头无用
				//cout<<c[j].st.count(i)<<' '<<c[j].stsize<<"   ";
				if(c[j].st.count(i)&&c[j].stsize<=1){//如果这辆车被这个测速仪检测到，且只被这个测速仪检测到，那么不行
					flag=false;//没有检测到任何车超速就不会进if，然后就直接删掉了
					//cout<<"jumped: "<<i<<' '<<j<<' '<<p[i]<<endl;
					break;
				}
			}
			if(flag){//这个测速仪没用，被检测到的每辆车测速仪数量-1，删除数量+1
				//cout<<"delete: "<<i<<endl;
				cnt++;
				for(int j=1;j<=n;j++)
					if(c[j].st.count(i))c[j].stsize--;//如果被这个测速仪测到了，因为这个摄像头被删了，所以检测到这辆车的探测仪数量-1
			}
		}
		
		//puts("");
		//！！！
		//如果测速仪一个超速都没查到，删除
		//！！！
		
		//一个超速都没查到就在上面循环中实现了
		cout<<cnt<<'\n';
		
	}
	return 0;
}
