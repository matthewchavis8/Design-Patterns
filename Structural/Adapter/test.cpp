#include <iostream>
#include <vector>

// void print(std::vector<int>& arr) {
//   for (int i{}; i < arr.size(); ++i)
//     std::cout << arr[i] << '\n';
//   std::cout << '\n';
// }
//

int main (int argc, char *argv[]) {

  std::vector<int> arr(10, 0);
  
  auto print = [&](std::vector<int>& arr) -> void {
    for (int& num : arr)
      std::cout << num << " ";
    std::cout << '\n';
  };
  print(arr); 
  return 0;
}
