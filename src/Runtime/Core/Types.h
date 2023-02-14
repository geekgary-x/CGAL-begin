#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/Point_set_3.h>
#include <CGAL/Triangulation_2.h>
typedef CGAL::Exact_predicates_exact_constructions_kernel Kernel;

typedef Kernel::Point_3 Point_3;

typedef CGAL::Surface_mesh<Point_3> Surface_mesh;
typedef std::array<std::size_t, 3> Facet;
typedef Kernel::Line_3 Line_3;
typedef std::array<Point_3, 2> Vector;
typedef Surface_mesh::Edge_index Edge_Descritor;

typedef Kernel::Triangle_3 Triangle_3;
typedef CGAL::Bbox_3 Bbox_3;

typedef Surface_mesh::Face_index Face_descriptor;
typedef Surface_mesh::Vertex_index Vertex_descriptor;
typedef Surface_mesh::Halfedge_index Halfedge_descriptor;

typedef CGAL::Point_set_3<Point_3> Point_set;


typedef CGAL::Triangulation_2<Kernel>      Triangulation;
typedef Triangulation::Vertex_handle  Trianglation_Vertex_handle;
typedef Triangulation::Point          Trianglation_Point;
typedef Triangulation::Finite_vertex_handles    Trianglation_Finite_vertex_handles;

// The following types are different
// Its value type is Triangulation_2::Vertex
typedef Triangulation::Finite_vertices_iterator Trianglation_Finite_vertices_iterator;
// Its value type is Triangulation_2::Vertex_handle
typedef Trianglation_Finite_vertex_handles::iterator         Trianglation_Finite_vertex_handles_iterator;