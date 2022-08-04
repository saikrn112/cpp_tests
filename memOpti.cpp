#include <iostream>
#include <chrono>
char ui_buf[0x4000]; //16Kilo bytes
int totalSetSize = 10000;
int dynamicRun = 0;
int staticRun = 0;
int totalRuns = 10000;
int numberOfAllocs = 100;

void doSomeComputation(char* buf)
{
    for(int i=0; i<totalSetSize; ++i)
    {
        buf[i]=i;
    }
}

int main()
{
    for(int globalrun=0; globalrun<totalRuns; ++globalrun)
    {
	    // Start
	    auto start = std::chrono::high_resolution_clock::now();
	
	    /*** CODE ***/ 
	    char* buf;
	    for (int i = 0; i<numberOfAllocs; ++i)
	    {
	        buf = new char[0x4000];
	        doSomeComputation(buf);
	        delete buf;
	    }
	    /***********/ 
	
	    // Stop and Print
	    auto finish = std::chrono::high_resolution_clock::now();
	    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start);
        dynamicRun += elapsed.count();
	
	    // Start
	    start = std::chrono::high_resolution_clock::now();
	    /*** CODE ***/ 
	    for (int i = 0; i<numberOfAllocs; ++i)
	    {
	        doSomeComputation(buf);
	        memset(ui_buf,0,totalSetSize);
	    }
	    /***********/ 
	    // Stop and Print
	    finish = std::chrono::high_resolution_clock::now();
	    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start);
        staticRun += elapsed.count();
    }
    double avgDynamicRunTime = (double)dynamicRun/(double)totalRuns;
    double avgStaticRunTime = (double)staticRun/(double)totalRuns;
    std::cout << "Dynamic Allocation in Loop:" << avgDynamicRunTime << " ns" << std::endl;
    std::cout << "Static Allocation in Loop:" << avgStaticRunTime << " ns" << std::endl;
    double diff = avgDynamicRunTime - avgStaticRunTime;
    if(diff>=0)
    {
        std::cout << "Dynamic Allocation is faster by :" << diff << " ns" << std::endl;
    }
    else
    {
        std::cout << "Dynamic Allocation is faster by :" << (-1)*diff << " ns" << std::endl;
    }

    return 0;
}
