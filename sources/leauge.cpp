#include "leauge.hpp"
#include <algorithm>
#include <string>

namespace BBall {


    League::League(std::vector<Team *> teams) : teams(teams) {
        while (this->teams.size() < 20) {
            this->teams.push_back(new Team());
        }
    }

    League::League() {
        while (this->teams.size() < 20) {
            this->teams.push_back(new Team());
        }
    }

    std::vector<Team *> League::get_teams() {
        return teams;
    }

    bool League::compare_for_display(Team *team1, Team *team2) {
        return team1->get_wins() > team2->get_wins();
    }

    void League::display_table() {
        std::sort(teams.begin(), teams.end(), compare_for_display);
        printf("%5s|%25s|%6s|%6s|%10s|%10s\n", "Place", "Team", "Wins", "Loses", "W-Streak", "L-Streak");
        printf("===================================================================\n");
        int i = 0;
        for (Team *team: teams) {
            printf("%5d|%25s|%6d|%6d|%10d|%10d\n", ++i, team->get_name().c_str(), team->get_wins(), team->get_loses(),
                   team->get_best_wins_seq(), team->get_best_loses_seq());
        }

    }

    League::~League() {
        for (Team *team: teams) {
            delete team;
        }
    }
}
