// Binary_Search.cpp: Implementation of the Binary Search Algorithm using Modern C++
#include <print>
#include <array>
#include <cstdint>
#include <optional> 

template<typename T, size_t N>
std::optional<int8_t> binary_search(const std::array<T, N>& sortedArray, const std::int8_t& min, const std::int8_t& max, const std::int8_t& searchTerm){

  // Retrieve Middle of the sortedArray
  std::uint8_t middlePosition = (min + max) / 0x02;

  if(max >= min){
    if(searchTerm > sortedArray.at(middlePosition))
      return binary_search(sortedArray, (middlePosition+0x01), max, searchTerm);
    else if(searchTerm < sortedArray.at(middlePosition))
      return binary_search(sortedArray, min, (middlePosition-0x01), searchTerm);
    else if(searchTerm == sortedArray.at(middlePosition))
      return middlePosition;

  } 

  return {};

}

template<typename T, size_t N>
void print_array(const std::array<T, N>& myArray){
  std::print("sortedArray = [");
  for(const int8_t& indx: myArray){
    if(indx != myArray.at(myArray.size()-0x01))
      std::print("{}, ", indx);
    else
      std::print("{}]", indx);
  }
}

int main(int argc, char* argv[]){

  if(argc != 2){
    std::print("Usage: ./bsearch searchTerm\n");
    return -1;
  }


  constexpr uint8_t arraySize = 10;
  std::array<std::int8_t, arraySize> sortedArray{1,4,7,8,23,29,30,31,45,47};

  print_array(sortedArray);

  std::print("\nSearching for {:}\n", argv[1]);

  std::print("{:} located at Index {:d}\n",
             argv[1],
             binary_search(sortedArray, 0x00, sortedArray.size()-0x01, std::stoi(argv[1])).value_or(-1));

  return 0;
}
