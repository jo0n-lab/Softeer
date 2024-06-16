#include <bits/stdc++.h>
using namespace std;

// TODO
// m friends picking fruit
// return max num of picked with the limited time 3seconds
// 2<=n<=20
// 1<=m<=3
// 1<=max_fruit<=1000

#define X first
#define Y second

#define __INPUT__
#define __DEBUG__
#define __PRINT__

int n;  // size of board
int m;  // num of friends

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int board[22][22];
int vis[22][22];
vector<pair<int, int>> friends;

void print_config(string s) {
   cout.width(15);
   cout.fill('-');
   cout << s << "\n";
}

void print_board() {
   print_config("board");
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         cout.width(4);
         cout.fill(' ');
         cout << board[i][j] << " ";
      }
      cout << "\n";
   }
}

void print_friends() {
   print_config("friends");
   for (int i = 0; i < friends.size(); i++)
      cout << i << "st friend, x: " << friends[i].X << " y: " << friends[i].Y
           << "\n";
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> n >> m;

   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         cin >> board[i][j];
      }
   }

   for (int i = 0; i < m; i++) {
      pair<int, int> input;
      cin >> input.X >> input.Y;
      friends.push_back(input);
   }

#ifdef __INPUT__
   print_board();
   print_friends();
#endif
}
