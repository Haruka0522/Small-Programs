# コンパイラを指定(Macはclang++,Linuxはg++)
ifeq ($(shell uname),Linux)
	CC := g++
else
	CC := clang++
endif

# インクルードファイル等
CFLAGS :=`pkg-config opencv4 --cflags` `pkg-config opencv4 --libs` -std=c++11
LDFLAGS := json11.cpp homography.cpp

# ディレクトリ内の全てのC++ファイルをコンパイル
SOURCES := main.cpp

EXECUTABLE := homography

all:$(EXECUTABLE)

$(EXECUTABLE):$(SOURCES)
	$(CC) $< $(LDFLAGS) $(CFLAGS) -o $@

clean:
	rm -rf $(EXECUTABLE)
