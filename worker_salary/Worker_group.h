//
//  Worker_group.h
//  worker_salary
//
//  Created by Osadchy Dima on 3/4/15.
//  Copyright (c) 2015 Osadchy Dima. All rights reserved.
//

#ifndef __worker_salary__Worker_group__
#define __worker_salary__Worker_group__

#include "Worker.h"
#include <list>
#include <stdexcept>
#include <iostream>
#include "helper_functions.h"

class Worker_group : public Worker {
public:
    ~Worker_group();
    
    void add(std::shared_ptr<Worker>);
    void removeWorker(int);
    void removeWorker();
    void print(std::ostream&)const;
    void sortBySalary();
    
    void printFirst5(std::ostream&);
    void printLast3(std::ostream&);
    
    double getSalary()const{return 0;}
    
protected:
    typedef std::list<std::shared_ptr<Worker>> WorkerList;
    WorkerList workers;
};

#endif /* defined(__worker_salary__Worker_group__) */
