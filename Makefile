INPUT_FILE = "src/main.c"
OUTPUT_FILE = "bin/main.exe"

# -Wl,-subsystem,windows

build:
	gcc $(INPUT_FILE) \
	-w \
	-I"include" \
	-L"lib" \
	-lmingw32 -lSDL2main -lSDL2 \
	-o $(OUTPUT_FILE)

run:
	$(OUTPUT_FILE)

