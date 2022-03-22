#include <string.h>
#include <stdio.h>
int main(){
  int arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
  int p = sizeof(arr) / sizeof(int) - 1;
  int k = arr[p];
  for (int j = p; j >=1; j--){
    arr[j] = arr[j-1];
  }
  arr[0] = k;
  printf("%d\n", p);
  printf("%d\n", k);
  for (int j = p; j >=1; j--){
    printf("%d\n", arr[j]);
  }
}
