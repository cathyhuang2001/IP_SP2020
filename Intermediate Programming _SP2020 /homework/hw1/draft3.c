#include<stdio.h>
int main(){
  printf("Please enter an arithmetic expression using * and / only:\n");  
  float num1;
  scanf("%f", &num1);
  if(num1 == EOF){
    printf("malformed expression");
    return 1;
  }
  float result = num1;
  char operand;
  float num2;
  int check = scanf(" %c %f", &operand, &num2);
  while(check == 2){
    if(operand == '*'){
      result *= num2;
    }
    else if(operand == '/'){
      if(num2 == 0){
        printf("division by zero");
        return 2;
      }else{
        result /= num2;
      }
    }
    else{
      printf("malformed expression");
      return 1;
    }
    check = scanf(" %c %f", &operand, &num2);
  }
  if(check ==1){
    printf("malformed expression");
    return 1;
  }
  printf("%.6f\n", result);
  return 0;
}
      
      
    
    
