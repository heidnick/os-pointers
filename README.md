# os-pointers
C / C++ Pointers

Copy and paste to compile:
g++ -std=c++11 -o pointers pointers.cpp

Copy and paste to run:
./pointers

Copy and past to run test files:
./pointers < ./tests/input/in01.txt > ./tests/output/usr_output_1.txt
./pointers < ./tests/input/in02.txt > ./tests/output/usr_output_2.txt

To compare test files:
-diff --strip-trailing-cr ./tests/output/usr_output_1.txt /tests/output/out01.txt
-diff --strip-trailing-cr ./tests/output/usr_output_2.txt /tests/output/out02.txt

