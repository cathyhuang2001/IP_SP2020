//Brhea D'Mello
//bdmello2
//Jingyu Huang
//jhuan146
//Wilson Tjoeng
//wtjoeng1

#ifndef BASICGAMERULES_H
#define BASICGAMERULES_H

#include "gamerules.h"
#include "position.h"

class BasicGameRules : public GameRules {
private:
  // copy constructor and assignment operator are disallowed
  BasicGameRules(const BasicGameRules &);
  BasicGameRules &operator=(const BasicGameRules &);

public:
  BasicGameRules();
  virtual ~BasicGameRules();

  virtual bool allowMove(Game *game, Entity *actor, const Position &source, const Position &dest) const;
  virtual void enactMove(Game *game, Entity *actor, const Position &dest) const;
  virtual GameResult checkGameResult(Game *game) const;

private:
  // add your own private member functions...
  virtual Direction getPushDirection(Entity *actor, Entity *obj) const;
  virtual Position getPushPosition(Game *game, Direction dir, Entity *obj) const;
  virtual bool checkObjCanBePushed(Game *game, Entity *actor, const Position &source, const Position &dest) const;
};

#endif // BASICGAMERULES_H
