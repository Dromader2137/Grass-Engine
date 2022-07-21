#include "Quaternion.h"

namespace grs
{
    Quaternion Quaternion::operator*(Quaternion a)
    {
        return Quaternion(
            this->w * a.x - this->x * a.w - this->y * a.z - this->z * a.y,
            this->w * a.y - this->x * a.z - this->y * a.w - this->z * a.x,
            this->w * a.z - this->x * a.y - this->y * a.x - this->z * a.w,
            this->w * a.w - this->x * a.x - this->y * a.y - this->z * a.z
        );
    }
    Quaternion& Quaternion::operator*=(Quaternion a)
    {
        Quaternion* q = this;
        this->x = q->w * a.x - q->x * a.w - q->y * a.z - q->z * a.y;
        this->y = q->w * a.y - q->x * a.z - q->y * a.w - q->z * a.x;
        this->z = q->w * a.z - q->x * a.y - q->y * a.x - q->z * a.w;
        this->w = q->w * a.w - q->x * a.x - q->y * a.y - q->z * a.z;
        return *this;
    }
    Vector3f Quaternion::operator*(Vector3f a)
    {
        Vector3f u = Vector3f(this->x, this->y, this->z);

        float s = this->w;

        return u * 2 * Vector3f::Dot(u, a) +
            a * (s * s - Vector3f::Dot(u, u)) +
            Vector3f::Cross(u, a) * 2 * s;
    }

    Quaternion::Quaternion(float x, float y, float z, float w)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }
    Quaternion::Quaternion()
    {
        this->x = 0;
        this->y = 0;
        this->z = 0;
        this->w = 1;
    }
}

