targetfile=main
CXX=g++
CPP11 = -std=c++11
OPENCV=-I"D:/opencv430/opencv/build/include" -L"D:/opencv430/opencv/build/x64/mingw/bin"
OPENCV+=-lopencv_core430 -lopencv_highgui430 -lopencv_imgcodecs430
test: 
	$(CXX) $(CPP11) $(OPENCV) $(targetfile).cpp -o $(targetfile).exe
clean:
	del *.o *.exe
