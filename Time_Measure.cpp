// how to measure time

#include <iostream>
#include <windows.h> 
#include <time.h>
#include <chrono>  

using namespace std;

void ff() {
	Sleep(2777);
}

int main() {
	cout << "Started...\n";

	// Method 1
	auto t1 = time(NULL);
	ff();
	printf("1) Time: %lu sec\n", (unsigned long)(time(NULL) - t1));

	// Method 2
	auto t2 = GetTickCount64();
	ff();
	printf("2) Time: %lu ms\n", (unsigned long)(GetTickCount64() - t2));

	// Method 3
	auto t3 = chrono::system_clock::now();
	ff();
	chrono::duration<double> tempo = chrono::system_clock::now() - t3;
	printf("3) Time: %.3f sec\n", tempo.count());

	printf("\nPress Enter to exit...\n"); cin.get();
	return 0;
}

