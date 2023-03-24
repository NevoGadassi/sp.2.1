#include "doctest.h"
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;

 namespace ariel{
   
TEST_CASE("base"){
     // Create two players with their names 
   Player p1("Alice");
   Player p2("Bob");
   //cant build game with the same player
   CHECK_THROWS( (Game(p1,p1)));
  Game game(p1,p2); 
  //check that 2 player taken cards is 0
  CHECK(p1.cardesTaken()==0);
  CHECK(p2.cardesTaken()==0);
  //check that 2 player take 26 cards
  CHECK(p2.stacksize()==26);
  CHECK(p1.stacksize()==26);
  //cant print last and log of turn becuase the gams is not start
  CHECK_THROWS(game.printLastTurn());
  CHECK_THROWS(game.printLog());
  // we until dont have winer
  CHECK_THROWS(game.printWiner());
  int wasstack=p1.stacksize();
  game.playTurn();
  //check that after first turn player1 throw until 1 cards
  CHECK(26>p1.stacksize());
  //check that after first turn player win or stay with 0 card taken
  CHECK(p1.cardesTaken()>=0);
  //check that after first turn someone win the round and take the cards
  CHECK(((p2.cardesTaken() >p1.cardesTaken() )||( p2.cardesTaken()>p1.cardesTaken())));
}
TEST_CASE("5 turns"){
     // Create two players with their names 
   Player p1("Alice");
   Player p2("Bob");

   Game game(p1,p2); 
  for (int i=0;i<5;i++) {
      game.playTurn();
   }  
   //there is no chance that we have winer after 5 turns
  CHECK_THROWS(game.printWiner());
  //check that all player throw card in each turn
  CHECK(p2.stacksize()<22);
  CHECK(p1.stacksize()<22);
  int allcards=p1.cardesTaken()+p2.cardesTaken()+p2.stacksize()+p1.stacksize();
  //check that we still have 52 cards in the game after 5 turns
  CHECK(allcards==52);
  game.playAll();
  //we cant play again after game finish
  CHECK_THROWS(game.playTurn());
  CHECK_THROWS(game.playAll());
  //check that someone lose with 0 card in the stack and in the cardestaken
  CHECK(((p2.stacksize() ==0 )||( p1.stacksize()==0)));
  CHECK(((p2.cardesTaken()==0 )||( p1.cardesTaken()==0)));
  //check that someone win and all the 52 cards belong to him
  CHECK(((p2.stacksize() +p2.cardesTaken() ==52 )||( p1.stacksize() +p2.cardesTaken()==52)));


}
}