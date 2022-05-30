#ifndef POLISH_H
#define POLISH_H

#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;

class Polish {

    public:
        Polish();
        Polish(string function);

        void set(string function);
        string convert();
        int calc();
        string pre;
};

#endif

