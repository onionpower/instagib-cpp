#include <iostream>
#include <thread>

using namespace std;

void doSomething(int id) {  
  cout << "Thread id = " << id << endl;
}

void spawnThreads(int n)
{
    thread threads[n];
    for (int i = 0; i < n; i++) {
        threads[i] = thread(doSomething, i + 1);
    }

    for (auto& th : threads) {
        th.join();
    }
}

int main (int argc, char ** argv) {
    spawnThreads(5);
    return 0;
}
