//
//  Worker_hourly_salary.cpp
//  worker_salary
//
//  Created by Osadchy Dima on 3/4/15.
//  Copyright (c) 2015 Osadchy Dima. All rights reserved.
//

#include "Worker_hourly_salary.h"

Worker_hourly_salary::Worker_hourly_salary(const std::string& name, const std::string& position, const double& hourly_rate): Worker(name, position), hourly_rate(hourly_rate){
    
    Worker_hourly_salary::salaryUpdate();
}

void Worker_hourly_salary::print(std::ostream& os)const{
    
    os << "Hourly salary" << "," << Worker::name << ","
    << Worker::position << "," << Worker_hourly_salary::hourly_rate
    << "," << salary <<  std::endl;
}

double Worker_hourly_salary::getSalary() const{
    return salary;
}
void Worker_hourly_salary::salaryUpdate(){
    Worker_hourly_salary::salary = 20.8 * 8 * Worker_hourly_salary::hourly_rate;
}