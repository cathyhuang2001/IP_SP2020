//jhuan146
//Jingyu Huang

#include <stdio.h>
// Ask user to input mathematical calculation and return the output.
int main(){
  // Prompt user for input.
  printf("Please enter an arithmetic expression using * and / only:\n");
  float num1;
  // Scan the first float input and check if it is valid.
  int check =  scanf("%f", &num1);
  if(check == EOF){
    printf("malformed expression\n");
    return 1;
  }
  float result = num1;
  char operand;
  float num2;
  // Check if a character and a float are scanned together.
  check = scanf(" %c %f", &operand, &num2);
  // Execute until user press Ctrl-d.
  while(check == 2){
    // If input valid, perform the calculation.
    if(operand == '*'){
      result *= num2;
    }
    // If divided by zero, print error message.
    else if(operand == '/'){
      if(num2 == 0){
        printf("division by zero\n");
        return 2;
      }else{
        result /= num2;
      }
    }
    // If input invalid, print error message.
    else{
      printf("malformed expression\n");
      return 1;
    }
    check = scanf(" %c %f", &operand, &num2);
  }
  // If no float is inputed after a character, print error message.
  if(check ==1){
    printf("malformed expression\n");
    return 1;
  }
  // Print result.
  printf("%.6f\n", result);
  return 0;
}
