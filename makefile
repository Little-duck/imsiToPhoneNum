imsiToPhoneNum:imsiToPhoneNum.o
	g++ -o imsiToPhoneNum imsiToPhoneNum.o
imsiToPhoneNum.o:imsiToPhoneNum.cpp
	g++ -c imsiToPhoneNum.cpp
