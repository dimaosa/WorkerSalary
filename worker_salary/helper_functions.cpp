//
//  helper_functions.cpp
//  worker_salary
//
//  Created by Osadchy Dima on 3/4/15.
//  Copyright (c) 2015 Osadchy Dima. All rights reserved.
//

#include "helper_functions.h"

bool compareNames(const std::shared_ptr<Worker> wrkr1, const std::shared_ptr<Worker> wrkr2){
    return wrkr1->name.compare(wrkr2->name) < 0;
}
bool compareSalary(const std::shared_ptr<Worker> wrkr1, const std::shared_ptr<Worker> wrkr2){
    return wrkr1->getSalary() > wrkr2->getSalary();
}

bool compareWorkers (const std::shared_ptr<Worker> wrkr1, const std::shared_ptr<Worker> wrkr2) {
    if(wrkr1->getSalary() == wrkr2->getSalary()){
        return compareNames(wrkr1, wrkr2);
    }
    else{
        return compareSalary(wrkr1, wrkr2);
    }
}


