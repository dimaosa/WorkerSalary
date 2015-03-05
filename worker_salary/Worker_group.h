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
    
    double getSalary()const{return 0;}
    void print(std::ostream&)const;
    
    void add(Worker_ptr);
    void removeWorker(int);
    void removeWorker();
    
    void sortBySalary();
    
    void printFirst(std::ostream&, int count);
    void printLast(std::ostream&, int count);
    
protected:
    //Worker_ptr in helper_functions.h
    typedef std::list<Worker_ptr> WorkerList;
    WorkerList workers;
};

#endif /* defined(__worker_salary__Worker_group__) */
