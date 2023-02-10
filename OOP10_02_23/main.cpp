#include <iostream>
#include <thread>// поток
#include <chrono>// для отслеживания времени
// std::cout - эта функция не потоко безопасная
void work(int a,int b) {
	std::cout << "Work Started! " << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	std::cout << "work thread " << std::this_thread::get_id() << std::endl;
	std::cout << "Work Ended! " << std::endl;
}
int main() {
	// параллелизм и конкурентность
	// конкурентность - когда несколько потоков конкурируют за вычислительную мощность ядра

	std::cout<<"Main thread "<<std::this_thread::get_id() << std::endl;//главный поток
	//не нужно блокировать главный поток, но можем это сделать если не хотим предоставлять доступ пользователю
	std::thread t1([](int a, int b) {
		std::cout << a << " " << b << std::endl;
		std::cout << "Work Started! " << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
		std::cout << "work thread " << std::this_thread::get_id() << std::endl;
		std::cout << "Work Ended! " << std::endl; }, 5, 6);// a = 5,b = 6
	std::thread t2(work,3,2);//указатель на функцию work
	std::cout << "Hello" << std::endl;
	// race conditional - гонка данных или гонка состояния
	t1.join();//присоединение к главному потоку
	t2.join();
	return 0;
	
}