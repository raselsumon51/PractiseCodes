#include <iostream>
using namespace std;

int price[]= {0, 1, 5, 8, 9, 10, 17, 17, 20};
int max_price[sizeof(price)/sizeof(price[0])];

int rod_cutting(int l){
    if(l==0)
      return 0;

    
    if(max_price[l] != 0)
      return max_price[l];

    
    int max_value = INT32_MIN;

    for(int i=1; i<=l; i++){
      max_value = max(max_value, rod_cutting(l-i)+ price[i]);
    }

    max_price[l] = max_value;

    return max_price[l];
}

int main() {
  int length = 7;
  cout << "Max Revenue: " << rod_cutting(length);
  return 0;
}