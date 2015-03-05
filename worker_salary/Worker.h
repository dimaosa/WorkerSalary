//
//  Worker.h
//  worker_salary
//
//  Created by Osadchy Dima on 3/3/15.
//  Copyright (c) 2015 Osadchy Dima. All rights reserved.
//

#ifndef __worker_salary__Worker__
#define __worker_salary__Worker__

#include <string>
#include <ostream>

class Worker{
public:
    std::string name;
    std::string position;
    Worker(){}
    Worker(const std::string& name, const std::string& position): name(name), position(position){}
    virtual ~Worker(){};
    
    virtual double getSalary()const=0;
    
    virtual void print(std::ostream&)const=0;
    
    
    
};


#endif /* defined(__worker_salary__Worker__) */
