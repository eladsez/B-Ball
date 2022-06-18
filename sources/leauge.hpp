#ifndef B_BALL_LEAUGE_HPP
#define B_BALL_LEAUGE_HPP

#include <vector>
#include "team.hpp"

namespace BBall {

    class League {
    private:
        std::vector<Team *> teams;

        static bool compare_for_display(Team *team1, Team *team2);


    public:
        League();

        League(std::vector<Team *> teams);

        std::vector<Team *> get_teams();

        void display_table();

        ~League();

        class Stats {

        };
    };

}


#endif //B_BALL_LEAUGE_HPP
