/*****************************************************************//**
 * \file   predicates_and_constructions.cpp
 * \brief  �жϺ͹���
 * 
 * \author StoneHappy
 * \date   January 2023
 *********************************************************************/
#include <CGAL/Simple_cartesian.h>

typedef CGAL::Simple_cartesian<double> Kernel;
typedef Kernel::Point_2 Point_2;
typedef Kernel::Segment_2 Segment_2;
/**
 * \brief ν���빹��  
 * 
 * �ж���Ҫ���ڱȽϺͷ��࣬����㷵��ֵ�ǲ������ͻ���ö������
 * 
 * ��������Ҫ�����㷨�����м��ζ���Ļ����ϲ����µļ��ζ���
 * 
 * \return 
 */
int predicates_and_constructions()
{
	Point_2 p(1, 1), q(10, 10);
	std::cout << "p = " << p << std::endl;
	std::cout << "q = " << q.x() << " " << q.y() << std::endl;

	std::cout << "sqdist(p, q) = " \
		<< CGAL::squared_distance(p, q) << std::endl;

	Segment_2 s(p, q);
	Point_2 m(5, 9);

	std::cout << "m = " << m << std::endl;
	std::cout << "sqdist(Segment_2(p,q), m) = " \
		<< CGAL::squared_distance(s, m) << std::endl;

	std::cout << "p, q, and m ";
	switch (CGAL::orientation(p, q, m))
	{
	case CGAL::COLLINEAR:
		std::cout << "are collinear\n";
		break;
	case CGAL::LEFT_TURN:
		std::cout << "make a left turn\n";
		break;
	case CGAL::RIGHT_TURN:
		std::cout << "make a right turn\n";
		break;
	default:
		break;
	}

	std::cout << " midpoint(p,q) = " << CGAL::midpoint(p, q) << std::endl;
	return 0;
}