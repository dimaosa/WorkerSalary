//
//  Factory.h
//  worker_salary
//
//  Created by Osadchy Dima on 3/4/15.
//  Copyright (c) 2015 Osadchy Dima. All rights reserved.
//

#ifndef __worker_salary__Factory__
#define __worker_salary__Factory__
#include "Worker_group.h"
#include "Worker_hourly_salary.h"
#include "Worker_monthly_salary.h"
#include "helper_functions.h"
#include <vector>
#include <algorithm>
#include <sstream>
#include <ostream>
#include <fstream>
enum WorkerType{
    mouthly=0,
    hourly=1
};


void save2file(const Worker_group&, const std::string&);
void readFromFile(Worker_group&, const std::string&);
void createWorker(Worker_group&, const std::vector<std::string>&);
#endif /* defined(__worker_salary__Factory__) */
