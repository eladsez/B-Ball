#ifndef B_BALL_TEAM_HPP
#define B_BALL_TEAM_HPP

#include <string>

using std::string;
using std::ostream;

namespace BBall {

    class Team {

    private:
        string name;
        float talent_level;
        unsigned short wins;
        unsigned short loses;
        unsigned short won_points;
        unsigned short lose_points;
        unsigned short best_wins_seq;
        unsigned short best_loses_seq;
        unsigned short wins_seq; // the current wins seq
        unsigned short loses_seq; // the current lose seq

    public:
        Team();

        Team(string name, float level = 0.0);

        Team(const Team &other);

        string get_name();

        float get_talent_level();

        unsigned short get_wins_seq();

        unsigned short get_loses_seq();

        unsigned short get_best_wins_seq();

        unsigned short get_best_loses_seq();

        unsigned short get_lose_points();

        unsigned short get_won_points();

        unsigned short get_wins();

        unsigned short get_loses();

        void set_name(string new_name);

        void set_talent_level(float level);

        void set_wins_seq(unsigned short wins_seq);

        void set_loses_seq(unsigned short loses_seq);

        void set_best_wins_seq(unsigned short best_wins_seq);

        void set_best_loses_seq(unsigned short best_loses_seq);

        void set_lose_points(unsigned short lose_points);

        void set_won_points(unsigned short won_points);

        void set_wins(unsigned short wins);

        void set_loses(unsigned short loses);

        bool operator<(const Team &other); // for the set in league class
        ~Team();

        friend ostream &operator<<(ostream &out, const Team &team);
    };

}


#endif //B_BALL_TEAM_HPP
