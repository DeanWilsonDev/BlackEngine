#include <iostream>

using namespace std;

namespace DaemonEngine {
  __declspec(dllimport) void Print();
}


int main() {

    DaemonEngine::Print();
    return 0;
}
