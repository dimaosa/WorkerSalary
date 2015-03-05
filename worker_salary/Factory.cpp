//
//  Factory.cpp
//  worker_salary
//
//  Created by Osadchy Dima on 3/4/15.
//  Copyright (c) 2015 Osadchy Dima. All rights reserved.
//

#include "Factory.h"

void save2file(const Worker_group& workers, const std::string& filename){
    
    std::ofstream out(filename, std::ofstream::binary);
    
    //writitng all workers to file
    workers.print(out);
    out.close();
}
void readFromFile(Worker_group& workers, const std::string& filename){
    
    std::ifstream in_file(filename);
    std::string line;
    
    //part_str - every element in line
    std::string part_str;
    
    std::vector<std::string> worker;
    
    if (in_file.is_open()) {
        
        while (std::getline(in_file, line)) {
            std::stringstream ss(line);
            while (std::getline(ss, part_str, ',')) {
                worker.push_back(part_str);
            }
            //create worker and added it to a list of workers
            createWorker(workers, worker);
            worker.clear();
        }
    }
}

void createWorker(Worker_group& workers, const std::vector<std::string>& worker){
    
    if (!worker.empty()) {
        if (Worker_hourly_salary::match(worker[0])) {
            workers.add(Worker_hourly_salary::create(worker));
        }else if(Worker_monthly_salary::match(worker[0])){
            workers.add(Worker_monthly_salary::create(worker));
        }
    }else{
        std::cerr << "Invalid worker input";
    }
    
}


