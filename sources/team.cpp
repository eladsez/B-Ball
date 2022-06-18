#include "team.hpp"
#include <iomanip>

namespace BBall {

    Team::Team() { // for a random team

    }

    Team::Team(string name, float level) : name(name), talent_level(level) {}

    Team::Team(const Team &other) {
        name = other.name;
        talent_level = other.talent_level;
    }

    string Team::get_name() { return name; }

    float Team::get_talent_level() { return talent_level; }

    unsigned short Team::get_wins_seq() { return wins_seq; }

    unsigned short Team::get_loses_seq() { return loses_seq; }

    unsigned short Team::get_best_wins_seq(){ return best_wins_seq;}

    unsigned short Team::get_best_loses_seq(){ return best_loses_seq;}

    unsigned short Team::get_lose_points() { return lose_points; }

    unsigned short Team::get_won_points() { return won_points; }

    unsigned short Team::get_wins() { return wins; }

    unsigned short Team::get_loses() { return loses; }

    void Team::set_name(string new_name) { name = new_name; }

    void Team::set_talent_level(float level) { talent_level = level; }

    void Team::set_wins_seq(unsigned short wins_seq) { this->wins_seq = wins_seq; }

    void Team::set_loses_seq(unsigned short loses_seq) { this->loses_seq = loses_seq; }

    void Team::set_best_wins_seq(unsigned short best_wins_seq){ this->best_wins_seq = best_wins_seq;}

    void Team::set_best_loses_seq(unsigned short best_loses_seq){ this->best_loses_seq = best_loses_seq;}

    void Team::set_lose_points(unsigned short lose_points) { this->lose_points = lose_points; }

    void Team::set_won_points(unsigned short won_points) { this->won_points = won_points; }

    void Team::set_wins(unsigned short wins) { this->wins = wins; }

    void Team::set_loses(unsigned short loses) { this->loses = loses; }

    bool Team::operator<(const Team &other) {
        return talent_level < other.talent_level;
    }

    Team::~Team() {}

    ostream &operator<<(ostream &out, const Team &team) {
        out << string("Team: ") << team.name << string(", Level: ") << std::fixed << team.talent_level;
        return out;
    }
}
