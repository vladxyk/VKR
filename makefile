#export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/opt/intel/oneapi/mkl/2021.4.0/lib/intel64
CPP=/opt/intel/oneapi/compiler/2021.4.0/linux/bin/icpx
INC=/opt/intel/oneapi/mkl/2021.4.0/include
LIB=/opt/intel/oneapi/mkl/2021.4.0/lib/intel64

all:
	g++ main.cpp init.cpp printAll.cpp step1.cpp step2.cpp step3.cpp step4.cpp -o task
