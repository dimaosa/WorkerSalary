//
//  Worker_hourly_salary.h
//  worker_salary
//
//  Created by Osadchy Dima on 3/4/15.
//  Copyright (c) 2015 Osadchy Dima. All rights reserved.
//

#ifndef __worker_salary__Worker_hourly_salary__
#define __worker_salary__Worker_hourly_salary__

#include "Worker.h"
#include <vector>
#include "helper_functions.h"

const double MONTH_WORKING_DAYS = 20.8;
const int WORK_HOURS = 8;


class Worker_hourly_salary : public Worker{
public:
    
    Worker_hourly_salary(const std::string&, const std::string&, const double&);
    
    double getSalary() const;
    
    void print(std::ostream&)const;
    
    static bool match(const std::string& signature);
    
    static Worker_ptr create(const std::vector<std::string>& worker);
    
private:
    double hourly_rate;
    double salary;
};
#endif /* defined(__worker_salary__Worker_hourly_salary__) */
