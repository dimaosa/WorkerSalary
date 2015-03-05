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

class Worker_hourly_salary : public Worker{
public:
    
    Worker_hourly_salary(const std::string&, const std::string&, const double&);
    
    void print(std::ostream&)const;
    
    double getSalary() const;
    
    void salaryUpdate();
    
private:
    double hourly_rate;
    double salary;
};
#endif /* defined(__worker_salary__Worker_hourly_salary__) */
