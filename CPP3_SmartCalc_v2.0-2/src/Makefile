CXX = g++
CXXFLAGS 	= -std=c++17 -Wall -Werror -Wextra -g
TEST_LIBS 	= -lpthread -lstdc++ -lm -lgtest
VIEW_DIR = view
MODEL_DIR = model
CONTROLLER_DIR = controller
BLD_DIR = ../build
EXECUTABLE 	= test
TESTS_DIR 	= tests
SOURCES 	= $(wildcard $(MODEL_DIR)/*.cpp)
TESTS 	= $(wildcard $(TESTS_DIR)/*.cpp)
OBJECTS 	= $(patsubst %.cpp, %.o, $(SOURCES) $(TESTS))
UNAME:=$(shell uname -s) # check OS

ifeq ($(UNAME),Linux ) # Linux
	OPEN_CMD=lynx
	ADD_LIB=-lm -lrt -lpthread -lsubunit
	BREW=/home/darkwolf/homebrew
endif
ifeq ($(UNAME),Darwin ) # MacOS
	OPEN_CMD=open
	ADD_LIB=
	BREW:=${HOME}/homebrew
endif
PATH := $(PATH):$(BREW)/bin # paths to lcov and genhtml
GCOV=--coverage
PROJECTNAME=S21_SmartCalc_v2_0

all: tests

build: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE) $(TEST_LIBS)

install:
	@if [ ! -d $(BLD_DIR) ] ; then mkdir $(BLD_DIR); fi
	cmake -B$(BLD_DIR) -H$(VIEW_DIR)
	cmake --build $(BLD_DIR)

uninstall:
	-rm -rf ../build

dvi:
	@if [ ! -d ../dvi ] ; then mkdir ../dvi; fi
	doxygen dvi_config
	-$(OPEN_CMD) ../dvi/html/index.html

dist:
	@if [ ! -d ../dist ] ; then mkdir ../dist; fi
	tar -czvf ${PROJECTNAME}.tar.gz images $(VIEW_DIR) $(CONTROLLER_DIR) $(MODEL_DIR) $(TESTS_DIR) dvi_config Makefile README.md
	mv ${PROJECTNAME}.tar.gz ../dist

$(PROJECTNAME).a: $(OBJECTS)
	${CC} $(CFLAGS) ${ADD_LIB} ${SOURCE}
	ar rc $(PROJECTNAME).a ${OBJECTS}
	ranlib $(PROJECTNAME).a

tests: build
	rm -f *.o
	valgrind --tool=memcheck --leak-check=yes ./$(EXECUTABLE)

debug_flag:
	$(eval CXXFLAGS += -g)

gcov_flag:
	$(eval CXXFLAGS += --coverage)

gcov_report: clean gcov_flag tests
	mkdir -p gcov
	lcov --no-external -o coverage.info -c --directory . 
	genhtml coverage.info --output-directory gcov
	rm -rf *.gcno *.gcda *.gcov
	make clean
	-$(OPEN_CMD) ./gcov/index.html

rebuild: 
	-rm -rf $(BLD_DIR)
	make clean
	make all

clean:
	-rm -rf *.o
	-rm -rf *.a
	-rm -rf *.info && rm -rf *.gcov
	-rm -rf ./test && rm -rf ./gcov_report
	-rm -rf ./report/
	-rm -rf ./$(VIEW_DIR)/*.o
	-rm -rf ./$(VIEW_DIR)/*.a
	-rm -rf ./$(MODEL_DIR)/*.gcda
	-rm -rf ./$(MODEL_DIR)/*.gcno
	-rm -rf ./$(TESTS_DIR)/*.gcda
	-rm -rf ./$(TESTS_DIR)/*.gcno
	-rm -rf ./$(TESTS_DIR)/*.o
	-rm -rf ./$(MODEL_DIR)/*.o
	-rm -rf ./$(MODEL_DIR)/*.a
	-rm -rf ./$(CONTROLLER_DIR)/*.o
	-rm -rf ./$(CONTROLLER_DIR)/*.a
	-rm -rf ./$(VIEW_DIR)/moc_*.cpp
