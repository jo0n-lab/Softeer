#include<bits/stdc++.h>
using namespace std;

#define __INPUT__
#define __DEBUG__
#define __PRINT__

#define X first
#define Y second

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int R,C;
char board[1002][1002];

void print_config(string s){
	cout.width(15);
	cout.fill('-');
	cout<<s<<"\n";
}

void print_board(){
	print_config("board");
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cout.width(2);
			cout.fill(' ');
			cout<<board[i][j]<<" ";
		}
		cout<<"\n";
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>R>>C;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin>>board[i][j];
		}
	}

	

