//
//  main.cpp
//  worker_salary
//
//  Created by Osadchy Dima on 3/3/15.
//  Copyright (c) 2015 Osadchy Dima. All rights reserved.
//

#include <iostream>
#include "Worker_hourly_salary.h"
#include "Worker_monthly_salary.h"
#include "Worker.h"
#include "Worker_group.h"
#include "Factory.h"

int main(int argc, const char * argv[]) {
    
    
    Worker_group workers;
    std::string filename = "/Users/dimao/Documents/Programming/worker_salary/out.txt";
    
    std::cout << std::endl;
    std::cout << "-------------------" << std::endl;
    std::cout << "Task 5: Read from file" << std::endl;
    readFromFile(workers, filename);
    std::cout << filename;
    
    std::cout << std::endl;
    std::cout << "-------------------" << std::endl;
    std::cout << "Task 1: Sort by salary, if salary equal, sort by names: " << std::endl;
    workers.sortBySalary();
    workers.print(std::cout);
    
    
    std::cout << std::endl;
    std::cout << "-------------------" << std::endl;
    std::cout << "Task 2: Show first 5  " << std::endl;
    workers.printFirst(std::cout, 5);
    

    std::cout << std::endl;
    std::cout << "-------------------" << std::endl;
    std::cout << "Task 3: Show Last 3" << std::endl;
    workers.printLast(std::cout, 3);

    
    std::cout << std::endl;
    std::cout << "-------------------" << std::endl;
    std::cout << "Task 4: Save to file" << std::endl;
    save2file(workers, filename);
    std::cout << filename;
    
    return 0;
}
