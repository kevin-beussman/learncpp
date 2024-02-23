#include <vector>
#include <iostream>

class Point
{
private:
	int m_x{};
	int m_y{};

public:
	Point(int x, int y)
		: m_x{ x }, m_y{ y }
	{

	}

	friend std::ostream& operator<<(std::ostream& out, const Point& p)
	{
		return out << "Point(" << p.m_x << ", " << p.m_y << ')';
	}
};

class Shape
{
    // virtual print function that takes and returns a std::ostream&, an overloaded operator<< and an empty virtual destructor.
public:
    virtual std::ostream& print(std::ostream& out) const = 0;

    friend std::ostream& operator<<(std::ostream& out, const Shape& s)
    {
        return s.print(out);
    }

    virtual ~Shape() = default;
};

class Triangle: public Shape
{
private:
    Point m_p1;
    Point m_p2;
    Point m_p3;

public:
    Triangle(const Point& p1, const Point& p2, const Point& p3): m_p1{p1}, m_p2{p2}, m_p3{p3}
    {
    }

    std::ostream& print(std::ostream& out) const override
    {
        out << "Triangle(" << m_p1 << ", " << m_p2 << ", " << m_p3 << ")";
        return out;
    }
};

class Circle: public Shape
{
private:
    Point m_center;
    int m_radius;

public:
    Circle(const Point& center, int radius): m_center{center}, m_radius{radius}
    {
    }

    std::ostream& print(std::ostream& out) const override
    {
        out << "Circle(" << m_center << ", " << m_radius << "))";
        return out;
    }

    int getRadius()
    {
        return m_radius;
    }
};

int getLargestRadius(std::vector<Shape*>& vec)
{ 
    int max_radius{0};
    for (Shape* s : vec)
    {
        auto* cur{ dynamic_cast<Circle*>(s) };
        if (cur)
        {
            int currad{ dynamic_cast<Circle*>(s)->getRadius() };
            // std::cout << cur->getRadius() << "\n";
            if (currad > max_radius)
                max_radius = currad;
        }
    }
    return max_radius;
}

int main()
{
	std::vector<Shape*> v{
	  new Circle{Point{ 1, 2 }, 7},
	  new Triangle{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }},
	  new Circle{Point{ 7, 8 }, 3}
	};

	// print each shape in vector v on its own line here
    for (Shape* s : v)
    {
        s->print(std::cout) << "\n";
    }

	std::cout << "The largest radius is: " << getLargestRadius(v) << '\n'; // write this function

	// delete each element in the vector here
    for (Shape* s : v)
    {
        delete s;
    }

	return 0;
}