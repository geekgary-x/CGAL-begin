/*****************************************************************//**
 * \file   array_convex_hull_2.cpp
 * \brief  从原生数组点集中找到凸多边形集，并生成原生数组结果
 * 
 * \author StoneHappy
 * \date   January 2023
 *********************************************************************/
#include <iostream>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/convex_hull_2.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef K::Point_2 Point_2;

/**
 * \brief 从原生数组点集中找到凸多边形集，并生成原生数组结果
 * 
 * 输入：{0, 0} { 10, 0} {10, 10} {6, 5} {4, 1}
 * 
 * 输出：{0, 0} { 10, 0} {10, 10}能够构成凸多边形
 * 
 * \return 
 */
int array_convex_hull_2()
{
	Point_2 points[5] =\
	{ Point_2(0, 0), Point_2(10, 0),\
	Point_2(10, 10), Point_2(6, 5), Point_2(4, 1) };

	Point_2 result[5];
	Point_2* ptr = CGAL::convex_hull_2(points, points + 5, result);
	std::cout << ptr - result << "points on the convex hull:" << std::endl;
	for (size_t i = 0; i < ptr - result; i++)
	{
		std::cout << result[i] << std::endl;
	}
	return 0;
}
