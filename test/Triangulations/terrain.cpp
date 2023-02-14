#include <CGAL/Projection_traits_xy_3.h>
#include <CGAL/Projection_traits_xz_3.h>
#include <CGAL/Projection_traits_yz_3.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <fstream>
#include <Core/Types.h>
#include <CGAL/draw_triangulation_2.h>
#include <CGAL/draw_point_set_3.h>
#include <Core/Types.h>
typedef CGAL::Projection_traits_xy_3<Kernel>  Gt;
typedef CGAL::Delaunay_triangulation_2<Gt> Delaunay;
namespace CGALBeginTests
{
	namespace Triangulations
	{
		int terrain()
		{
			//std::ifstream in(CGAL::data_file_path("points_3/point_set_3.xyz"));
			//std::ifstream inpp(CGAL::data_file_path("points_3/point_set_3.xyz"));

			std::ifstream in("D:/codes/mesh_merge/out/bin/Debug/borderPoints.ply");
			std::ifstream inpp("D:/codes/mesh_merge/out/bin/Debug/borderPoints.ply");
			std::istream_iterator<Point_3> begin(in);
			std::istream_iterator<Point_3> end;
			Point_set pointset;
			inpp >> pointset;

			CGAL::draw(pointset);
			Delaunay dt(pointset.points().begin(), pointset.points().end());
			std::cout << dt.number_of_vertices() << std::endl;

			CGAL::draw(dt);
			return 0;
		}

	}
}