#pragma once

#include <iostream>

namespace gml 
{
    template <typename T>
    class Quaternion
    {
    private:
        T r, i, j, k;
    public:
        Quaternion();
        Quaternion(T, T, T, T);
        Quaternion(const Quaternion<T>&);
        ~Quaternion();
        
        const Quaternion<T> &operator = (const Quaternion<T>&);
        Quaternion<T> operator + (const Quaternion<T>&);
        Quaternion<T> operator - (const Quaternion<T>&);
        Quaternion<T> operator * (const Quaternion<T>&);
        Quaternion<T> operator * (T);
        Quaternion<T> operator / (const Quaternion<T>&);
        
        Quaternion<T> inverse() const;
        
        std::ostream &print(std::ostream &) const;
        std::istream &input(std::istream &s);
    }
}