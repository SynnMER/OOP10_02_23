#include <iostream>
#include <thread>// �����
#include <chrono>// ��� ������������ �������
// std::cout - ��� ������� �� ������ ����������
void work(int a,int b) {
	std::cout << "Work Started! " << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	std::cout << "work thread " << std::this_thread::get_id() << std::endl;
	std::cout << "Work Ended! " << std::endl;
}
int main() {
	// ����������� � ��������������
	// �������������� - ����� ��������� ������� ����������� �� �������������� �������� ����

	std::cout<<"Main thread "<<std::this_thread::get_id() << std::endl;//������� �����
	//�� ����� ����������� ������� �����, �� ����� ��� ������� ���� �� ����� ������������� ������ ������������
	std::thread t1([](int a, int b) {
		std::cout << a << " " << b << std::endl;
		std::cout << "Work Started! " << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
		std::cout << "work thread " << std::this_thread::get_id() << std::endl;
		std::cout << "Work Ended! " << std::endl; }, 5, 6);// a = 5,b = 6
	std::thread t2(work,3,2);//��������� �� ������� work
	std::cout << "Hello" << std::endl;
	// race conditional - ����� ������ ��� ����� ���������
	t1.join();//������������� � �������� ������
	t2.join();
	return 0;
	
}