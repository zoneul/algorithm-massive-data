#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};
vector<Point> stream; // simulation of streaming data

double distance(const Point& a, const Point& b){ return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)); }

bool streaming_k_center(int k, double r)
{
    vector<Point> centers;

    for(auto& point : stream)
    {
        if(any_of(centers.begin(), centers.end(), [&](const Point& c) { return distance(c, point) <= 2*r; }))
            continue;
        else if (centers.size() < k)
            centers.push_back(point);
        else
            return false; // not feasible
    }

    return true; // feasible
}

int main()
{
    int k = 10; // number of centers

    double x, y;
    freopen("dataset\\bangkok_points.txt", "r", stdin);
    while(cin >> x >> y) stream.push_back({x, y});

    double low = 0, high = 1e6;
    while(high - low > 1e-6) // binary search for optimal r
    {
        double rad = (low + high) / 2;
        if(streaming_k_center(k, rad)) 
            high = rad; // feasible, try smaller
        else
            low = rad; // try larger
    }
    cout << "Minimum radius: " << high << endl;

    return 0;
}