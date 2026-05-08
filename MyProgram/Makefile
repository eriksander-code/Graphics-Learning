# Detecta se está no Windows ou Linux
ifeq ($(OS), Windows_NT)
	# --- CONFIGURAÇÃO WINDOWS ---
	CXX = g++
	CXXFLAGS = -Iinclude
	LDFLAGS = -Llib-mingw-w64 -lglfw3dll -lopengl32 -lgdi32 -lwinmm
	OUT = build/program.exe
	MKDIR = if not exist build mkdir build
	RM = rmdir /s /q build
	CP_ASSETS = copy lib-mingw-w64\glfw3.dll build\ && xcopy /E /I /Y shaders build\shaders
else
	# --- CONFIGURAÇÃO LINUX ---
	CXX = g++
	CXXFLAGS = -Iinclude
	LDFLAGS = -lglfw -lGL -ldl
	OUT = build/program.out
	MKDIR = mkdir -p build
	RM = rm -rf build
	CP_ASSETS = cp -r shaders build/
endif

SOURCES = $(wildcard src/*.cpp) src/glad.c

all: build_dir compile copy_assets

build_dir:
	$(MKDIR)

compile:
	$(CXX) $(SOURCES) $(CXXFLAGS) $(LDFLAGS) -o $(OUT)

.PHONY: copy_assets  # Isso avisa o make para sempre rodar essa regra, sem checar datas

copy_assets:
	$(CP_ASSETS)

clean:
	$(RM)