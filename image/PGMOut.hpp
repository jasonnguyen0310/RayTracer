/*
PGMOut.hpp
Author: Jason Nguyen
May 2, 2021
*/

#include <vector>
using namespace std;
class PGMOut
{
    public:
        PGMOut();

        // Prints out the PGM picture to standard out
        void save(vector<vector<int>> image);
};