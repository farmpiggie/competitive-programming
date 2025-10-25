#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int i,j,k,n,m,t,a[100500],vis[34050];
vector<int> p;
 
int main(){
	ios::sync_with_stdio(0);
	for(i=2;i<=34000;i++){
		if(!vis[i]){
			p.push_back(i);
			for(j=i;j<=34000;j+=i)vis[j]=1;
		}
	}
	cin>>t;
	while(t--){
		cin>>n;
		map<int,int> mp;
		for(i=1;i<=n;i++)cin>>a[i];
		for(i=1;i<=n;i++){
			k=a[i];
			for(auto j:p){
				if(!(a[i]%j)){
					if(mp[j]){
						cout<<"YES\n";goto aaa;
					}
					mp[j]=1;
					while(!(k%j))k/=j;
				}
			}
			if(k-1&&mp[k]){
				cout<<"YES\n";goto aaa;
			}mp[k]++;
		}
		cout<<"NO\n";
		aaa:;
	}
}