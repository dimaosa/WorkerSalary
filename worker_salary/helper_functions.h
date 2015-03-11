//
//  helper_functions.h
//  worker_salary
//
//  Created by Osadchy Dima on 3/4/15.
//  Copyright (c) 2015 Osadchy Dima. All rights reserved.
//

#ifndef __worker_salary__helper_functions__
#define __worker_salary__helper_functions__

#include <iostream>
#include "Worker.h"
#include <sstream>
#include <algorithm>

typedef std::shared_ptr<Worker> Worker_ptr;

bool compareNames(const Worker_ptr wrkr1, const Worker_ptr wrkr2);
bool compareSalary(const Worker_ptr wrkr1, const Worker_ptr wrkr2);

bool compareWorkers (const Worker_ptr wrkr1, const Worker_ptr wrkr2);

//if conversation from string to double wrong, show error
class BadConversion : public std::runtime_error {
public:
    BadConversion(const std::string& s)
    : std::runtime_error(s)
    { }
};
inline double convertToDouble(const std::string& s)
{
    std::istringstream i(s);
    double x;
    if (!(i >> x)){
        throw BadConversion("convertToDouble(\"" + s + "\")");
    }
    return x;
}

//define own functor for Worker::print in for_each
template <typename T>
class PrintIt {
    T& os;
    
public:
    explicit PrintIt (T& x): os(x){}
    void operator ()(Worker_ptr wrkr) const {
        wrkr->print(os);
    }
};
#endif /* defined(__worker_salary__helper_functions__) */
