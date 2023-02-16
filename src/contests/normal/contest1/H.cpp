#include <iostream>

int main() {
  int N, K, M;
  std::cin >> N >> K >> M;
  if (K < M) {
    std::cout << 0 << std::endl;
    return 0;
  }
  int detail_count = N / K;
  int material_left = N % K;
  int result_detail_count = (K / M) * detail_count;
  int result_material_left = (K % M) * detail_count;
  int left_sum = material_left + result_material_left;
  while (true) {
    int all_material = left_sum;
    int det_count = all_material / K;
    material_left = all_material % K;
    result_detail_count += (K / M) * det_count;
    result_material_left = (K % M) * det_count;
    left_sum = material_left + result_material_left;
    if (left_sum / K < 1) {
      break;
    }
  }
  std::cout << result_detail_count << std::endl;
  return 0;
}