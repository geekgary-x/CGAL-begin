#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/random_selection.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/algorithm.h>
#include <CGAL/point_generators_2.h>

#include <CGAL/draw_triangulation_2.h>
#include <vector>
typedef CGAL::Exact_predicates_exact_constructions_kernel Kernel;
typedef Kernel::Point_2 Point_2;
typedef CGAL::Creator_uniform_2<double, Point_2> Creator;
typedef std::vector<Point_2> Vector;
typedef CGAL::Delaunay_triangulation_2<Kernel> Delaunay;
typedef Delaunay::Vertex_handle Vertex_handle;

int random_point_2d_delaunay()
{
	Vector points;
	points.reserve(10);

	CGAL::Random_points_in_disc_2<Point_2, Creator> g(150.0);
	CGAL::cpp11::copy_n(g, 10, std::back_inserter(points));

	Delaunay dt;

	dt.insert(points.begin(), points.end());

	CGAL::draw(dt);

	return EXIT_SUCCESS;
}
