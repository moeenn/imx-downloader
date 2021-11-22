#include "./AtomicCounter.hpp"

AtomicCounter::AtomicCounter(uint start) : m_counter(start) {}

void AtomicCounter::increment() {
  std::lock_guard<std::mutex> lock(m_mutex);
  m_counter++;
}

void AtomicCounter::decrement() {
  std::lock_guard<std::mutex> lock(m_mutex);

  if (m_counter == 0)
    return;

  m_counter--;
}

uint AtomicCounter::value() { return m_counter; }