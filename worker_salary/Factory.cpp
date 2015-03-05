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
    workers.print(out);
    out.close();
}
void readFromFile(Worker_group& workers, const std::string& filename){
    
    std::ifstream in_file(filename);
    std::string line;
    std::string part_str;
    std::vector<std::string> worker;
    
    if (in_file.is_open()) {
        
        while (std::getline(in_file, line)) {
            std::stringstream ss(line);
            while (std::getline(ss, part_str, ',')) {
                worker.push_back(part_str);
            }
            createWorker(workers, worker);
            worker.clear();
        }
    }
}
bool validateWorker(const std::vector<std::string>& worker){
    
    if (worker.empty() || worker.size() > 6) return false;
    else return true;
    
}
void createWorker(Worker_group& workers, const std::vector<std::string>& worker){
    
    if (validateWorker(worker)) {
        if (std::strstr(worker[0].c_str(), "Hourly") != NULL) {
            Worker_ptr wrkr (new Worker_hourly_salary(worker[1], worker[2], convertToDouble(worker[3])));
            workers.add(wrkr);
        }
        else if(std::strstr(worker[0].c_str(), "Monthly") != NULL){
            Worker_ptr wrkr (new Worker_monthly_salary(worker[1], worker[2], convertToDouble(worker[3])));
            workers.add(wrkr);
        }
    }else{
        std::cerr << "Invalid worker input";
    }
    
}


