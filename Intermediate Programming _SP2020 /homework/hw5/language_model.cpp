//Jingyu Huang
//jhuan146

#include <iostream>
#include "language_model.h"
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstring>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::vector;
using std::map;
using std::sort;
using std::pair;
using std::stringstream;

void a(vector<string>trigrams){
  //Map the trigrams and corresponding frequencies
  sort(trigrams.begin(), trigrams.end());
  map<string, int> frequency;
  for(size_t i = 0; i < trigrams.size(); i++){
    string current = trigrams[i];
    frequency[current]++;
  }
  //Print in order
  map<string, int>::iterator it;
  for (it = frequency.begin(); it != frequency.end(); it++){
    cout << it->second << " - [" << it->first << "]" << endl;
  }
}

void d(vector<string>trigrams){
  //Map the trigrams and corresponding frequencies
  sort(trigrams.begin(), trigrams.end(), std::greater<string>());
  map<string, int> frequency;
  for(size_t i = 0; i < trigrams.size(); i++){
    string current = trigrams[i];
    frequency[current]++;
  }
  //Print in reversed order
  map<string, int>::reverse_iterator it;
  for (it = frequency.rbegin(); it != frequency.rend(); ++it){
    cout << it->second << " - [" << it->first << "]" << endl;
  }
}
//Create comparators for sorting
bool compare(const pair<int, string>&one, const pair<int, string>&two){
  if(one.first > two.first){
    return true;
  }
  else if(one.first == two.first){
    if (one.second <= two.second){
      return true;
    }
  }
  return false;
}
void c(vector<string>trigrams){
  //Map the trigrams and corresponding frequencies
  map<string, int> frequency;
  for(size_t i = 0; i < trigrams.size(); i++){
    string current = trigrams[i];
    frequency[current]++;
  }
  //Store the pairs from the map to a vector in descending order
  std::vector<pair<int, string>> store;
  map<string, int>::reverse_iterator it;
  for(it = frequency.rbegin(); it != frequency.rend(); it++){
    std::pair <int, string> element;
    element = make_pair(it->second, it->first);
    store.push_back(element);
  }
  //Sort and print the pairs in vector
  sort(store.begin(), store.end(), &compare);
  for(size_t i = 0; i < store.size(); i++){
    cout << store[i].first << " - [" << store[i].second << "]" << endl;
  }
}

void f(vector<string>trigrams, vector<string>targets){
  //Map the trigrams and corresponding frequencies                                                                                       
  sort(trigrams.begin(), trigrams.end());
  map<string, int> frequency;
  for(size_t i = 0; i < trigrams.size(); i++){
    string current = trigrams[i];
    frequency[current]++;
  }
  map<string, int>::iterator it;
  std::vector<pair<int, string>> store;
  for (it = frequency.begin(); it != frequency.end(); it++){
    string curr = it->first;
    stringstream ss(curr);
    string word;
    ss >> word;
    if (word.compare(targets[0]) == 0){
      ss >> word;
      if (word.compare(targets[1]) == 0){
	//Store the pairs from the map to a vector in descending order
        std::pair <int, string> element;
	element = make_pair(it->second, it->first);
	store.push_back(element);
      }else{
	continue;
      }
    }else{
      continue;
    }
  }
  //Check if the vector is empty
  if(store.empty()){
    cout << "No trigrams of the form [" << targets[0] << " " << targets[1] << " ?] appear" << endl;
  }
  else{
    //Sort and print the pairs in vector
    sort(store.begin(), store.end(), &compare);
    size_t k = 0;
    cout << store[k].first << " - [" << store[k].second << "]" << endl;
  }
}
