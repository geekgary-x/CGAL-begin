#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Triangle_2.h>
typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
typedef Kernel::Point_2 Point_2;
typedef Kernel::Triangle_2 Triangle_2;

int bonded()
{
	Point_2 p(0, 1);
	Point_2 A(0, 0), B(10, 0), C(0, 10);
	Triangle_2 T(A, B, C);

	if (T.bounded_side(p) == CGAL::ON_UNBOUNDED_SIDE)
	{
		std::cout << "�����������ⲿ" << std::endl;
	}
	else if (T.bounded_side(p) == CGAL::ON_BOUNDARY)
	{
		std::cout << "���������α���" << std::endl;
	}
	else if (T.bounded_side(p) == CGAL::ON_BOUNDED_SIDE)
	{
		std::cout << "�����������ڲ�" << std::endl;
	}

	return 0;
}
