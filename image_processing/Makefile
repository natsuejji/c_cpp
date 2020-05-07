CXX=g++
CPP11 = -std=c++11
OPENCV=-I"D://opencv//build//include" -L"D:\opencv\build\x64\MinGW\bin" -lopencv_core400 -lopencv_highgui400 -lopencv_imgcodecs400

test:
	$(CXX) $(CPP11) $(OPENCV) main.cpp -o main.exe
clean:
	del *.o *.exe
