# Task Scheduler

A program that manages related tasks. 

### Public interface TTaskScheduler

 - **add** - accepts a task for it as an argument. Returns an object describing the added task (Pointer to the task).
 - **getFutureResult<T>** - returns an object from which you can get the result of a task passed as a result of type T in the future.
 - **getResult<T>** -  returns the result of a specific type of task. Calculates it if it has not been calculated yet, unnecessary tasks are not calculated.
 - **executeAll** - executes all scheduled tasks. Execution takes place in a topological order. If a cyclical dependency is detected, the program throws an exception.


### Example of tasks

Finding the roots of a quadratic equation.


```cpp
struct AddNumber {
  float add(float a) const {
    return a + number;
  }

  float number;
};

float a = 1;
float b = -2;
float c = 0;
AddNumber add{
  .number = 3
};

TTaskScheduler scheduler;

auto id1 = scheduler.add([](float a, float c) {return -4 * a * c;}, a, c);

auto id2 = scheduler.add([](float b, float v) {return b * b + v;}, b, scheduler.getFutureResult<float>(id1));

auto id3 = scheduler.add([](float b, float d) {return -b + std::sqrt(d);}, b, scheduler.getFutureResult<float>(id2));

auto id4 = scheduler.add([](float b, float d) {return -b - std::sqrt(d);}, b, scheduler.getFutureResult<float>(id2));

auto id5 = scheduler.add([](float a, float v) {return v/(2*a);}, a, scheduler.getFutureResult<float>(id3));

auto id6 = scheduler.add([]{float a, float v} {return v/(2*a);}, a, scheduler.getFutureResult<float>(id4));

auto id7 = scheduler.add(&AddNumber::add, add, scheduler.getFutureResult<float>(id6));

scheduler.executeAll();

std::cout << "x1 = " << scheduler.getResult<float>(id5) << std::endl;
std::cout << "x2 = " << scheduler.getResult<float>(id6) << std::endl;
std::cout << "x3 = " << scheduler.getResult<float>(id7) << std::endl;
```

Where getFutureResult is the result of performing a task in the future,



### Requirements and limitations for tasks

- [Callable object](https://en.cppreference.com/w/cpp/named_req/Callable)
- The number of arguments is not more than 2
- A task can be a pointer to a class method. In this case, the first argument is the class from which the method will be called. The class itself is also considered an argument.

## Constraints
The standart library except containers and smart pointers
