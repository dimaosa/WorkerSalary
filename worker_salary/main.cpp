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
#include <assert.h>
int main(int argc, const char * argv[]) {
    
    Worker_group workers;
    
    assert(argc > 1);
    std::string in_file = argv[1];
    std::string out_file = (argc>2) ? argv[2] : in_file;
    
    std::cout << std::endl;
    std::cout << "-------------------" << std::endl;
    std::cout << "Task 5: Read from file" << std::endl;
    readFromFile(workers, in_file);
    std::cout << in_file;
    
    
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
    save2file(workers, out_file);
    std::cout << out_file;
    
    return 0;
}
