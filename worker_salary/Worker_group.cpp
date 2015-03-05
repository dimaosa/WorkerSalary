//
//  Worker_group.cpp
//  worker_salary
//
//  Created by Osadchy Dima on 3/4/15.
//  Copyright (c) 2015 Osadchy Dima. All rights reserved.
//
#include <stdexcept>
#include "Worker_group.h"

Worker_group::~Worker_group(){}

void Worker_group::add(std::shared_ptr<Worker> worker){
    workers.push_back(worker);
}
void Worker_group::removeWorker(int pos){
    try {
        typename WorkerList::iterator it = workers.begin();
        std::advance(it, pos);
        Worker_group::workers.erase(it);
        
        
    } catch (const std::out_of_range& oor) {
        std::cerr << "Out of range error: " << oor.what() << std::endl;
    }
}
void Worker_group::removeWorker(){
    try {
        workers.pop_back();
    } catch (const std::out_of_range& oor) {
        std::cerr << "Out of range error: " << oor.what() << std::endl;
    }
}
void Worker_group::printFirst5(std::ostream& os){
    typename WorkerList::iterator it_stop = workers.begin();
    std::advance(it_stop, 5);
    for (typename WorkerList::iterator it = workers.begin(); it != it_stop; it++) {
        os << (*it)->name << std::endl;
    }
}
void Worker_group::printLast3(std::ostream& os){
    int step = 3;
    typename WorkerList::iterator it = workers.begin();
    std::advance(it, workers.size() - step);
    do{
        (*it)->print(os);
        it++;
    }while(it != workers.end());
}
void Worker_group::print(std::ostream& os)const{
    
    for (auto i : workers) {
        i->print(os);
    }
}
void Worker_group::sortBySalary(){
    
    workers.sort(compareWorkers);
    
}
