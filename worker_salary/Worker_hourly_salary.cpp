//
//  Worker_hourly_salary.cpp
//  worker_salary
//
//  Created by Osadchy Dima on 3/4/15.
//  Copyright (c) 2015 Osadchy Dima. All rights reserved.
//

#include "Worker_hourly_salary.h"

Worker_hourly_salary::Worker_hourly_salary(const std::string& name, const std::string& position, const double& hourly_rate): Worker(name, position), hourly_rate(hourly_rate){
    
    salary =  hourly_rate * WORK_HOURS * MONTH_WORKING_DAYS;
}


void Worker_hourly_salary::print(std::ostream& os)const{
    
    os << Signature_hours << ","
    << name << ","
    << position << ","
    << hourly_rate << ","
    << salary
    <<  std::endl;
}

double Worker_hourly_salary::getSalary() const{
    return salary;
}

//
bool Worker_hourly_salary::match(const std::string& signature){
    return signature.find(Signature_hours) == 0;
}

//create new object Worker_hourly_salary
Worker_ptr Worker_hourly_salary::create(const std::vector<std::string>& worker){
    return Worker_ptr(new Worker_hourly_salary(worker[1], worker[2], convertToDouble(worker[3])));
}