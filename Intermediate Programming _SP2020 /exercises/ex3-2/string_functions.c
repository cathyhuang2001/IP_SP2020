/*
    Returns in the third argument the concatenation of the first
    argument and the second argument, provided that there is
    sufficient space in third argument, as specified by the fourth.
    e.g.
        concat("alpha", "beta", result, 10) puts "alphabeta" into result and returns 0
        concat("alpha", "gamma", result, 10) puts nothing into result and returns 1
*/
int concat(const char word1[], const char word2[], char result[], int result_capacity){

   //TODO: replace the following stub with a correct function body so that 
   //      this function behaves as indicated in the comment above
   //
   //NOTE: you may not use the strcat or strcpy library functions in your solution!
  if(result_capacity < strlen(word1) + strlen(word2)){
    return 1;
  }
  int n = 0;
  for(int i = 0; i < result_capacity; i++){
    if(i < strlen(word1)){
      result[i] = word1[i];
    }else{
      result[i] = word2[n];
      n = n + 1;
    }
  }
  return 0;
}
