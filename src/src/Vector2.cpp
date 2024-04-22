#include "Vector2.h"


std::ostream& operator<<(std::ostream& Os, const Vector2& vector)
{
    Os << "[" << vector.x << "," << vector.y << "]";
    return Os;
}