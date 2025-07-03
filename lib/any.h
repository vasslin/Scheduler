#pragma once
#include <memory>

class Any {
   public:
    bool empty() const { return res_ == nullptr; }

    Any() = default;

    template <typename T>
    Any(const T& value) {
        res_ = std::shared_ptr<AnyDerived<T>>(new AnyDerived<T>(value));
    }

    template <typename T>
    Any(const Any& value) {
        if (value.res_ == nullptr) {
            res_ = nullptr;
        } else {
            res_ = std::shared_ptr<AnyDerived<decltype(*value.res_)>>(
                new AnyDerived<decltype(*value.res_)>(*value.res_));
        }
    }

    template <typename T>
    Any& operator=(const T& value) {
        res_ = std::shared_ptr<AnyDerived<T>>(new AnyDerived<T>(value));
        return *this;
    }


    template <typename T>
    const T& getValue() const {
        if (res_ != nullptr) {
            return (std::static_pointer_cast<AnyDerived<T>>(res_))->getValue();
        } else {
            throw "Any has no value";
        }
    }

    Any(const Any& other) {}

    Any& operator=(const Any& other) {
        if (other.res_ == nullptr) {
            res_ = nullptr;
            return *this;
        }
        res_ = std::make_shared<AnyDerived<decltype(*other.res_)>>((*other.res_));
        return *this;
    }

   private:
    class AnyBase {};

    template <typename T>
    class AnyDerived : public AnyBase {
       public:
        AnyDerived(const AnyDerived& other) : value_(other.value_) {}
        AnyDerived(AnyDerived&& other) : value_(std::move(other.value_)) {}

        template <typename U>
        AnyDerived(U&& value) : value_(std::forward<U>(value)) {}


        AnyDerived& operator=(AnyDerived& other) {
            value_ = other.value_;
            return *this;
        }
        AnyDerived& operator=(AnyDerived&& other) {
            value_ = std::move(other.value_);
            return *this;
        }

        const T& getValue() const { return value_; }

       private:
        T value_;
    };

    std::shared_ptr<AnyBase> res_;
};