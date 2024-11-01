#include <bits/stdc++.h>
using namespace std;
int nt;
int n,m,L,V;
struct car{
	int d;
	double v0;
	int a;
	double x1;//start
	double x2;//finish
	int p1;//start
	int p2;//finish
	int dleng;//amount of detectors that can detect the over speed.
	bool iffind;//whether the car is detected.
}c[114514];
bool cmp(car f1,car f2){
    return f1.dleng<f2.dleng;
}
//vector <int> dr[114514];
int drs[114514];
int p[114514];
bool fp[114514]={0};//0:off;  1:on
double dx;
int cnt; //detected cars
int de;//deleted p
bool dect(){
    int ned;
    bool ftr;
    for(int i=1;i<=n;i++){
        ftr=false;
        ned=c[i].p1;
        while(ned<=c[i].p2){
            if(fp[ned]=true)ftr=true;
        }
        if(!ftr)return false;
    }
    return true;
}
int re=0;
void clearall(){
    car p0;
    p0.a=0;
    p0.d=0;
    p0.dleng=0;
    p0.iffind=false;
    p0.p1=0;
    p0.p2=0;
    p0.v0=0;
    p0.x1=0;
    p0.x2=0;
    for(int i=1;i<=n;i++){
        c[i]=p0;
    }
    for(int i=1;i<=max(n,m);i++){
        drs[i]=0;
        p[i]=0;
        fp[i]=false;

    }
    dx=0;
    cnt=0;
    de=0;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>nt;
	for(int t=1;t<=nt;t++){ //最外层循环，别动
        clearall();
		//inputs----------------
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>c[i].d>>c[i].v0>>c[i].a;
		}
		for(int i=1;i<=n;i++)cin>>p[i];
		//deal every cars;
		for(int i=1;i<=n;i++){
			dx=0;
			if(c[i].a==0){
				if(c[i].v0>V){
					c[i].x1=c[i].d;
					c[i].x2=L;
				}
			}
			else if(c[i].a>0){
				if(c[i].v0>=V){
					c[i].x1=c[i].d;
					c[i].x2=L;
				}
				else{
					dx=(V*V-c[i].v0*c[i].v0)/(2*c[i].a);
					c[i].x1=c[i].d+dx;
					c[i].x2=L;
				}
			}
			else{
				if(c[i].v0>V){
					dx=(V*V-c[i].v0*c[i].v0)/(2*c[i].a);
					c[i].x1=c[i].d;
					c[i].x2=c[i].d+dx;
				}
			}

			//check
			//cout<<i<<" will over speed from "<<c[i].x1<<" to "<<c[i].x2<<endl;
		}
		//caculate x-->p
		for(int i=1;i<=n;i++){
			if(abs(c[i].x2-c[i].x1)<=0.000001)continue;
			int tp=1;
			if(c[i].a==0){
                if(c[i].v0>V)
                while(p[tp]<c[i].d and tp<m)tp++;
                c[i].p1=tp;
                if(c[i].p1!=0)c[i].p2=n;
			}
			else if(c[i].a<0){
                while(p[tp]<c[i].x1 and tp<m)tp++;
                c[i].p1=tp;
                while(p[tp]>c[i].x2 and tp<m+1)tp++;
                c[i].p2=tp;
                if(tp==m+1)c[i].p2=0;
			}
			else{
                while(p[tp]<c[i].x1 and tp<m)tp++;
                c[i].p1=tp;
                if(c[i].p1!=0)c[i].p2=n;
			}
			if(c[i].p1!=0 and c[i].p2!=0)cnt++;

			//check
			//cout<<i<<" will detected by "<<c[i].p1<<" to "<<c[i].p2<<" detector(s)"<<endl;
		}
		cout<<cnt<<" ";
		//lines together 这不会了，开始暴力！
		for(int i=1;i<=n;i++){
            if(c[i].p1==0 or c[i].p2==0)c[i].p1=c[i].p2=0;
            if(c[i].p1!=0 and c[i].p2!=0)c[i].dleng=c[i].p2-c[i].p1+1;
		}
		sort(c+1,c+n+1,cmp);
		int tpr=1;
		while(c[tpr].dleng==0)tpr++;
		while(c[tpr].dleng==1){
            fp[c[tpr].p1]=true;
            re++;
            tpr++;
		}
		//--only be detected by one detector.

		//how many detectors can be closed
		de=m;
		de-=re;
		cout<<de<<endl;
	}//最外层循环，别动
	return 0;
}
