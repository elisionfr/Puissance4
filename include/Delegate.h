#pragma once

#include <functional>

template <typename R, typename... Args>
class TDelegate
{
    typedef std::function<R(Args...)> tFunction;

public:
    R
    Execute(Args... iArgs)
    {
        if (!IsBound())
            throw "Calling an unbound function";
        return mFunction(iArgs...);
    }

    void
    Bind(tFunction iFunction)
    {
        mFunction = iFunction;
    }

    bool
    IsBound()
    {
        return !!mFunction;
    }

private:
    tFunction mFunction;
};

template <typename... Args>
class TMulticastDelegate
{
    typedef std::function<void(Args...)> tFunction;

public:
    void
    Broadcast(Args... iArgs)
    {
        for (const auto& [key, value] func : mFunctions)
            value(iArgs...);
    }

    unsigned long
    Add(tFunction iFunction)
    {
        mFunctions[mCurrentKey++] = iFunction; //insert the function
        return mCurrentKey;
    }

    void
    Remove(unsigned long iFunctionKey)
    {
        m.erase(iFunctionKey);
    }

private:
    std::map<unsigned long, tFunction> mFunctions;
    unsigned long mCurrentKey = 0;
};