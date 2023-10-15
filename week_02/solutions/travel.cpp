#include <iostream>

int main() {
    int h, m, t, dt;

    std::cin >> h >> m >> t >> dt;

    int minTravelTime = t - dt,
        maxTravelTime = t + dt;

    int startTravelTime = h * 60 + m;
    int minArrivalTime = (startTravelTime + minTravelTime) % (24 * 60),
        maxArrivalTime = (startTravelTime + maxTravelTime) % (24 * 60);

    std::cout << minArrivalTime / 60 << " " << minArrivalTime % 60 << " "
        << maxArrivalTime / 60 << " " << maxArrivalTime % 60 << std::endl;

    return 0;
}