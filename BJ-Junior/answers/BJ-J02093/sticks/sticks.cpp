#include<iostream>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int n;
		cin>>n;
		if(n>13){
			int co=(n%7)+7;
			if(co==7)cout<<8;
			if(co==8)cout<<10;
			if(co==9)cout<<18;
			if(co==10)cout<<22;
			if(co==11)cout<<20;
			if(co==12)cout<<28;
			if(co==13)cout<<68;
			for(int i=0;i<n/7-1;i++)cout<<8;
		}else{
			if(n==1)cout<<-1;
			if(n==2)cout<<1;
			if(n==3)cout<<7;
			if(n==4)cout<<4;
			if(n==5)cout<<2;
			if(n==6)cout<<6;
			if(n==7)cout<<8;
		}
		cout<<endl;
	}
	/* 
	define ((/= ^v^
	^v^ only wants money
	 true
	^v^ love computer
	 false
	^v^,oh ^v^,oh ^v^
	you le ni sheng huo mei hao mei fan nao
	^v^ legond qi miao zhi ji
	zui bang she qu,ren ren zan tan ni
	ru guo mei qian
	na jiu bu dui
	jin wan you dollar fou ze wo hui hou jiao
	wu lun bai tian,hai shi ye wan
	^v^ de quan qian rang wo yi fen bu sheng
	zai ku shu huo han dong
	^v^ de kao shi rang qian bao kong
	oh oh oh oh oh oh
	^v^ quan qian,qian bao qi kong
	^v^ cheng ba,quan qian bu chi
	ju ban kao shi
	......
	* * * *
	* | | *
	*     *
	* \_/ *
	*     *
	*     *
	* hi  *
	* i'm *
	* flo-*
	* wery*
	* * * *
	* * * * * - - * * * * * * * - - * * * * *
	* * * * / * * \ * * * * * / * * \ * * * *
	* * * / * * * * \ * * * / * * * * \ * * *
	* * / * * * * * * \ * / * * * * * * \ * *
	* / * * * * * * * * - * * * * * * * * \ *
	/ * * * * * * * * * * * * * * * * * * * \
	\ * * * * * * * * * * * * * * * * * * * /
	* \ * * * * * for CSP RP++!* * * * * / *
	* * \ * * * * * * * * * * * * * * * / * *
	* * * \ * * * * * * * * * * * * * / * * *
	* * * * \ * * * * * * * * * * * / * * * *
	* * * * * \ * * * * * * * * * / * * * * *
	* * * * * * \ * * * * * * * / * * * * * *
	* * * * * * * \ * * * * * / * * * * * * *
	* * * * * * * * \ * * * / * * * * * * * *
	* * * * * * * * * _ _ _ * * * * * * * * *
	*/
	
}
