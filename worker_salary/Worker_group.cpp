//
//  Worker_group.cpp
//  worker_salary
//
//  Created by Osadchy Dima on 3/4/15.
//  Copyright (c) 2015 Osadchy Dima. All rights reserved.
//
#include "Worker_group.h"

Worker_group::~Worker_group(){}

void Worker_group::add(Worker_ptr worker){
    workers.push_back(worker);
}
void Worker_group::removeWorker(int pos){
    if (pos > 0 && pos <= workers.size()) {
        typename WorkerList::iterator it = workers.begin();
        std::advance(it, pos);
        Worker_group::workers.erase(it);
    }else {
        std::cout << "Your position is out of range";
    }
}
void Worker_group::removeWorker(){
    if (workers.size()) {
        workers.pop_back();
    }else{
        std::cout << "Nothing to delete from list";
    }
}
void Worker_group::printFirst(std::ostream& os, int count){
    
    int step = count;
    if (step > 0) {
        
        if (count > workers.size()) {
            step = (int)workers.size();
        }
        typename WorkerList::iterator it_stop = workers.begin();
        std::advance(it_stop, step);
        for (typename WorkerList::iterator it = workers.begin(); it != it_stop; it++) {
            os << (*it)->name << std::endl;
        }
    }
}
void Worker_group::printLast(std::ostream& os, int count){
    int step;
    if (step > 0) {
        step = count;
        if (step > workers.size()) {
            step = (int)workers.size();
        }
        typename WorkerList::iterator it = workers.begin();
        std::advance(it, workers.size() - step);
        do{
            (*it)->print(os);
            it++;
        }while(it != workers.end());
    }
}
void Worker_group::print(std::ostream& os)const{
    
    for (auto i : workers) {
        i->print(os);
    }
}
void Worker_group::sortBySalary(){
    
    workers.sort(compareWorkers);
    
}
