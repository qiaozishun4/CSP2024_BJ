#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
using namespace std;
vector<int>v;
priority_queue<int>q;
map<int,int>mp;
int T,a[200010],n;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		while(!q.empty())q.pop();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",a+i);
			mp[a[i]]++;
		}
		if((int)mp.size()==n){puts("0");continue;}//无重复数字，则输出0
		for(auto i:mp)
			if(i.second>=2){
				v.push_back(i.first);
				q.push(i.first);
			}
		int x=q.top(),xl=0,xr=0;
		q.pop();
		int y=q.top(),yl=0,yr=0;
		q.pop();
		bool f=false;
		while(!q.empty()){
			for(int i=1;i<=n;i++){
				if(a[i]==x&&xl==0)xl=i;
				if(a[i]==y&&yl==0)yl=i;
				if(xl&&yl)break;
			}
			for(int i=n;i>=1;i--){
				if(a[i]==x&&xr==0)xr=i;
				if(a[i]==y&&yr==0)yr=i;
				if(xr&&yr)break;
			}
			if(xl>yl){
				swap(xl,yl);
				swap(xr,yr);
				swap(x,y);
			}
			bool flag=false;
			if(xr>yl&&xr<yr){//有交集 xyxy
				//___xl___yl___xr___yr___
				for(int i=n;i>yr;i--)
					if(a[i]==x){flag=true;break;}//xyyx
				for(int i=yr-1;i>xr;i--)
					if(a[i]==y){flag=true;break;}//xxyy
				for(int i=xr-1;i>yl;i--)
					if(a[i]==y){flag=true;break;}//xyyx
				for(int i=yl-1;i>xl;i--)
					if(a[i]==x){flag=true;break;}//xxyy
				for(int i=xl-1;i>=1;i--)
					if(a[i]==y){flag=true;break;}//yxxy
				if(flag){
					f=true;
					printf("%d\n",x+y);
					break;
				}
			}
			else{
				f=true;
				printf("%d\n",x+y);
				break;
			}
			if(flag==false){
				if(x<y)
					swap(x,y);
				y=q.top();
				q.pop();
			}
		}
		if(!f)printf("%d\n",x+y);
	}
	return 0;
}
//5 3 7 2 4 13 11 6 5 5 3 5 12 8 13
//5 3 13 5 5 3 5 13   
