#include <iostream>
#include <cstring>
using namespace std;
int main() {
  char A[20], B[20];
  int word[27] = {0};
  cin >> A >> B;
  if (strlen(A) != strlen(B)) 
    cout << "No!";
  else
  {
    for (int i=0; i<strlen(A); i++) {
      word[A[i]-97]++;
      word[B[i]-97]--;  
    }
    for (int i=0; i<26; i++) {
      if (word[i] != 0) {
        word[27] = 1;
      }
    }
    if (word[27] == 1)
      cout << "No!";
    else 
      cout << "Yes!";  
  }
  return 0;
}