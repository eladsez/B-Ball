#ifndef B_BALL_GAME_HPP
#define B_BALL_GAME_HPP

#include "team.hpp"
#include <iostream>
#include <utility>
#include <map>
#include <random>

#define MAX_SCORE 100
#define MIN_AWAY_SCORE 50
#define MIN_HOME_SCORE 55

using std::ostream;
using std::cout;
using std::endl;
using std::random_device;
using std::mt19937;

namespace BBall {

    class Game {

    private:
        Team *home;
        Team *away;
        unsigned int score_away;
        unsigned int score_home;
        static random_device rd;
        static mt19937 gen;

        void home_win();

        void away_win();

        void update_teams();

    public:
        Game(Team &home, Team &away);

        std::map<string, Team *> get_teams();

        std::pair<unsigned int, unsigned int> get_score();

        string get_winner();

        ~Game();

        friend ostream &operator<<(ostream &out, const Game &game);
    };

}


#endif //B_BALL_GAME_HPP
