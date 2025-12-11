#pragma once

#include <memory>
#include <iostream>

// http://en.wikipedia.org/wiki/Curiously_recurring_template_pattern
template <class Base> class RefCounted : public Base
{
protected:
    virtual ~RefCounted() {}

public:
    RefCounted() { m_refCount = 0; }
    RefCounted(RefCounted const& rhs) { m_refCount = 0; }
    RefCounted& operator=(RefCounted const& rhs) { if (this != &rhs) { Base::operator=(rhs); } return *this; }
    int GetRefCount() const { return m_refCount; }
    int AddRef() const { return ++m_refCount; }
    int Release() const
    {
        int refCount = --m_refCount;
        if (0 < refCount)
        {
            return refCount;
        }

        delete this;
        return 0;
    }

private:
    mutable int m_refCount;
};

class IRefCounted
{
protected:
    virtual ~IRefCounted() {}

public:
    virtual int AddRef() const = 0;
    virtual int Release() const = 0;
};

template<class T> class RefCountedPtr
{
private:

    typedef RefCountedPtr this_type;

public:

    RefCountedPtr() : p_(0) {}

    RefCountedPtr(T * p, bool add_ref = true) : p_(p)
    {
        if (p_ != 0 && add_ref) p_->AddRef();
    }

    template<class U> RefCountedPtr(RefCountedPtr<U> const & rhs) : p_(rhs.get())
    {
        if (p_ != 0) p_->AddRef();
    }

    RefCountedPtr(RefCountedPtr const & rhs) : p_(rhs.p_)
    {
        if (p_ != 0) p_->AddRef();
    }

    ~RefCountedPtr()
    {
        if (p_ != 0) p_->Release();
    }

    template<class U> RefCountedPtr & operator=(RefCountedPtr<U> const & rhs)
    {
        this_type(rhs).swap(*this);
        return *this;
    }

    bool operator== (RefCountedPtr<T> const& rhs) const
    {
        return p_ == rhs.p_;
    }

    template<class U> bool operator== (RefCountedPtr<U> const& rhs) const
    {
        return p_ == rhs.get();
    }

    bool operator!= (RefCountedPtr<T> const& rhs) const
    {
        return p_ != rhs.p_;
    }

    template<class U> bool operator!= (RefCountedPtr<U> const& rhs) const
    {
        return p_ != rhs.get();
    }

    RefCountedPtr & operator=(RefCountedPtr const & rhs)
    {
        this_type(rhs).swap(*this);
        return *this;
    }

    RefCountedPtr & operator=(T * rhs)
    {
        this_type(rhs).swap(*this);
        return *this;
    }

    T * get() const
    {
        return p_;
    }

    T& operator*() const
    {
        return *p_;
    }

    T * operator->() const
    {
        return p_;
    }

    void swap(RefCountedPtr & rhs)
    {
        T * tmp = p_;
        p_ = rhs.p_;
        rhs.p_ = tmp;
    }

private:

    T * p_;
};
