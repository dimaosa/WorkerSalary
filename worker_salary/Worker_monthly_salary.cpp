//
//  Worker_monthly_salary.cpp
//  worker_salary
//
//  Created by Osadchy Dima on 3/4/15.
//  Copyright (c) 2015 Osadchy Dima. All rights reserved.
//

#include "Worker_monthly_salary.h"

Worker_monthly_salary::Worker_monthly_salary(const std::string& name, const std::string& position, const double& salary): Worker(name, position), salary(salary){}
void Worker_monthly_salary::print(std::ostream& os)const{
    
    os << "Monthly salary"<< ","
    << name << ","
    << position << ","
    << salary
    <<  std::endl;
}

double Worker_monthly_salary::getSalary() const{
    return salary;
}
bool Worker_monthly_salary::match(const std::string& signature){
    return signature.find("Monthly") == 0;
}

Worker_ptr Worker_monthly_salary::create(const std::vector<std::string>& worker){
    return Worker_ptr(new Worker_monthly_salary(worker[1], worker[2], convertToDouble(worker[3])));
}