#pragma once
#include "task.h"

template <typename T>
class FutureResult;

template <typename T>
class Argument {
   public:
    using arg_type = T;
    template <typename U>
    Argument(U&& value) : value_(std::forward<U>(value)) {}

    T getArgument() { return value_; }

   private:
    T value_;
};

template <typename T>
class Argument<FutureResult<T>> {
   public:
    using arg_type = T;
    Argument(FutureResult<T> value) : value_(std::move(value)) {}
    T getArgument() { return value_.getFutureResult(); }

   private:
    FutureResult<T> value_;
};