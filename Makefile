CPP :=g++
TARGET :=../bin/change_me.exe # change this to the name of your language
LDFLAGS :=
SOURCES := $(shell find . -name "*.cpp")
SOURCES += $(shell find . -name "*.hpp")

TEST_CODE :=../test/test.txt # change the extension to match your language
TEST_TARGET :=../test/test.exe

all:
	$(CPP) $(LDFLAGS) $(CFLAGS) -o $(TARGET) $(SOURCES)

test:
	$(TARGET) $(TEST_CODE) -o $(TEST_TARGET)

clean:
	del $(TARGET)