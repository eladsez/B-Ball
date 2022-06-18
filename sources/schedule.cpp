#include "schedule.hpp"

using std::cout;
using std::endl;

namespace BBall{

    int Schedule::GAMES_PER_SEASON = 38;

    Schedule::Schedule(League &league) {

        std::vector<size_t> rotate_indexes = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
        std::vector<Team *> teams = league.get_teams();

        while (this->season.size() < GAMES_PER_SEASON) {
            std::vector<Game*> rotation(10);
            for (size_t home = 0, away = 19; home < away ; --home, --away) {
                rotation.push_back(new Game(*(teams[rotate_indexes[home]]), *(teams[rotate_indexes[away]])));
            }
            this->season.push_back(rotation);

            std::rotate(rotate_indexes.begin(), rotate_indexes.begin() + 1, rotate_indexes.end());
        }
    }

    Schedule::~Schedule(){
        for (std::vector<Game *> rotation : season){
            for (Game * game: rotation){
                delete game;
            }
        }
    }
}
