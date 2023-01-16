/*****************************************************************//**
 * \file   miniqt_project.cpp
 * \brief  最简单CGAL Qt项目
 * 
 * \author StoneHappy
 * \date   January 2023
 *********************************************************************/
#include <CGAL/Simple_cartesian.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/draw_surface_mesh.h>
#include <CGAL/draw_polygon_2.h>
#include <fstream>
typedef CGAL::Simple_cartesian<double>                       Kernel;
typedef Kernel::Point_3                                      Point;
typedef CGAL::Surface_mesh<Point>                            Mesh;

/**
 * \brief CGAL最简单Qt显示代码
 * 
 * \return 
 */
int miniqtproject()
{
  const std::string filename = CGAL::data_file_path("meshes/elephant.off");
  Mesh sm;
  if(!CGAL::IO::read_polygon_mesh(filename, sm))
  {
    std::cerr << "Invalid input file." << std::endl;
    return EXIT_FAILURE;
  }
  CGAL::draw(sm);
  return 0;
}