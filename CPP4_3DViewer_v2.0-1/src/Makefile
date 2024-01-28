CXX = g++
CXXFLAGS 	= -std=c++17 -Wall -Werror -Wextra -g
TEST_LIBS 	= -lpthread -lstdc++ -lm -lgtest
CMD_DIR = command
MATRIX_DIR = matrix
OBJRDR_DIR = objreader
TRANSF_DIR = transform
FACADE_DIR = singleton_facade
GIF_DIR = QtGifimage
DVI_DIR = ../dvi
BLD_DIR = ../build
EXECUTABLE 	= test
TESTS_DIR 	= mxtests
SOURCES 	= $(wildcard $(MATRIX_DIR)/*.cc)
TESTS_FILES 	= $(wildcard $(TESTS_DIR)/*.cc)
OBJECTS 	= $(patsubst %.cc, %.o, $(SOURCES) $(TESTS_FILES))
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
PROJECTNAME=S21_3dviewer_v2_0

all: clean uninstall install gcov_report dvi

build: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE) $(TEST_LIBS)

tests: build
	rm -f *.o
	valgrind --tool=memcheck --leak-check=yes ./$(EXECUTABLE)

install:
	@if [ ! -d $(BLD_DIR) ] ; then mkdir $(BLD_DIR); fi
	cd $(BLD_DIR) && qmake ../src && make

uninstall:
	-rm -rf $(BLD_DIR)

dvi:
	@if [ ! -d $(DVI_DIR) ] ; then mkdir $(DVI_DIR); fi
	doxygen dvi_config
	cd $(DVI_DIR)/latex && make
	open $(DVI_DIR)/latex/refman.dvi

dist:
	@if [ ! -d ../dist ] ; then mkdir ../dist; fi
	tar -czvf ${PROJECTNAME}.tar.gz $(CMD_DIR) $(OBJRDR_DIR) $(MATRIX_DIR) $(TRANSF_DIR) $(TESTS_DIR) $(FACADE_DIR) $(GIF_DIR) dvi_config Makefile README.md 3DViewer10.pro 3DViewer10.pro.user ./*.cpp ./*.h
	mv ${PROJECTNAME}.tar.gz ../dist

$(PROJECTNAME).a: $(OBJECTS)
	${CC} $(CFLAGS) ${ADD_LIB} ${SOURCE}
	ar rc $(PROJECTNAME).a ${OBJECTS}
	ranlib $(PROJECTNAME).a

debug_flag:
	$(eval CXXFLAGS += -g)

gcov_flag:
	$(eval CXXFLAGS += --coverage)

gcov_report: clean gcov_flag tests
	mkdir -p gcov
	lcov --no-external -o coverage.info -c --directory ./$(MATRIX_DIR)
	genhtml coverage.info --output-directory gcov
	rm -rf *.gcno *.gcda *.gcov
	-$(OPEN_CMD) ./gcov/index.html

rebuild: 
	-rm -rf $(BLD_DIR)
	make clean
	make all

clang:
	clang-format -i *.cpp *.cc *.h $(CMD_DIR)/*.cc $(OBJRDR_DIR)/*.cc $(MATRIX_DIR)/*.cc $(TRANSF_DIR)/*.cc $(TESTS_DIR)/*.cc $(CMD_DIR)/*.h $(OBJRDR_DIR)/*.h $(MATRIX_DIR)/*.h $(TRANSF_DIR)/*.h $(FACADE_DIR)/*.h $(TESTS_DIR)/*.h

clean:
	-rm -rf *.o
	-rm -rf *.a
	-rm -rf *.info && rm -rf *.gcov
	-rm -rf ./test && rm -rf ./gcov
	-rm -rf ./gcov/
	-rm -rf *.gcda
	-rm -rf *.gcno
	-rm -rf ./$(CMD_DIR)/*.o
	-rm -rf ./$(CMD_DIR)/*.a
	-rm -rf ./$(TRANSF_DIR)/*.o
	-rm -rf ./$(TRANSF_DIR)/*.a
	-rm -rf ./$(MATRIX_DIR)/*.gcda
	-rm -rf ./$(MATRIX_DIR)/*.gcno
	-rm -rf ./$(TESTS_DIR)/*.gcda
	-rm -rf ./$(TESTS_DIR)/*.gcno
	-rm -rf ./$(TESTS_DIR)/*.o
	-rm -rf ./$(MATRIX_DIR)/*.o
	-rm -rf ./$(MATRIX_DIR)/*.a
	-rm -rf ./$(OBJRDR_DIR)/*.o
	-rm -rf ./$(OBJRDR_DIR)/*.a
	-rm -rf ./$(CMD_DIR)/moc_*.cpp