//Jingyu Huang
//jhuan146

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "dnasearch.h"
// Return value is the first offset *greater than or equal to* start_at                                                                                            
// where pattern occurs in text.  Returns -1 if there is no such match                                                                                             
int pattern_match(const char t[], int tlen, const char p[], int plen, int start_at){
  if (plen > tlen){
    return -1;
  }
  int i = start_at;
  int j = 0;
  int position = i;
  for (i = start_at; i <= tlen - plen; i++){
    position = i;
    if(t[i] == p[0]){
      for(j = 0; j < plen; j++){
        int pos = i;
        if(p[j] == t[pos]){
          pos = pos + 1;
        }
        else{
          break;
        }
      }
      if(j == plen - 1){
        return position;
      }
    }
  }
  return -1;
}

int main(){
  //Read a file and store in a string                                                                                                                               
  char* fname;
  scanf("%s", fname);
  FILE *text;
  text = fopen("fname", "r");
  if (text == NULL) {
    printf("Error: could not open input file\n");
    return -1;
  }
  char t[15000];
  int i = 0;
  fscanf(text, " %c ", &t[i]);
  while(!feof(text)){
    if ((t[i] == 'A')||(t[i] == 'a')||(t[i] == 'C')||(t[i] == 'c')||(t[i] == 'G')||(t[i] == 'g')||(t[i] == 'T')||(t[i] == 't')){
      i = i + 1;
      fscanf(text, " %c ", &t[i]);
    }
    else{
      printf("Invalid pattern\n");
      return -1;
    }
  }
  fclose(text);
  //Search for the target patterns in text string
  char p[30];
  while(scanf("%s", p) != EOF){
    int start_at = 0;
    int position = pattern_match(t, strlen(t), p, strlen(p), start_at);
    printf("%s ", p);
    if (position == -1){
      printf("Not found\n");
      scanf("%s", p);
    }else{
      while(position != -1){
        printf("%d ", position);
        start_at = position + 1;
        position = pattern_match(t, strlen(t), p, strlen(p), start_at);
      }
      printf("\n");
      scanf("%s", p);
    }
  }
}
  
