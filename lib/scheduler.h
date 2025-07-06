#pragma once
#include <forward_list>
#include <memory>

#include "any.h"
#include "task.h"

class TTaskScheduler {
   public:
    template <typename T>
    FutureResult<T> getFutureResult(Task* task) {
        if (task == nullptr) {
            throw "Invalid task pointer";
        }
        return FutureResult<T>(task);
    }

    template <typename Obj, typename R>
    TaskClassZero<Obj, R>* add(R (Obj::*func)() const, Obj&& obj) {
        std::shared_ptr<TaskClassZero<Obj, R>> task =
            std::make_shared<TaskClassZero<Obj, R>>(TaskClassZero<Obj, R>(func, std::forward<Obj>(obj)));
        tasks_.push_front(task);
        return task.get();
    }

    template <typename Obj, typename R, typename A, typename V>
    TaskClassSingle<Obj, R, A, V>* add(R (Obj::*func)(A) const, Obj obj, V&& arg) {
        std::shared_ptr<TaskClassSingle<Obj, R, A, V>> task =
            std::make_shared<TaskClassSingle<Obj, R, A, V>>(func, std::forward<Obj>(obj), std::forward<V>(arg));
        tasks_.push_front(task);
        return task.get();
    }

    template <typename Func>
    TaskZero<Func>* add(Func&& func) {
        std::shared_ptr<TaskZero<Func>> task = std::make_shared<TaskZero<Func>>(std::forward<Func>(func));
        tasks_.push_front(task);
        return task.get();
    }

    template <typename Func, typename Arg>
    TaskSingle<Func, Arg>* add(Func&& func, Arg&& arg) {
        std::shared_ptr<TaskSingle<Func, Arg>> task =
            std::make_shared<TaskSingle<Func, Arg>>(std::forward<Func>(func), std::forward<Arg>(arg));
        tasks_.push_front(task);
        return task.get();
    }

    template <typename Func, typename Arg1, typename Arg2>
    TaskPair<Func, Arg1, Arg2>* add(Func&& func, Arg1&& arg1, Arg2&& arg2) {
        std::shared_ptr<TaskPair<Func, Arg1, Arg2>> task = std::make_shared<TaskPair<Func, Arg1, Arg2>>(
            std::forward<Func>(func), std::forward<Arg1>(arg1), std::forward<Arg2>(arg2));

        tasks_.push_front(task);
        return task.get();
    }

    void executeAll() {  // execute in topsort order
        for (auto& task : tasks_) {
            if (!task->hasResult()) {
                task->execute();
            }
        }
    }

    template <typename T>
    T getResult(Task* task) {
        if (task == nullptr) {
            throw "Invalid task pointer";
        }
        return task->getResult().getValue<T>();
    }

    bool hasResult(Task* task) {
        if (task == nullptr) {
            throw "Invalid task pointer";
        }

        return task->hasResult();
    }

   private:
    std::forward_list<std::shared_ptr<Task>> tasks_;
};
