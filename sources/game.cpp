#include "game.hpp"

namespace BBall {

    Game::Game(Team home, Team away) : home(home), away(away), score_away(0), score_home(0) {}

    std::map<string, Team *> Game::get_teams() {
        std::map < string, Team * > teams;
        teams.insert({string("home"), &home});
        teams.insert({string("away"), &away});
        return teams;
    }

    std::pair<unsigned int, unsigned int> Game::get_score() {
        return {score_home, score_away};
    }

    string Game::get_winner() {
        return home.get_name(); // TODO: change to logic
    }

    Game::~Game() {}

    ostream &operator<<(ostream &out, const Game &game) {
        out << "Game\nHome " << game.home << ", Score:" << game.score_home << endl;
        out << "Away " << game.away << ", Score:" << game.score_away << endl;
        return out;
    }
}
