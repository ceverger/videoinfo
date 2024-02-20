
all:
	g++ main.cpp videoinfo.cpp libavcodec.so libavformat.so -o videoinfo -I.
