#include <stdio.h>
#include <thread>
using namespace std;

void ThreadPrint(int num) {

	printf("thread %d\n", num);

}

int main() {

	thread threadPrint1(ThreadPrint, 1);
	threadPrint1.join();
	thread threadPrint2(ThreadPrint, 2);
	threadPrint2.join();
	thread threadPrint3(ThreadPrint, 3);
	threadPrint3.join();

	return 0;

}