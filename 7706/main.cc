#include<bits/stdc++.h>
using namespace std;

#define __INPUT__
#define __DEBUG__
#define __PRINT__


int N,K,H;
vector<tuple<int,int,int>> patterns;
int board[200002];

void print_config(string s){
	cout.width(15);
	cout.fill(' ');
	cout<<s<<"\n";
}

void print_board(){
	print_config("board");
	for(int i=0;i<N;i++)
		cout<<board[i];
	cout<<"\n";
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int INF=0x7f7f7f7f;

	cin>>N>>K>>H;
	for(int p=0;p<K;p++){
		int i,j,x;
		cin>>i>>j>>x;
		patterns.push_back({i,j,x});
	}

	int steps=H;
	int options=K;
	int tot_case=1<<(steps*options);

	for(int ncase=0;ncase<tot_case;ncase++){










