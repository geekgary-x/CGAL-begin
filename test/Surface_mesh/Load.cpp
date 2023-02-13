#include <Core/Types.h>
#include <CGAL/Polygon_mesh_processing/IO/polygon_mesh_io.h>
namespace CGALBeginTests
{
	namespace SurfaceMesh
	{
		int load()
		{
			Surface_mesh mesh;
			CGAL::Polygon_mesh_processing::IO::read_polygon_mesh(CGAL::data_file_path("meshes/elephant.off"), mesh);
		}
	}
}