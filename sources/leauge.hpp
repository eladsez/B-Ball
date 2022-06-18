#ifndef B_BALL_LEAUGE_HPP
#define B_BALL_LEAUGE_HPP

#include <set>
#include <map>
#include <vector>
#include "team.hpp"

namespace BBall {

    class League {

    private:
        std::set<Team *> teams;
        std::map<Team *, std::vector<int>> scoresTable;
    };

}


#endif //B_BALL_LEAUGE_HPP
