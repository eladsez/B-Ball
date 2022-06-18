#include "sources/game.hpp"

using namespace BBall;

int main(){

    Game game1(Team("bla1"), Team("bla2"));

    cout << game1 << endl;

    auto teams = game1.get_teams();
    cout << *teams["home"] << endl;
    cout << *teams["away"] << endl;
}