#include "Least_sequence.h"

int Least_sequence::run(std::vector< double > &x, std::vector< double > &y)
{
  if (x.size() != y.size()) {
    std::cout << "Not much vector size." << std::endl;
    return -1;
  }
    
  n = (int)x.size();

  double a, b, p, q;
  double A, B, C, D, E;
  A = B = C = D = E = 0.0;
    
  for (int i=0; i<n; i++) {
    A += y[i] * y[i];
    B += x[i] * x[i];
    C += y[i];
    D += x[i] * y[i];
    E += x[i];
  }
    
  a = (n*D - C*E)/(n*B - E*E);
  b = (B*C - D*E)/(n*B - E*E);
    
  for (int i=0; i<n; i++) {
    printf("%f %f\n", x[i], y[i]);
  }
  printf("\n");
    
  for (p=x[0]-10.0; p<x[n-1]+10.0; p+=0.01) {
    q = a*p + b;
    printf("%f %f\n", p, q);
  }
        
  return 0;
}


int Least_sequence::readFile(std::vector< double > &x, std::vector< double > &y)
{
  std::ifstream ifs(DATA_SOURCE);
  std::string line;
    
  if (!ifs) {
    std::cout << "File not found." << std::endl;
    return -1;
  }
    
  while (getline(ifs, line)) {
    std::vector< std::string > buf = splitString(line, DELIMITER);
    x.push_back(stringToInt(buf[0]));
    y.push_back(stringToDouble(buf[1]));
  }
    
  if (x.size() != y.size()) {
    std::cout << "Not much vector size." << std::endl;
    return -1;
  }
    
  return 0;
}


/**
 [文字の変換 string -> int]
**/
int Least_sequence::stringToInt(std::string string)
{
  std::istringstream stringStream;
  int result;
    
  stringStream.str(string);
  stringStream >> result;
    
  return result;
}


/**
 [文字の変換 string -> double]
**/
double Least_sequence::stringToDouble(std::string string)
{
  std::istringstream stringStream;
  double result;
    
  stringStream.str(string);
  stringStream >> result;
    
  return result;
}


int main()
{
  std::vector< double > x;
  std::vector< double > y;

  Least_sequence least_sequence;
  int ret = least_sequence.readFile(x, y);
  if (ret != 0) {
    return -1;
  }

  ret = least_sequence.run(x, y);
  if (ret != 0) {
    return -1;
  }

  return 0; 
}
