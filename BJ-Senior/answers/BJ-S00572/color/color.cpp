#include <bits/stdc++.h>
using namespace std;
int t,n;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		int a[100005],cnt=0;
		for(int i=0;i<n;i++){
			int t;
			cin>>t;
			a[t]++;	
		}
		for(int i=0;i<n;i++){
			if(a[i]>2){
				cnt+=i*(a[i]/2);
			}
		}
		cout<<cnt;
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}







































/*
	人死为鬼，鬼死为你，你死为雟，雟死为魍，魍死无形，无极生太极，太极生四舅，四舅生八仔，八仔爱喝奶，喝下这瓶奶，忘掉那个仔
	水绿则深，水黑则渊，鳝大成蛇，蛇大成蟒，蟒大成蛟，蛟大成龙，龙大成王，王中王，火腿肠，一节更比六节长，果冻我选喜之郎，喜之郎，不一般
	马可波罗是瓷砖，能上墙，能贴地，
*/