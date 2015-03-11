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
    if (!workers.empty()) {
        workers.pop_back();
    }else{
        std::cout << "Nothing to delete from list";
    }
}
void Worker_group::printFirst(std::ostream& os, int count){
    
    //if count is bigger than elements in workers, it shows all workers
    int step = count;
    if (step > 0) {
        
        if (count > workers.size()) {
            step = (int)workers.size();
        }
        typename WorkerList::iterator it_stop = workers.begin();
        std::advance(it_stop, step);
        std::for_each(workers.begin(), it_stop, [&] (Worker_ptr worker){
            os << worker->name << std::endl;
        });
    }
}
void Worker_group::printLast(std::ostream& os, int count){
    
    //if count is bigger than elements in workers, it shows all workers
    int step;
    if (step > 0) {
        step = count;
        if (step > workers.size()) {
            step = (int)workers.size();
        }
        typename WorkerList::iterator it = workers.begin();
        std::advance(it, workers.size() - step);
        std::for_each(it, workers.end(), PrintIt<std::ostream>(os));
    }
}
void Worker_group::print(std::ostream& os)const{
    
    std::for_each(workers.begin(), workers.end(), PrintIt<std::ostream>(os));
}
void Worker_group::sortBySalary(){
    
    //compare by salary, if salary equal, compare by names, descend order
    workers.sort(compareWorkers);
    
}
