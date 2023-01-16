/*****************************************************************//**
 * \file   surprising.cpp
 * \brief  意外情况
 * 
 * \author StoneHappy
 * \date   January 2023
 *********************************************************************/
#pragma once
#include <iostream>
#include <CGAL/Simple_cartesian.h>

typedef CGAL::Simple_cartesian<double> Kernel;
typedef Kernel::Point_2 Point_2;

/**
 * \brief 意外情况
 * 
 * 由于简单笛卡尔内核是3x3的矩阵运算
 * 
 * 其只能逼近不能相等
 * 
 * \return 
 */
int surprising()
{
	{
		Point_2 p(0, 0.3), q(1, 0.6), r(2, 0.9);
		std::cout << (CGAL::collinear(p, q, r)?"collinear\n":"not collinear\n");
	}

	{
		Point_2 p(0, 1.0/3.0), q(1, 2.0/0.3), r(2, 1);
		std::cout << (CGAL::collinear(p, q, r) ? "collinear\n" : "not collinear\n");
	}

	{
		Point_2 p(0, 0), q(1, 1), r(2, 2);
		std::cout << (CGAL::collinear(p, q, r) ? "collinear\n" : "not collinear\n");
	}
	return 0;
}