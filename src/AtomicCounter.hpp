#ifndef __ATOMIC_COUNTER__
#define __ATOMIC_COUNTER__

#include <iostream>
#include <mutex>

class AtomicCounter {
private:
  uint m_counter;
  std::mutex m_mutex;

public:
  AtomicCounter(uint start);
  void increment();
  void decrement();
  uint value();
};

#endif