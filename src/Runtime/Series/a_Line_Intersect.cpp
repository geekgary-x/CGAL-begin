#include "index.h"
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/intersections.h>
#include <iostream>
typedef CGAL::Exact_predicates_exact_constructions_kernel K;
typedef K::Point_2 Point_2;
typedef K::Line_2 Line_2;
typedef K::Intersect_2 Intersect_2;
int a_test_line_intersect()
{
	std::cout << "test line intersect" << std::endl;
	Line_2 lina(1, 1, 2);
	Line_2 linb(1, -1, 1);
	CGAL::cpp11::result_of<Intersect_2(Line_2, Line_2)>::type
		result = intersection(lina, linb);
	if (result)
	{
		const Point_2* p = boost::get<Point_2 >(&*result);
		std::cout << *p << std::endl;
	}
	//system("pause");
	return 0;
}
