/*****************************************************************//**
 * \file   vector_convex_hull_2.cpp
 * \brief  计算标准模板库vector点集的凸多边形
 * 
 * \author StoneHappy
 * \date   January 2023
 *********************************************************************/
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/convex_hull_2.h>

#include <vector>

typedef CGAL::Exact_predicates_exact_constructions_kernel K;
typedef K::Point_2 Point_2;

typedef std::vector<Point_2> Points;

/**
 * \brief 计算标准模板库vector点集的凸多边形
 * 
 * 传入vector 的begin和end迭代器、结果的后向迭代器
 * 
 * \return 
 */
int vector_convex_hull_2()
{
	Points points, result;
	points.push_back(Point_2(0, 0));
	points.push_back(Point_2(10, 0));
	points.push_back(Point_2(10, 10));
	points.push_back(Point_2(6, 5));
	points.push_back(Point_2(4, 1));

	CGAL::convex_hull_2(points.begin(), points.end(), std::back_inserter(result));
	std::cout << result.size() << "points on the convex hull" << std::endl;
	return 0;
}
