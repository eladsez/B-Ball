#include "sources/game.hpp"

using namespace BBall;

int main(){

    Team team1 = Team();
    Team team2 = Team();
    Game game1(team1, team2);

    cout << game1 << endl;

    cout << game1.get_winner() << endl;

    auto teams = game1.get_teams();
    cout << *teams["home"] << endl;
    cout << *teams["away"] << endl;
}