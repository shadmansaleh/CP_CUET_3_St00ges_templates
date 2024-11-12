// To find the closest pair of points
long long
closestPair(vector<pair<long long, long long> > coordinates,
            int n)
{
    // Sort points according to x-coordinates
    sort(coordinates.begin(), coordinates.end());

    // Set to store already processed points whose distance
    // from the current points is less than the smaller
    // distance so far
    set<pair<long long, long long> > s;

    long long squaredDistance = LLONG_MAX;
    long long j = 0;

    for (long long i = 0; i < n; ++i) {
        // Find the value of D
        long long D = ceil(sqrtl(squaredDistance));
        while (coordinates[i].first - coordinates[j].first >= D) {
            s.erase({ coordinates[j].second, coordinates[j].first });
            j += 1;
        }

          // Find the first point in the set whose y-coordinate is less than D distance from ith point
        auto start
            = s.lower_bound({ coordinates[i].second - D,
                              coordinates[i].first });
          // Find the last point in the set whose y-coordinate is less than D distance from ith point
        auto end
            = s.upper_bound({ coordinates[i].second + D,
                              coordinates[i].first });

          // Iterate over all such points and update the minimum distance
        for (auto it = start; it != end; ++it) {
            long long dx = coordinates[i].first - it->second;
            long long dy = coordinates[i].second - it->first;
            squaredDistance = min(squaredDistance, 1LL * dx * dx + 1LL * dy * dy);
        }

          // Insert the point as {y-coordinate, x-coordinate}
        s.insert({ coordinates[i].second,
                   coordinates[i].first });
    }
    return squaredDistance;
}
closestPair(v,v.size());
