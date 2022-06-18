#include "team.hpp"
#include <iomanip>
#include <random>

namespace BBall {

    vector Team::random_teams{"Boston Celtics", "Brooklyn Nets", "New York Knicks", "Philadelphia 76ers",
                              "Toronto Raptors", "Chicago Bulls", "Cleveland Cavaliers", "Detroit Pistons",
                              "Indiana Pacers", "Milwaukee Bucks", "Los Angeles Lakers", "Phoenix Suns",
                              "Memphis Grizzlies", "New Orleans Pelicans", "San Antonio Spurs",
                              "Denver Nuggets", "Sacramento Kings", "Portland Trail Blazers", "Miami Heat",
                              "Washington Wizards"};

    Team::Team() { // for a random team
        std::random_device rd; // obtain a random number from hardware
        std::mt19937 gen(rd()); // seed the generator
        std::uniform_int_distribution<> dist_name(0, 19); // define the range
        *this = Team(random_teams[(size_t) dist_name(gen)], rand()/(float)RAND_MAX);
    }

    Team::Team(string name, float level) : name(name), talent_level(level), best_loses_seq(0), best_wins_seq(0),
                                           loses(0), wins(0), won_points(0), lose_points(0), loses_seq(0),
                                           wins_seq(0) {}

    string Team::get_name() { return name; }

    float Team::get_talent_level() { return talent_level; }

    unsigned int Team::get_wins_seq() { return wins_seq; }

    unsigned int Team::get_loses_seq() { return loses_seq; }

    unsigned int Team::get_best_wins_seq() { return best_wins_seq; }

    unsigned int Team::get_best_loses_seq() { return best_loses_seq; }

    unsigned int Team::get_lose_points() { return lose_points; }

    unsigned int Team::get_won_points() { return won_points; }

    unsigned int Team::get_wins() { return wins; }

    unsigned int Team::get_loses() { return loses; }

    void Team::set_name(string new_name) { name = new_name; }

    void Team::set_talent_level(float level) { talent_level = level; }

    void Team::set_wins_seq(unsigned int wins_seq) { this->wins_seq = wins_seq; }

    void Team::set_loses_seq(unsigned int loses_seq) { this->loses_seq = loses_seq; }

    void Team::set_best_wins_seq(unsigned int best_wins_seq) { this->best_wins_seq = best_wins_seq; }

    void Team::set_best_loses_seq(unsigned int best_loses_seq) { this->best_loses_seq = best_loses_seq; }

    void Team::set_lose_points(unsigned int lose_points) { this->lose_points = lose_points; }

    void Team::set_won_points(unsigned int won_points) { this->won_points = won_points; }

    void Team::set_wins(unsigned int wins) { this->wins = wins; }

    void Team::set_loses(unsigned int loses) { this->loses = loses; }

    bool Team::operator<(const Team &other) {
        return talent_level < other.talent_level;
    }

    Team::~Team() {}

    ostream &operator<<(ostream &out, const Team &team) {
        out << string("Team: ") << team.name << string(", Level: ") << std::fixed << team.talent_level;
        return out;
    }
}
