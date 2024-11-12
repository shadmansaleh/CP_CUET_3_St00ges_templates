
typedef pair<int, int> Point;

// Function to determine the orientation of the triplet (p, q, r).
int orientation(const Point& p, const Point& q, const Point& r) {
    int val = (q.second - p.second) * (r.first - q.first) - (q.first - p.first) * (r.second - q.second);
    if (val == 0) return -1;            // Collinear
    return (val > 0) ? 1 : -1;          // Clockwise or Counterclockwise
}

// Function to compute the convex hull using Andrew's monotone chain algorithm
vector<Point> convexHull(vector<Point>& points) {
    int n = points.size();
    if (n < 3) return points;

    // Sort points lexicographically (by x first, then by y)
    sort(points.begin(), points.end());

    vector<Point> hull;

    // Build the lower hull
    for (int i = 0; i < n; ++i) {
        while (hull.size() >= 2 && orientation(hull[hull.size() - 2], hull.back(), points[i]) != -1) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    // Build the upper hull, avoiding the last point of the lower hull
    for (int i = n - 2, t = hull.size() + 1; i >= 0; --i) {
        while (hull.size() >= t && orientation(hull[hull.size() - 2], hull.back(), points[i]) != -1) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    hull.pop_back(); // Remove the last point because it is the same as the first one

    return hull;
}
