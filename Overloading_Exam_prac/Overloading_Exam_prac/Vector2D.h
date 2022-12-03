#pragma once

template <typename T>
class Vector2D
{
public:
    T x,y;
    Vector2D(){}
    Vector2D(T px,T py):x(px),y(py){}
    Vector2D operator!();
    Vector2D operator+(const Vector2D&);
    
};
template <typename T>
Vector2D<T> Vector2D<T>::operator!()
{
    Vector2D<T> result;
    result.x = (this->x * -1);
    result.y = (this->y * -1);
    return result;
}
template <typename T>
Vector2D<T> Vector2D<T>::operator+(const Vector2D<T>& vec)
{
    Vector2D<T> result;
    result.x = this->x + vec.x;
    result.y = this->y + vec.y;
    return result;
}

