#include <bits/stdc++.h>
#include <random>
using namespace std;

typedef pair<double, double> pt;

double dist(pt& one, pt& two) {
    double dx = two.first-one.first;
    double dy = two.second-one.second;
    return dx*dx + dy*dy;
}

int compute(vector<pt> points) {
    default_random_engine generator;
    uniform_real_distribution<double> distribution(0.0, 2*M_PI);
    double angle = distribution(generator);

    int N = points.size();
    for(int i = 0; i<N; i++) {
        double x = points[i].first*cos(angle)-points[i].second*sin(angle);
        double y = points[i].first*sin(angle)+points[i].second*cos(angle);
        points[i] = make_pair(x, y);
        cout << x << " " << y << endl;
    }


}

int main() {

    int N;
    cin >> N;

    vector<pt> points;
    for(int i = 0; i<N; i++) {
        double a, b;
        cin >> a >> b;
        points.emplace_back(a, b);
    }

    compute(points);

}