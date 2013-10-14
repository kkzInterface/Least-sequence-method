#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <fstream>
#include <istream>
#include <sstream>

#define DATA_SOURCE "./test-data"
#define NUMBER_OF_UNKNOWN 2 // 解の個数（2だと y=ax+b におけるaとb）
#define DELIMITER " "

class Least_sequence {
 private:
  int n; // データの個数
  int stringToInt(std::string string);
  double stringToDouble(std::string string);
    
 public:
  int readFile(std::vector< double > &x, std::vector< double > &y);
  int run(std::vector< double > &x, std::vector< double > &y); // 結果を1次式として求める
    
  Least_sequence() // 初期化
    {
      n = 0;
    };
};

template<class DATA_TYPE> std::vector<std::string> splitString(std::string orgString, DATA_TYPE delimiter)
{
  std::vector<std::string> divideStringArray;
    
  long long int iFind = 0; // デリミタが見つかった位置が格納される
  for (long long int iCount = 0; iCount <= orgString.length(); iCount = iFind + 1) {
    iFind = orgString.find_first_of(delimiter, iCount);
    if (iFind == std::string::npos) {
      iFind = orgString.length();
    }
    divideStringArray.push_back(orgString.substr(iCount, iFind - iCount));
  }
    
  return divideStringArray;
}
