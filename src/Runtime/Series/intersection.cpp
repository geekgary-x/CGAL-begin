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

#include <CGAL/Triangulation_3.h>
typedef CGAL::Triangulation_3<Kernel>      Triangulation;
typedef Triangulation::Finite_facets_iterator Finite_facets_iterator;
typedef Kernel::Point_3 Point_3;
typedef Kernel::Line_3 Line_3;
typedef Kernel::Triangle_3 Triangle_3;
typedef Kernel::Intersect_3 Intersect_3;

int intersection_trianglation()
{

	Point_3 linea_b(0, 0, 0);
	Point_3 linea_e(1, 1, 1);

	Line_3 lina(linea_b, linea_e);


	std::list<Point_3> L;
	L.push_front(Point_3(0, 0, 0));
	L.push_front(Point_3(1, 0, 0));
	L.push_front(Point_3(0, 1, 0));
	L.push_front(Point_3(0, 0, 1));

	Triangulation T(L.begin(), L.end());

	std::vector<Point_3> intersect_points;
	for (Finite_facets_iterator fit = T.finite_facets_begin(); fit != T.finite_facets_end(); fit++)
	{

		Point_3 one = fit->first->vertex(T.vertex_triple_index(fit->second, 0))->point();
		Point_3 two = fit->first->vertex(T.vertex_triple_index(fit->second, 1))->point();
		Point_3 thr = fit->first->vertex(T.vertex_triple_index(fit->second, 2))->point();

		Triangle_3 tri(one, two, thr);

		CGAL::cpp11::result_of<Intersect_3(Line_3, Triangle_3)>::type result = intersection(lina, tri);
		if (result)
		{
			const Point_3* p = boost::get<Point_3 >(&*result);

			bool similiar = false;
			for (size_t i = 0; i < intersect_points.size(); i++)
			{
				Point_3& point = intersect_points[i];
				double distance = sqrt(pow(point.x() - p->x(), 2) +
					pow(point.y() - p->y(), 2) +
					pow(point.z() - p->z(), 2));

				if (distance < 0.000001)
					similiar = true;
			}
			if (!similiar)
				intersect_points.push_back(*p);
		}
	}

	std::cout << "Intersect Point Number: " << intersect_points.size() << std::endl;
	for (size_t i = 0; i < intersect_points.size(); i++)
	{
		std::cout << intersect_points[i] << std::endl;
	}

	return 0;
}