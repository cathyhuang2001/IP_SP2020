#include <stdio.h>
int main(){
  printf("Please enter an arithmetic expression using * and / only:\n");
  float value1;
  scanf("%f", &value1);
  float result = value1;
  float value2;
  char operand;
  scanf("%c", &operand);
  while(getchar(operand) != EOF){
    while(operand == ' ' || operand == '\n'){
      scanf("%c", &operand);
    }
    scanf("%f", &value2);
    if(value2 == EOF){
      printf("malformed expression\n");
      return 1;
    }
    if(operand == '*'){
      result*=value2;
    }
    else if(operand == '/' && value2 != 0){
      result/=value2;
    }
    else if(operand == '/' && value2 == 0){
      printf("division by zero\n");
      return 2;
    }
    else{
      printf("malformed expression\n");
      return 1;
    }
    scanf("%c", &operand);
  }
  printf("%.6f", result);
  return 0;
}
