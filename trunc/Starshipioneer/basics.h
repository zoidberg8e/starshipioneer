#ifndef BASICS_H
#define BASICS_H

struct coord
{
    float x, y, ang;

    coord() { }

    coord(float x, float y, float ang) : x(x), y(y), ang(ang) { }

    coord(const coord &c) : x(c.x), y(c.y), ang(c.ang) { }

    coord operator+(const coord &other) const { coord c(*this); c+=other; return c; }
    coord operator-(const coord &other) const { coord c(*this); c-=other;  return c; }

    void operator+=(const coord &other) { x += other.x; y += other.y; ang += other.ang; }
    void operator-=(const coord &other) { x -= other.x; y -= other.y; ang += other.ang; }
};

struct size
{
    float width, height;

    size() { }

    size(float width, float height) : width(width), height(height) { }

    size(const size &c) : width(c.width), height(c.height) { }

    size operator+(const size &other) const { size c(*this); c+=other; return c; }
    size operator-(const size &other) const { size c(*this); c-=other;  return c; }

    void operator+=(const size &other) { width += other.width;height += other.height; }
    void operator-=(const size &other) { width -= other.width; height -= other.height; }
};

enum entityType
{
    ENTITY_STARSHIP,
    ENTITY_PINGUIN,

    NOF_ENTITY
};

#endif // BASICS_H
