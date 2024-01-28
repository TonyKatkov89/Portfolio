CXX 		= g++ 
CXXFLAGS 	= -std=c++17 -Wall -Werror -Wextra
TEST_LIBS 	= -lpthread -lstdc++ -lm -lgtest
EXECUTABLE 	= test
TESTS_DIR 	= Tests
SOURCES 	= $(wildcard $(TESTS_DIR)/*.cpp)
OBJECTS 	= $(patsubst %.cpp, %.o, $(SOURCES))

all: test

build: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE) $(TEST_LIBS)
	
debug_flag:
	$(eval CXXFLAGS += -g)

gcov_flag:
	$(eval CXXFLAGS += --coverage)

gcov_report: clean gcov_flag test
	mkdir -p gcov
	lcov --ignore-errors mismatch --no-external -o coverage.info -c --directory . 
	genhtml coverage.info --output-directory gcov
	rm -rf *.gcno *.gcda *.gcov
	
test: build
	./$(EXECUTABLE)
	rm -f *.o

debug: debug_flag build

valgrind:
	CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(EXECUTABLE)

clean:
	rm -rf *.a *.o $(TESTS_DIR)/*.o $(EXECUTABLE) *.a* $(TESTS_DIR)/*.gc* *.info gcov
