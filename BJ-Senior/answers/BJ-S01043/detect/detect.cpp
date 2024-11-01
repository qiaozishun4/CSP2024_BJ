#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 1e5;

int t,n,m,l,v;

struct Interval{
	int l,r;
};

bool operator < (Interval a,Interval b){
	return a.r < b.r;
}

Interval chaos[maxn + 5];
int cam[maxn + 5];

int ceil(int x,int y){
	if(x % y == 0) return x / y;
	else return x / y + 1;
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n >> m >> l >> v;
		for(int i = 1;i <= n; i++){
			int a,d,vv;
			cin >> d >> vv >> a;
			//求出超速区间。
			chaos[i] = {l+1,l+1};
			if(a >= 0 && vv > v) chaos[i] = {d,l+1};
			if(a < 0 && vv > v){
				int gopos = vv*vv/(2*-a)+d;//除法求右端点。
				chaos[i] = {d,min(ceil(vv*vv-v*v,2*(-a))+d,l+1)};
			}
			if(a > 0 && vv <= v)
				chaos[i] = {(v*v-vv*vv)/(2*a)+1+d,l+1};
//			cout << chaos[i].l << " " << chaos[i].r << endl;
		}
		//cout << "how shit you are!" << endl;
		for(int i = 1;i <= m; i++) cin >> cam[i];
		sort(cam + 1,cam + m + 1);
		sort(chaos + 1,chaos + n + 1);
		int cntcam = 0,cntint = 0;
//		for(int i = 1;i <= n; i++) cout << chaos[i].l << " " << chaos[i].r << endl;
//		for(int i = 1;i <= m; i++) cout << cam[i] << " ";
//		cout << endl;
		for(int i = 1,j = 0;i <= n; i++){
			int l = chaos[i].l,r = chaos[i].r;//暂时覆盖一下外面的l
			if(l > r) continue;//没超速，看他干吗
//			cout << j << endl;
			if(cam[j] >= l && cam[j] < r){
				cntint++;//能管上
//				cout << "i:" << i << endl;
				continue;//能管上，管它干吗
			}
			int lstj = j;
			while(cam[j+1] < r && j < m) j++;//找到能管上的最北点。
			if(cam[j] >= l && cam[j] < r) cntint++,cntcam++;
			else j = lstj;
		}
		cout << cntint << " " << m - cntcam << endl;
	}
	
	
	return 0;
}//对于每一辆车，都有超速区间（带有浮点数，可以二分出答案），我们只需要看有几个超速区间里包含摄像头，以及这些超速区间至少需要多少摄像头管住。
/*
因此，正解应运而生。
先对区间右端点排序，再对摄像头排序。扫一遍摄像头，记录当前超速区间
*/
/*
附：我的对拍代码（只支持一定目录结构，当前目录里有题目名目录，里面有数据和选手代码。）
#include <iostream>
#include <cstdlib>
using namespace std;

char buf[105];

int main(int argc,char** argv){
	int l,r;
	for(int i = 1;i < argc; i++){
		if(argv[i][0] == '-' && argv[i][1] == 'h' || argv[i][0] == '-' && argv[i][1] == '-' && argv[i][2] == 'h' && argv[i][3] == 'e' && argv[i][4] == 'l' && argv[i][5] == 'p'){
			cout << "Usage:./a.out lt rt name [--help][-h]" << endl;
			cout << "where lt is left test id rt is right test id,name is problem's name" << endl;
			cout << "--help,-h means you need help.you cannot goes to man." << endl;
			cout << "it can tests your code's effect,and can you AC this problem." << endl;
			cout << "it can also give your wrong samples!!!!" << endl;
			return 0;
		}
	}
	sscanf(argv[1],"%d",&l);
	sscanf(argv[2],"%d",&r);
	sprintf(buf,"g++ %s/%s.cpp -o %s.exe",argv[3],argv[3],argv[3]);
	cout << buf << endl;
	system(buf);
	for(int i = l;i <= r; i++){
		sprintf(buf,"mv %s/%s%d.in ./%s.in",argv[3],argv[3],i,argv[3]);
		system(buf);
		sprintf(buf,"./%s.exe",argv[3]);
		system(buf);
		sprintf(buf,"diff %s/%s%d.ans ./%s.out > gmon.out",argv[3],argv[3],i,argv[3]);
		if(system(buf)) cout << "WA" << endl;
		else cout << "AC" << endl;
		sprintf(buf,"mv ./%s.in %s/%s%d.in",argv[3],argv[3],argv[3],i);
		system(buf);
		sprintf(buf,"mv ./%s.out %s/%s%d.out",argv[3],argv[3],argv[3],i);
		system(buf);
	}
	
	
	return 0;
}
*/