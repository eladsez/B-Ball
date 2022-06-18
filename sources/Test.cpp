#include "team.hpp"
#include "leauge.hpp"
#include "schedule.hpp"
#include "../doctest.h"

using namespace BBall;



TEST_CASE("league tests") {
    Team t1;

    CHECK_NOTHROW(t1.get_best_loses_seq());
    CHECK_NOTHROW(t1.get_best_loses_seq());
    CHECK_NOTHROW(t1.get_best_loses_seq());
    CHECK_NOTHROW(t1.get_best_loses_seq());
    CHECK_NOTHROW(t1.get_best_loses_seq());
    CHECK_EQ(t1.get_loses(), 0);
    CHECK_EQ(t1.get_wins(), 0);
    CHECK_EQ(t1.get_wins_seq(), 0);
    CHECK_EQ(t1.get_loses_seq(), 0);
    CHECK_EQ(t1.get_best_wins_seq(), 0);
    CHECK_EQ(t1.get_best_loses_seq(), 0);
    Team t2;
    Team t3;
    Team t4;
    Team t5;

    std::vector<Team *> teams(5);
    teams.push_back(&t1);
    teams.push_back(&t2);
    teams.push_back(&t3);
    teams.push_back(&t4);
    teams.push_back(&t5);

    League l1;
    CHECK_NOTHROW(Schedule s1(l1));
    CHECK_NOTHROW(l1.display_table());
    CHECK_NOTHROW(l1.get_teams());
    CHECK_EQ(l1.get_teams().size(), 20);
}