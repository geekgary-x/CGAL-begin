#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Point_set_3.h>
#include <CGAL/Point_set_3/IO.h>

#include <CGAL/remove_outliers.h>
#include <CGAL/compute_average_spacing.h>
#include <CGAL/grid_simplify_point_set.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
typedef Kernel::Point_3 Point_3;
typedef Kernel::Vector_3 Vector_3;
typedef CGAL::Point_set_3<Point_3, Vector_3> Point_set;

int surface_reconstruction()
{
	// 输入点云
	Point_set points;

	std::string fname = CGAL::data_file_path("points_3/kitten.xyz");

	std::ifstream stream(fname, std::ios::binary);

	if (!stream)
	{
		std::cerr << "Error: cannot read file " << fname << std::endl;
		return EXIT_FAILURE;
	}

	stream >> points;

	std::cout << "Read " << points.size() << " point(s)" << std::endl;
	if (points.empty())
		return EXIT_FAILURE;

	// 过滤离平面较为离散的点云
	typename Point_set::iterator rout_it = CGAL::remove_outliers<CGAL::Sequential_tag>(
		points, 24, points.parameters().threshold_percent(5.0)
		);
	points.remove(rout_it, points.end());

	std::cout << points.number_of_removed_points() << " point(s) are outliters" << std::endl;

	// 删除标记为remove的点云内存
	points.collect_garbage();

	// 计算点云与周围六个顶点的平均距离
	double spacing = CGAL::compute_average_spacing<CGAL::Sequential_tag>(
		points, 6
		);
	// 简化点云
	typename Point_set::iterator gsim_it = CGAL::grid_simplify_point_set(points, 2. * spacing);
	points.remove(gsim_it, points.end());
	std::cout << points.number_of_removed_points()
		<< " point(s) removed after simplification." << std::endl;
	points.collect_garbage();
}
