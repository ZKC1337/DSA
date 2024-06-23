// Insertion_Sort.cc: Implementation of the Insertion Sort Algorithm using Modern C++
#include <print>
#include <array>
#include <cstdint>

template<typename T, size_t N>
void Insertion_Sort(std::array<T, N>& myArray){

  for(int key = 1; key < myArray.size(); ++key){
    int preKey = key - 1;

    while(preKey >= 0 && myArray.at(preKey) > myArray.at(preKey + 1)){
      myArray.at(preKey)   ^= myArray.at(preKey+1);
      myArray.at(preKey+1) ^= myArray.at(preKey);
      myArray.at(preKey)   ^= myArray.at(preKey+1);
      preKey -= 1;
    }
  }
}

template<typename T, size_t N>
void print_array(const std::array<T, N>& myArray){
  std::print("[");
  for(const T& indx: myArray){
    if(indx != myArray.at(myArray.size()-1))
      std::print("{:d}, ", indx);
    else
      std::print("{:d}]\n", indx);
  }
}

int main(){

  // Define std::array to be sorted
  constexpr uint8_t myArraySize = 6;
  std::array<int, myArraySize> myArray{6,2,8,1,19,3};

  // Print Array Pre-Insertion_Sort
  std::print("Pre-Insertion_Sort: ");
  print_array(myArray);

  // Perform Insertion Sort
  Insertion_Sort(myArray);

  // Print Array Post-Insertion_Sort
  std::print("Post-Insertion_Sort: ");
  print_array(myArray);

  return 0;
}
