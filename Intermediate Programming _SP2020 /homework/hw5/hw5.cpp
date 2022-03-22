//Jingyu Huang
//jhuan146
#include <fstream>
#include <iostream>
#include "language_model.h"
#include <cassert>
#include <sstream>
#include <vector>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::vector;
using std::stringstream;

int main(int argc, const char* argv[]){
  //Check if there is at least input for filelist
  if (argc < 2){
    cerr << "Invalid file list: " << endl;
    return 1;
  }
  //Read from input file list
  std::ifstream file1(argv[1]);
  if(!file1.is_open()){
    cerr << "Invalid file list: " << argv[1] << endl;
    return 1;
  }
  std::stringstream inputstream;
  inputstream << file1.rdbuf();
  //Read individual files and store words in a vector of strings
  string filename;
  string input;
  vector<string> words;
  bool valid = false;
  while(inputstream >> filename){
    std::ifstream file2(filename);
    if(!file2.is_open()){
      std::cerr << "Invalid file: " << filename << std::endl;
    }
    else{
      std::stringstream sentences;
      words.push_back("<START_1>");
      words.push_back("<START_2>");
      sentences << file2.rdbuf();
      while(sentences >> input){
        words.push_back(input);
      }
      words.push_back("<END_1>");
      words.push_back("<END_2>");
      valid = true;
    }
  }
  //Check if all files cannot be opened
  if(valid == false){
    return 1;
  }
  //Create a vector that store trigrams
  vector<string> trigrams;
  for(size_t i = 0; i < words.size() - 2; i++){
    string trigram;
    trigram = words[i] + " " + words[i+1] + " " + words[i+2];
    trigrams.push_back(trigram);
  }
  //Delete unused trigrams
  for(size_t i = 0; i < trigrams.size(); i++){
    if(trigrams[i].compare("<END_1> <END_2> <START_1>") == 0){
      trigrams.erase(trigrams.begin()+i, trigrams.begin()+i+2);
    }
  }
  //Check for function input and perform function
  if(strcmp(argv[2], "a") == 0){
    a(trigrams);
  }
  else if(strcmp(argv[2], "d") == 0){
    d(trigrams);
  }
  else if(strcmp(argv[2], "c") == 0){
    c(trigrams);
  }
  else if(strcmp(argv[2], "f") == 0){
    vector<string> targets;
    //Check if the number of inputs is correct
    if (argc != 5){
      std::cerr << "Invalid argument list: f requires two additional command-line arguments" << std::endl;
      return 1;
    }
    for(int i = 3; i < 5; i++){
      targets.push_back(argv[i]);
    }
    f(trigrams, targets);
  }
  else{
    std::cerr << "Invalid command: valid options are a, d, c, and f" << std::endl;
    return 1;
  }
  return 0;
}
