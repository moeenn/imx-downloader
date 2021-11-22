#include "./WorkerPool.hpp"
#include <chrono>

WorkerPool::WorkerPool(uint max_workers)
    : m_max_workers(max_workers), m_current(0) {}

void WorkerPool::add(std::function<void(void)> func) {
  m_functions.push_back(func);
}

void WorkerPool::start() {
  for (auto &func : m_functions) {

  jump:
    if (m_current.value() >= m_max_workers - 1) {
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
      goto jump;
    }

    m_threads.push_back(std::thread{[&]() {
      m_current.increment();
      func();
      m_current.decrement();
    }});
  }

  for (auto &t : m_threads)
    if (t.joinable())
      t.join();
}