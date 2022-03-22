#include <stdio.h>
int main(){
  printf("Please enter an arithmetic expression using * and / only:\n");
  float value1;
  char operand;
  float result = value1;
  scanf("%f%c", &value1, &operand);
  while(operand == ' ' || operand == '\n'){
    scanf("%c", &operand);
  }
  float operand2;
  scanf("%f%c", &value1, &operand2);
  while(operand2!=EOF){
    while(operand2 == ' ' || operand2 == '\n'){
      scanf("%c", &operand2);
    }
    operand = operand2;
    printf("%c", operand);
    if(operand == '*'){
      result *= value1;
    }
    else if(operand == '/'){
      if(value1 != 0){
	result /= value1;
      }else{
	printf("division by zero");
	return 2;
      }
    }
    else{
      printf("malformed expression");
      return 1;
    }
    scanf("%f%c", &value1, &operand2);
  }
  if(value1 == EOF){
    printf("malformed expression");
    return 1;
  }else{
    if(operand == '*'){
      result *= value1;
    }
    else if(operand == '/'){
      if(value1 != 0){
        result /= value1;
      }else{
        printf("division by zero");
        return 2;
      }
    }
    else{
      printf("malformed expression");
      return 1;
    }
  }
  printf("%.6f", result);  
  return 0;
}
