#include <Core/Types.h>

namespace CGALBeginTests
{
	namespace Triangulations
	{
		int for_loop_2()
		{
			std::vector<Trianglation_Point> points = { {0, 0} , {1, 0}, {0,1} };

			Triangulation T;

			T.insert(points.begin(), points.end());

			std::cout << "Triangulation_2::Finite_vertices_iterator is like a  Triangulation_2::Vertex_handle\n";
			for (Trianglation_Finite_vertices_iterator it = T.finite_vertices_begin();
			it != T.finite_vertices_end(); ++it)
			{
				std::cout << it->point() << std::endl;
			}

			std::cout << "Triangulation_2::Finite_vertex_handles::iterator dereferences to Triangulation_2::Vertex_handle\n";

			Trianglation_Finite_vertex_handles::iterator b, e;
			std::tie(b, e) = T.finite_vertex_handles();

			for (; b!=e;++b)
			{
				Trianglation_Vertex_handle vh = *b;
				std::cout << vh->point() << std::endl;
			}

			std::cout << "and you can use a C++11 for loop\n";
			for (Trianglation_Vertex_handle vh: T.finite_vertex_handles())
			{
				std::cout << vh->point() << std::endl;
			}
			return 0;
		}
	}
}