#include <bits/stdc++.h>

using namespace std;

vector<int> sx; // scooter locations
vector<int> sy;
vector<bool> done; // if scooter is done
int X, Y; // my location
int A, B; // depot location
int N;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string output[4] = {"right", "up", "left", "down"};

void move(int sid, int dir) {
    int nx = sx[sid] + dx[dir];
    int ny = sy[sid] + dy[dir];
    for(int i = 0; i<N; i++) {
        if(i==sid || done[i]) continue;
        if(sx[i] == nx && sy[i] == ny) {
            move(i, dir);
            break;
        }
    } 
    sx[sid] = nx;
    sy[sid] = ny;
    if(nx == A && ny == B) done[sid] = true;
}

void walk(int dir) {
    int nx = X + dx[dir];
    int ny = Y + dy[dir];
    for(int i = 0; i<N; i++) {
        if(done[i]) continue;
        if(sx[i] == nx && sy[i] == ny) {
            move(i, dir);
            break;
        }
    }
    X = nx;
    Y = ny;
    cout << output[dir] << '\n';
}

void moveto(int x, int y, int dir) { // do not pass through x, y
    // move to x-1, y-1 
    // then to correct location
    if(x - X == 0) walk(2);
    if(y - Y == 0) walk(3);
    while(x - X > 1) {
        walk(0);
    }
    while(x - X < 1) {
        walk(2);
    }
    while(y - Y > 1) {
        walk(1);
    }
    while(y - Y < 1) {
        walk(3);
    }

    if(dir == 0) {
        walk(1);
    }
    else if(dir == 1) {
        walk(0);
    }
    else if(dir == 2) {
        walk(0);
        walk(0);
        walk(1);
    }
    else {
        walk(1);
        walk(1);
        walk(0);
    }

}

int main() {

    cin >> N;

    cin >> X >> Y >> A >> B;

    for(int i = 0; i<N; i++) {
        int a, b;
        cin >> a >> b;
        sx.push_back(a);
        sy.push_back(b);
        if(a == A && b == B) done.push_back(true);
        else done.push_back(false);
    }

    for(int curr = 0; curr < N; curr++) { // pick a scooter to move to depot
        if(done[curr]) continue;
        int xx = A - sx[curr];
        int yy = B - sy[curr];
        if(xx < 0) {
            moveto(sx[curr], sy[curr], 2);
            while(X-A > 1) {
                walk(2);
            }
        }
        else if(xx > 0) {
            moveto(sx[curr], sy[curr], 0);
            while(A-X > 1) {
                walk(0);
            }
        }
    
        if(yy < 0) {
            moveto(sx[curr], sy[curr], 3);
            while(Y-B > 1) {
                walk(3);
            }
        }
        else if(yy > 0) {
            moveto(sx[curr], sy[curr], 1);
            while(B-Y > 1) {
                walk(1);
            }
        }
            
    }

    cout << flush;

}