#ifndef B_BALL_GAME_HPP
#define B_BALL_GAME_HPP

#include "team.hpp"
#include <iostream>
#include <utility>
#include <map>

using std::ostream;
using std::cout;
using std::endl;

namespace BBall {

    class Game {

    private:
        Team home;
        Team away;
        unsigned int score_away;
        unsigned int score_home;

    public:
        Game(Team home, Team away);

        std::map<string, Team *> get_teams();

        std::pair<unsigned int, unsigned int> get_score();

        string get_winner();

        ~Game();

        friend ostream &operator<<(ostream &out, const Game &game);
    };

}


#endif //B_BALL_GAME_HPP
