#include "qte.h"
#include <array>
#include "matrix.h"
#include <iostream>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	MainWindow mainWin;
	mainWin.showMaximized();

	return app.exec();
	// std::array<double, 9> values1 {
	// 	9, 8, 7,
	// 	4, 5, 6,
	// 	3, 2, 1
	// };

	// std::array<double, 9> values2 {
	// 	1, 2, 3,
	// 	0, 5, 6,
	// 	0, 8, 9
	// };

	// Matrix m1(values1);
	// Matrix m2(values2);
	// Vector v1(3, 4, 5);

	// std::cout<<"M1"<<std::endl;
	// std::cout<<m1<<std::endl;

	// std::cout<<"M2"<<std::endl;
	// std::cout<<m2<<std::endl;

	// std::cout<<"M1 + M2"<<std::endl;
	// std::cout<<m1 + m2<<std::endl;

	// std::cout<<"M1 - M2"<<std::endl;
	// std::cout<<m1 - m2<<std::endl;

	// std::cout<<"M2 * 5"<<std::endl;
	// std::cout<<m2 * 5<<std::endl;

	// std::cout<<"M1 * M2"<<std::endl;
	// std::cout<<m1 * m2<<std::endl;

	// std::cout<<"M1 * v1"<<std::endl;
	// std::cout<<m2 * v1<<std::endl;

	// std::cout<<"!M2"<<std::endl;
	// std::cout<<(!m2)<<std::endl;
	
	// return 0;
}
