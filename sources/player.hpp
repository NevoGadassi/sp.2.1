#pragma once
#ifndef PLAYER_HPP
#define PLAYER_HPP


#include <string>
using namespace std;

namespace ariel{
    class Player{
    public:
    Player(string const &name){}
     int static stacksize();
    int static cardesTaken();
    };
}
#endif