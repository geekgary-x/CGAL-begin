#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/intersections.h>
typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
typedef Kernel::Point_2 Point_2;
typedef Kernel::Line_2 Line_2;
typedef Kernel::Intersect_2 Intersect_2;

int intersection_2_L_L()
{
	Line_2 lina(1, 1, 2);
	Line_2 linb(1, -1, 1);

	CGAL::cpp11::result_of<Intersect_2(Line_2, Line_2)>::type 
		result = intersection(lina, linb);

	if (result)
	{
		const Point_2* p = boost::get<Point_2 >(&*result);
		std::cout << *p << std::endl;
	}

	return 0;
}

typedef Kernel::Point_3 Point_3;
typedef Kernel::Line_3 Line_3;
typedef Kernel::Intersect_3 Intersect_3;

int intersection_3_L_L()
{
	Point_3 linea_b(0, 0, 0);
	Point_3 linea_e(1, 1, 1);

	Point_3 lineb_b(0, 1, 0);
	Point_3 lineb_e(1, 0, 1);

	Line_3 lina(linea_b, linea_e);
	Line_3 linb(lineb_b, lineb_e);

	CGAL::cpp11::result_of<Intersect_3(Line_3, Line_3)>::type
		result = intersection(lina, linb);
	if (result)
	{
		const Point_3* p = boost::get<Point_3 >(&*result);
		std::cout << *p << std::endl;
	}
	return 0;
}

#include <CGAL/Triangle_2.h>
typedef Kernel::Triangle_2 Triangle_2;
typedef Kernel::Segment_2 Segment_2;
int intersection_3_L_T()
{
	Line_2 line(0, -1, 1);
	Triangle_2 triangle(Point_2(0, 0), Point_2(2, 0), Point_2(1, 1.732));

	CGAL::cpp11::result_of<Intersect_2(Line_2, Triangle_2)>::type
		result = intersection(line, triangle);

	if (result)
	{
		if (const Point_2* p = boost::get<Point_2>(&*result))
		{
			std::cout << "Points intersect: " << std::endl;
			std::cout << *p << std::endl;
		}
		else
		{
			std::cout << "Segment intersect:" << std::endl;
			const Segment_2* s = boost::get<Segment_2>(&*result);
			std::cout << *s << std::endl;
		}
	}
	else
	{
		std::cout << "None Intersection" << std::endl;
	}
	return 0;
}
