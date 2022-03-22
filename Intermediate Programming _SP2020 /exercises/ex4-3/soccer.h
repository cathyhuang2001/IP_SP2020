#ifndef SOCCER_H
#define SOCCER_H

#include <stdbool.h>

//TODO 1: DEFINE DATE, STAT AND PLAYER STRUCTS HERE
struct Stat {
  int num_of_goals;
  int num_of_assists;
  float pass_accuracy;
  int min_played;
  int num_of_shots;
  float shot_accuracy;
};
struct Date {
  int day;
  int month;
  int year;
};
struct Player {
  int age;
  int jersey_number;
  bool goalkeeper;
  Date * date  // pointer to a Date struct defined on the heap
  Stat * stat   // pointer to a Stat struct defined on the heap
}
  
void create_player (Player *p, bool goalie);
void create_team(Player team[], int size);
void print_team (Player team[], int size);

#endif
