#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
using namespace std;
int n, m;
int arr[1000][1000];
pair<int,int> frr[1000][1000];
pair<int,int> start;
queue <pair<int,int>> monsters;
string path;
bool possible = false;
void pathh(pair<int,int> fd){
    pair<int,int> s = frr[fd.first][fd.second];
    if(fd == start){
        return;
    }
    if(s.first == fd.first + 1){
        path.push_back('U');
    }
    if(s.first == fd.first - 1){
        path.push_back('D');
    }
    if(s.second == fd.second + 1){
        path.push_back('L');
    }
    if(s.second == fd.second - 1){
        path.push_back('R');
    }
    pathh(s);
}
void bfs(bool a){
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while(!monsters.empty()){
        pair<int,int> mpoint = monsters.front();
        monsters.pop();
        for(const auto& onedir : directions){
            pair<int,int> nextp = {mpoint.first + onedir.first, mpoint.second + onedir.second};
            if(nextp.first >= 0 && nextp.first < n && nextp.second >= 0 && nextp.second < m){
                int cc = arr[mpoint.first][mpoint.second] + 1;
                if(cc < arr[nextp.first][nextp.second]){
                    arr[nextp.first][nextp.second] = cc;
                    monsters.push(nextp);
                    frr[nextp.first][nextp.second] = mpoint;
                }
            }
        }
        if(a && (mpoint.first == 0 || mpoint.first == n-1 || mpoint.second == 0 || mpoint.second == m-1)){
            possible = true;
            pathh(mpoint);
            return; 
        }
    }
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        char c;
        for(int j = 0; j < m; j++){
            cin >> c;
            if(c == 'A'){
                start = {i,j};
            }
            if(c == 'M'){
                monsters.push({i,j});
            }
            if(c == '#'){
                arr[i][j] = -1;
            }
            if(c == '.'){
                arr[i][j] = INT_MAX;
            }
        }
    }
    bfs(false);
    arr[start.first][start.second] = 0;
    frr[start.first][start.second] = {0,0};
    monsters.push(start);
    bfs(true);
    if(possible){
        cout << "YES\n"; 
        cout << path.size() << "\n";
        reverse(path.begin(), path.end());
        cout << path << "\n";
    }
    else{
        cout << "NO\n";
    }
    return 0;
}
