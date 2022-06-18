#ifndef B_BALL_TEAM_HPP
#define B_BALL_TEAM_HPP

#include <string>
#include <vector>

using std::string;
using std::ostream;
typedef std::vector <string> vector;

namespace BBall {

    class Team {

    private:
        static vector random_teams;
        string name;
        float talent_level;
        unsigned int wins;
        unsigned int loses;
        unsigned int won_points;
        unsigned int lose_points;
        unsigned int best_wins_seq;
        unsigned int best_loses_seq;
        unsigned int wins_seq; // the current wins seq
        unsigned int loses_seq; // the current lose seq

    public:
        Team();

        Team(string name, float level = 0.0);

        string get_name();

        float get_talent_level();

        unsigned int get_wins_seq();

        unsigned int get_loses_seq();

        unsigned int get_best_wins_seq();

        unsigned int get_best_loses_seq();

        unsigned int get_lose_points();

        unsigned int get_won_points();

        unsigned int get_wins();

        unsigned int get_loses();

        void set_name(string new_name);

        void set_talent_level(float level);

        void set_wins_seq(unsigned int wins_seq);

        void set_loses_seq(unsigned int loses_seq);

        void set_best_wins_seq(unsigned int best_wins_seq);

        void set_best_loses_seq(unsigned int best_loses_seq);

        void set_lose_points(unsigned int lose_points);

        void set_won_points(unsigned int won_points);

        void set_wins(unsigned int wins);

        void set_loses(unsigned int loses);

        bool operator<(const Team &other); // for the set in league class
        ~Team();

        friend ostream &operator<<(ostream &out, const Team &team);
    };

}


#endif //B_BALL_TEAM_HPP
