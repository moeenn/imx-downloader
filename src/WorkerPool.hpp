#ifndef __WORKER_POOL__
#define __WORKER_POOL__

#include "./AtomicCounter.hpp"
#include <functional>
#include <thread>
#include <vector>

class WorkerPool {
private:
  uint m_max_workers;
  std::vector<std::function<void(void)>> m_functions;
  std::vector<std::thread> m_threads;
  AtomicCounter m_current;

public:
  explicit WorkerPool(uint max_workers);
  void add(std::function<void(void)> func);
  void start();
};

#endif