// Compile Error 0
#include <iostream>
#if 0
template <class K> struct MyPoint
{

};

template <class K> struct MyLine
{

};

template <class K> struct MyConstruct
{
	typedef typename K::Line_2 Line_2;
	typedef typename K::Point_2 Point_2;
	Line_2 operator()( Point_2, Point_2 ) {
		return Line_2();
	}
};

template <class K> struct MyLess
{

};

struct Kernel
{
	typedef MyPoint<Kernel> Point_2;
	typedef MyLine<Kernel> Line_2;
	typedef MyConstruct<Kernel> Construct_line_2;
	typedef MyLess<Kernel> Less_xy_2;
};

template <class K> struct NewPoint
{

};

struct New_Kernel : public Kernel
{
	typedef NewPoint<New_Kernel> Point_2;
};
int kernel()
{
	New_Kernel::Point_2 p, q;
	New_Kernel::Construct_line_2 construct_line_2;
	New_Kernel::Line_2 line = construct_line_2(p, q); // error: no match for call to ¡®(Kernel::Construct_line_2 {aka MyConstruct<Kernel>}) (New_kernel::Point_2&, New_kernel::Point_2&)¡¯
}
#endif

// Compile Error 1
template <class K> struct MyPoint { float x, y; };
template <class K> struct MyLine { };
template <class K> struct MyConstruct {
	typedef typename K::Line_2 Line_2;
	typedef typename K::Point_2 Point_2;

	Line_2 operator() (Point_2, Point_2) const
	{
		return Line_2();
	}
};

template <class K> struct MyLess {
	typedef typename K::Point_2 Point_2;

	bool operator() (Point_2, Point_2) const
	{
		return true;
	}
};

template < class K >
struct Kernel_base {
	typedef MyPoint< K > Point_2;
	typedef MyLine< K > Line_2;
	typedef MyConstruct< K > Construct_line_2;
	typedef MyLess< K > Less_xy_2;
	Less_xy_2 less_xy_2_object() const {
		return Less_xy_2();
	}
	Construct_line_2 construct_line_2_object() const
	{
		return Construct_line_2();
	}
};

struct Kernel : public Kernel_base<Kernel> { };

template <class K>
struct MyLeftTurn
{};

template <class K> struct NewPoint
{
	float x, y;
};

template <class K>
struct New_kernel_base : public Kernel_base<K>
{
	typedef NewPoint<K> Point_2;
	typedef MyLeftTurn<K> Left_turn_2;
};

struct New_kernel : public New_kernel_base<New_kernel>
{};

template < class K >
bool
less_xy_2(typename K::Point_2 p, typename K::Point_2 q, K k = K())
{
	return k.less_xy_2_object()(p, q);
}

int kernel()
{
	Kernel::Point_2 p, q;
	p.x = 0; p.y = 1;
	q.x = 2; q.y = 3;
	if (less_xy_2<Kernel>(p, q)) { std::cout << "q < q" << std::endl; }
	else { std::cout << "q > q" << std::endl; }
	return 0;
}
