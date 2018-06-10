CXX = g++
CXXFLAGS = -std=c++0x -g

OBJS = main.o utils.o ItemRoom.o LinkedDungeon.o Player.o Space.o TalkRoom.o UseItemRoom.o

SRCS = main.cpp utils.cpp ItemRoom.cpp LinkedDungeon.cpp Player.cpp Space.cpp TalkRoom.cpp UseItemRoom.cpp

HEADERS = utils.hpp ItemRoom.hpp LinkedDungeon.hpp Player.hpp Space.hpp TalkRoom.hpp UseItemRoom.hpp

FinalProject: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o FinalProject

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o FinalProject
