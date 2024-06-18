#include <bits/stdc++.h>
using namespace std;

//#define __INPUT__
//#define __DEBUG__
//#define __PRINT__

#define X first
#define Y second

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m;
char board[1002][1002];

pair<int, int> player;
pair<int, int> ext;
vector<pair<int, int>> ghosts;

void print_config(string s) {
   cout.width(20);
   cout.fill('-');
   cout << s << "\n";
}

void print_board() {
   print_config("board");
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         cout.width(2);
         cout.fill(' ');
         cout << board[i][j] << " ";
      }
      cout << "\n";
   }
}

int BFS(pair<int, int> pos, bool is_player) {
   int initx = pos.X;
   int inity = pos.Y;

	if(!is_player) return abs(ext.X-pos.X)+abs(ext.Y-pos.Y);
   
	int dist[1002][1002];
   fill_n(&dist[0][0], 1002 * 1002, -1);
   dist[initx][inity] = 0;

   if (is_player) {
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
            if (board[i][j] == '#') dist[i][j] = 0;
         }
      }
   }

   queue<pair<int, int>> Q;
   Q.push({initx, inity});

   while (!Q.empty()) {
      pair<int, int> cur = Q.front();
      Q.pop();
      for (int dir = 0; dir < 4; dir++) {
         int nx = cur.X + dx[dir];
         int ny = cur.Y + dy[dir];
         if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
         if (dist[nx][ny] >= 0) continue;
         if (nx == ext.X && ny == ext.Y) return dist[cur.X][cur.Y] + 1;

         dist[nx][ny] = dist[cur.X][cur.Y] + 1;
         Q.push({nx, ny});
      }
   }
   return -1;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> n >> m;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         char input;
         cin >> input;
         board[i][j] = input;
         if (input == 'G')
            ghosts.push_back({i, j});
         else if (input == 'N') {
            player.X = i;
            player.Y = j;
         } else if (input == 'D') {
            ext.X = i;
            ext.Y = j;
         }
      }
   }

#ifdef __INPUT__
   print_board();
#endif

   int ghost_shortest = 0x7f7f7f7f;
   for (int i = 0; i < ghosts.size(); i++) {
      int tmp = BFS(ghosts[i], false);
      ghost_shortest = min(tmp, ghost_shortest);
   }

   int player_shortest = BFS(player, true);

   if (player_shortest < 0 || ghost_shortest < player_shortest)
      cout << "No";
   else
      cout << "Yes";
}
