#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int main(void){
  int array[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
  **array = 20;
  int *p = array[1];
  *(p+1) = 30;
  *(p+5) = 40;
  p += 3;
  p[2] *= 10;
  *(p-(*p-1)) *= 100;
  for (int i = 0; i<3; i++){
    for (int j = 0; j < 4; j++){
      printf("%d", array[i][j]);
    }
    printf("\n");
  }
  return 0;
}
