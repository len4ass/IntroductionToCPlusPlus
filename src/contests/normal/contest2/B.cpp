#include <iostream>
#include <vector>
#include <cmath>

struct Point {
  int x;
  int y;

public:
  Point(int first, int second) {
    x = first;
    y = second;
  }
};

bool point_sort(Point first, Point second) {
  double d1 = sqrt(first.x * first.x + first.y * first.y);
  double d2 = sqrt(second.x * second.x + second.y * second.y);
  if (d1 < d2) {
    return true;
  }

  return false;
}

int main() {
  int n;
  std::cin >> n;

  std::vector<Point> points;
  for (int i = 0; i < n; ++i) {
    int x, y;
    std::cin >> x >> y;
    Point point = Point(x, y);

    points.push_back(point);
  }

  std::sort(points.begin(), points.end(), &point_sort);
  for (const auto point : points) {
    std::cout << point.x << " " << point.y << std::endl;
  }

  return 0;
}