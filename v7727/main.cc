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

//#define __INPUT__
//#define __DEBUG__
//#define __PRINT__

int n;  // size of board
int m;  // num of friends

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int board[22][22];
int const_vis[22][22];
int vis[22][22];
vector<pair<int, int>> const_friends;

void print_config(string s) {
   cout.width(30);
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
   for (int i = 0; i < const_friends.size(); i++)
      cout << i << "st friend, x: " << const_friends[i].X << " y: " << const_friends[i].Y
           << "\n";
}

void print_visited() {
   print_config("visited");
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         cout.width(4);
         cout.fill(' ');
         if (vis[i][j])
            cout << "#" << " ";
         else
            cout << board[i][j] << " ";
      }
      cout << "\n";
   }
}

int move(int dir, pair<int, int> &f) {
   int nx = f.X + dx[dir];
   int ny = f.Y + dy[dir];

   if (vis[nx][ny]) {
#ifdef __DEBUG__
      cout << "x: " << nx << " y: " << ny << " already visited\n";
#endif
      return 0;
   }

   if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
#ifdef __DEBUG__
      cout << "x: " << nx << " y: " << ny << " out of board\n";
#endif
      return 0;
   }

   vis[nx][ny] = 1;
   f.X = nx;
   f.Y = ny;

#ifdef __DEBUG__
   cout << "x: " << nx << " y: " << ny << " earned: " << board[nx][ny] << "\n";
#endif
   return board[nx][ny];
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
      const_friends.push_back({input.X-1,input.Y-1});
   }

#ifdef __INPUT__
   print_board();
   print_friends();
#endif

   int steps = 3;
   int ncases = 1 << (2 * m * steps);
   int ans = 0;

   int init_sum = 0;
   for (int i = 0; i < m; i++) init_sum += board[const_friends[i].X][const_friends[i].Y];

   for (int i = 0; i < ncases; i++) {
      int sum = init_sum;
		vector<pair<int,int>> dyn_friends;
#ifdef __DEBUG__
      print_config("starting case " + to_string(i));
#endif
      fill_n(&vis[0][0], 22 * 22, 0);
      for (int pos = 0; pos < m; pos++){
			int nx=const_friends[pos].X;
			int ny=const_friends[pos].Y;

			vis[nx][ny] = 1;
			dyn_friends.push_back({nx,ny});
		}


      int tmp = i;
      int earn = 0;
      for (int j = 0; j < m; j++) {
         for (int k = 0; k < steps; k++) {
            int dir = tmp % 4;
            tmp /= 4;
            earn = move(dir, dyn_friends[j]);
            sum += earn;
            if (earn==0) break;
         }
         if (earn==0) {
#ifdef __DEBUG__
            cout << "breaking case\n";
#endif
            break;
         }
      }
      ans = max(ans, sum);
#ifdef __PRINT__
		if(earn!=0)
			print_visited();
#endif
   }

   cout << ans;
}
