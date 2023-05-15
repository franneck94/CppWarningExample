#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "BVNS.hpp"
#include "Helper.hpp"
#include "Matrix.hpp"

using namespace std;

int main(int argc, char **argv)
{
    unsigned int kMin = 1, kMax = 0, tMax = 0, shaking_mode = 0,
                 update_neighborhood_mode = 0, local_search_mode = 0,
                 update_xij_mode = 0, stopping_critera = 0, init_mode = 0,
                 rMax = 0, time = 0, rMax_mode = 0;

    vector<double> vals(10, 0.0);
    vector<double> vals_init(10, 0.0);

    string test_set_directory =
        "C:/Users/Jan/Documents/_LocalCoding/_CppWarningExample/data";

    vector<string> sets = {"14"};

    for (auto set : sets)
    {
        cout << "Open Testset: cap" << set << endl;

        local_search_mode = 1;
        shaking_mode = 0;
        update_xij_mode = 1;
        init_mode = 1;
        time = 3000;
        tMax = 40;
        kMax = 3;

        BVNS bvns = BVNS(test_set_directory + set,
                         kMin,
                         kMax,
                         tMax,
                         shaking_mode,
                         local_search_mode,
                         update_xij_mode,
                         init_mode,
                         time);

        cout << endl << "init = " << bvns.getInitialFx() << endl;
    }

    cout << endl << endl << "Finished Computation!" << endl;
    getchar();
    return 0;
}

// Init: RVNS, Local: Best, Xij: Vogel, Time Cap: 30s
/*init_mode = 1;
local_search_mode = 1;
update_xij_mode = 1;
time = 30;
tMax = 40;
kMax = 3;*/
