#ifndef B_BALL_SCHEDULE_HPP
#define B_BALL_SCHEDULE_HPP
#include "team.hpp"
#include "game.hpp"
#include "leauge.hpp"
#include <vector>
#include <algorithm>

namespace BBall {


    class Schedule {

    private:
        static int GAMES_PER_SEASON;
        std::vector<std::vector<Game *>> season;


    public:

        Schedule(League &league);

        ~Schedule();
    };

}
#endif //B_BALL_SCHEDULE_HPP
