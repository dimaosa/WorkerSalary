//
//  Worker_monthly_salary.h
//  worker_salary
//
//  Created by Osadchy Dima on 3/4/15.
//  Copyright (c) 2015 Osadchy Dima. All rights reserved.
//

#ifndef __worker_salary__Worker_monthly_salary__
#define __worker_salary__Worker_monthly_salary__

#include "Worker.h"

class Worker_monthly_salary : public Worker{
protected:
    double salary;
public:
    Worker_monthly_salary(const std::string&, const std::string&, const double&);
    
    void print(std::ostream&)const;

    double getSalary() const;

};



#endif /* defined(__worker_salary__Worker_monthly_salary__) */
