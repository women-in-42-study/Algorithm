#include <iostream>
#include <queue>

using namespace std;

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int bfs(queue<pair<int, int> > queue, int destX, int destY, int lineLen) {
    int answer  = 1;
    int map[301][301] = {0};
    map[queue.front().first][queue.front().second] = 1;
    while (!queue.empty()) {
        int qSize = queue.size();
        for(int j = 0; j < qSize; j++) {
            int x = queue.front().first;
            int y = queue.front().second;
            queue.pop();
            for(int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= lineLen || ny >= lineLen)
                    continue;
                if (nx == destX && ny == destY)
                    return answer;
                if (map[nx][ny] == 0) {
                    map[nx][ny] = 1;
                    queue.push(make_pair(nx, ny));
                }
            }
        }
        answer++;
    }
    return -1;
}

int main() {
    int T, lineLen, x, y, ans;

    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> lineLen >> x >> y;
        queue<pair<int, int> > queue;
        queue.push(make_pair(x, y));
        cin >> x >> y;
        if (queue.front().first == x && queue.front().second == y)
            ans = 0;
        else
            ans = bfs(queue, x, y, lineLen);
        cout << ans << "\n";
    }

}
