CXX = g++
CXXFLAGS = -Wall -g
TARGET = myprogram
SRCS = main.cpp users.cpp processes.cpp
OBJS = $(SRCS:.cpp=.o)
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)