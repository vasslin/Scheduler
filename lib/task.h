#pragma once
#include "any.h"
#include "argument.h"
#include "scheduler.h"

class TTaskScheduler;


template <typename T>
class FutureResult;

class Task {
   public:

    friend class TTaskScheduler;
    template <typename T> friend class FutureResult;

    virtual bool hasResult() const = 0;
    const Any& getResult() const { return result_; }
    bool inExecuting() const { return in_executing; }

   protected:
    virtual void execute() = 0;

    bool in_executing = false;

    Any result_;
};

template <typename Func>
class TaskZero : public Task {
   public:
    TaskZero(Func func) : func_(Func(func)) {}

    virtual bool hasResult() const override { return !result_.empty(); }

   private:
    virtual void execute() override {
        if (result_.empty()) {
            in_executing = true;
            result_ = func_();
            in_executing = false;
        }
    }
    Func func_;
};

template <typename Func, typename T>
class TaskSingle : public Task {
   public:
    template <typename F, typename U>
    TaskSingle(F&& func, U&& arg) : func_(Func(std::forward<F>(func))), arg_(Argument<T>(std::forward<U>(arg))) {}

    virtual bool hasResult() const override { return !result_.empty(); }

   private:
    virtual void execute() override {
        if (result_.empty()) {
            in_executing = true;

            result_ = func_(arg_.getArgument());

            in_executing = false;
        }
    }
    Func func_;
    Argument<T> arg_;
};

template <typename Func, typename T, typename U>
class TaskPair : public Task {
   public:
    template <typename F, typename A, typename B>
    TaskPair(F&& func, A&& arg1, B&& arg2)
        : func_(Func(std::forward<F>(func))),
          arg1_(Argument<T>(std::forward<A>(arg1))),
          arg2_(Argument<U>(std::forward<B>(arg2))) {}

    virtual bool hasResult() const override { return !result_.empty(); }

   private:
    virtual void execute() override {
        if (result_.empty()) {
            in_executing = true;

            result_ = func_(arg1_.getArgument(), arg2_.getArgument());

            in_executing = false;
        }
    }
    Func func_;
    Argument<T> arg1_;
    Argument<U> arg2_;
};

template <typename Obj, typename R>
class TaskClassZero : public Task {
   public:
    using Func = R (Obj::*)() const;

    template <typename O>
    TaskClassZero(Func func, O&& obj) : func_(func), obj_(std::forward<O>(obj)) {}

    virtual bool hasResult() const override { return !result_.empty(); }

   private:
    virtual void execute() override {
        if (result_.empty()) {
            in_executing = true;

            result_ = (obj_.*func_)();
            in_executing = false;
        }
    }

    Func func_;
    Obj obj_;
};

template <typename Obj, typename R, typename Arg, typename V>
class TaskClassSingle : public Task {
   public:
    using Func = R (Obj::*)(Arg) const;

    template <typename O, typename A>
    TaskClassSingle(Func func, O&& obj, A&& arg)
        : func_(func), obj_(std::forward<O>(obj)), arg_(Argument<V>(std::forward<A>(arg))) {}

    virtual bool hasResult() const override { return !result_.empty(); }

   private:
    virtual void execute() override {
        if (result_.empty()) {
            in_executing = true;
            result_ = (obj_.*func_)(arg_.getArgument());
            in_executing = false;
        }
    }
    Func func_;
    Obj obj_;
    Argument<V> arg_;
};

template <typename T>
class FutureResult {
   public:
    FutureResult(Task* task) : task_(task) {}

    T getFutureResult() {
        if (task_->inExecuting()) {
            throw "Tasks cannot be completed : cyclical dependency detected";
        }
        task_->execute();
        return task_->getResult().getValue<T>();
    }

   private:
    Task* task_;
};
