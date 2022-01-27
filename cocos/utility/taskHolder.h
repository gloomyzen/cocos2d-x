#ifndef CORE_TASKHOLDER_H
#define CORE_TASKHOLDER_H

#include <deque>
#include <functional>

enum class eTasksStatus {
  STATUS_OK = 0,
  STATUS_ERROR_BREAK
};

typedef std::function<eTasksStatus()> nodeTasks;

class taskHolder {
public:
  taskHolder();
  virtual ~taskHolder() = default;

  void executeTasks();

protected:
  /***
   * Loading nodes with tasks
   * @return std::function<bool()>
   */
  virtual std::deque<nodeTasks> getTasks() = 0;

private:
  bool allTasksLoaded = false;
};

#endif // CORE_TASKHOLDER_H
