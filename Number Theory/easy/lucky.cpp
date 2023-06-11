#include<bits/stdc++.h>
using namespace std;



int main(){
	long long n;cin>>n;
	
	long long cnt=0;
	while(n){
		long long ld=n/10;
		if(ld==4 or ld==7)cnt++;
		n/=10;
	}

	bool flag=true;
	while(cnt){
		long long ld=cnt%10;
		if(ld!=4 or ld!=7){
			flag=false;
			break;
		}
	}

	if(flag)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;


	return 0;
}