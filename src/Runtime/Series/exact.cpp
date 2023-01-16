/*****************************************************************//**
 * \file   exact.cpp
 * \brief  精确内核问题
 * 
 * \author StoneHappy
 * \date   January 2023
 *********************************************************************/
#pragma once
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <sstream>
typedef CGAL::Exact_predicates_exact_constructions_kernel Kernel;
typedef Kernel::Point_2 Point_2;
/**
 * \brief
 *   
 * (1)点的位置在代码中表示为一个text
 * 被计算机读入时会转换为float的形式
 * 在计算时又会被转换为任意精度的有理数
 * 这个有理数在浮点精度上是精确的
 * 之后的位数是不精确的
 * 
 * (2)从文本能够构建任意精度的有理数
 * 
 * (3)构造不会溢出，且对结果封闭
 * \return 
 */
int exact()
{
	Point_2 p(0, 0.3), q, r(2, 0.9);
	{
		q = Point_2(1, 0.6);
		std::cout << (CGAL::collinear(p, q, r) ? "collinear\n" : "not collinear\n");
	}

	{
		std::istringstream input("0 0.3   1 0.6   2 0.9");
		input >> p >> q >> r;
		std::cout << (CGAL::collinear(p, q, r) ? "collinear\n" : "not collinear\n");
	}

	{
		q = CGAL::midpoint(p, r);
		std::cout << (CGAL::collinear(p, q, r) ? "collinear\n" : "not collinear\n");
	}
	return 0;
}
