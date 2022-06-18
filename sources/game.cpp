#include "game.hpp"
#include <iomanip>

using std::max;
using std::min;

namespace BBall {

    random_device Game::rd;
    mt19937 Game::gen = mt19937(Game::rd());

    void Game::home_win() {
        home->set_wins(home->get_wins() + 1);
        away->set_loses(away->get_loses() + 1);
        home->set_loses_seq(0);
        home->set_wins_seq(home->get_wins_seq() + 1);
        away->set_wins_seq(0);
        away->set_loses_seq(away->get_loses_seq() + 1);

        if (away->get_loses_seq() > away->get_best_loses_seq()) {
            away->set_best_loses_seq(away->get_loses_seq());
        }
        if (home->get_wins_seq() > home->get_best_wins_seq()) {
            home->set_best_wins_seq(home->get_best_wins_seq());
        }
    }

    void Game::away_win() {
        away->set_wins(away->get_wins() + 1);
        home->set_loses(home->get_loses() + 1);

        away->set_loses_seq(0);
        away->set_wins_seq(away->get_wins_seq() + 1);
        home->set_wins_seq(0);
        home->set_loses_seq(home->get_loses_seq() + 1);

        if (home->get_loses_seq() > home->get_best_loses_seq()) {
            home->set_best_loses_seq(home->get_loses_seq());
        }
        if (away->get_wins_seq() > away->get_best_wins_seq()) {
            away->set_best_wins_seq(away->get_best_wins_seq());
        }
    }

    void Game::update_teams() {
        home->set_lose_points(home->get_lose_points() + score_away);
        home->set_won_points(home->get_won_points() + score_home);
        away->set_lose_points(away->get_lose_points() + score_home);
        away->set_won_points(away->get_won_points() + score_away);
        if (score_home > score_away) {
            home_win();
        } else if (score_home < score_away) {
            away_win();
        } else if (home->get_talent_level() > away->get_talent_level()) {
            home_win();
        } else {
            away_win();
        }
    }


    Game::Game(Team &home, Team &away) : home(&home), away(&away), score_away(0), score_home(0) {

        std::normal_distribution<> home_dis((MAX_SCORE + MIN_HOME_SCORE) / 2, 15);
        std::normal_distribution<> away_dis((MAX_SCORE + MIN_AWAY_SCORE) / 2, 15);

        score_home = home_dis(gen);
        score_away = away_dis(gen);

        score_home += home.get_talent_level() * 10;
        score_away += away.get_talent_level() * 10;

        score_home = max(min((unsigned int) MAX_SCORE, score_home),
                         (unsigned int) MIN_HOME_SCORE); // double check for the score interval
        score_away = max(min((unsigned int) MAX_SCORE, score_away),
                         (unsigned int) MIN_AWAY_SCORE); // double check for the score interval

        update_teams();
    }

    std::map<string, Team *> Game::get_teams() { // just to practice in map
        std::map < string, Team * > teams;
        teams.insert({string("home"), home});
        teams.insert({string("away"), away});
        return teams;
    }

    std::pair<unsigned int, unsigned int> Game::get_score() { // just to practice in pair
        return {score_home, score_away};
    }

    string Game::get_winner() {
        if (score_away > score_home) {
            return away->get_name();
        } else if (score_away < score_home) {
            return home->get_name();
        } else {
            return away->get_talent_level() < home->get_talent_level() ? home->get_name() : away->get_name();
        }
    }

    Game::~Game() {}

    ostream &operator<<(ostream &out, const Game &game) {
        cout << std::setprecision(3);
        out << "Game\nHome " << *(game.home) << ", Score:" << game.score_home << endl;
        out << "Away " << *(game.away) << ", Score:" << game.score_away;
        return out;
    }

}

