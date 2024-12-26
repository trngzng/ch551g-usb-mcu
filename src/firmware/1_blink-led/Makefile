# Define output directory
OUTPUT_DIR = output

# Compile each .c file into .rel files
hex: $(OUTPUT_DIR)\main.rel
	sdcc $(OUTPUT_DIR)\main.rel -o $(OUTPUT_DIR)\main.ihx

# Compile main.c to main.rel
$(OUTPUT_DIR)\main.rel: main.c
	mkdir $(OUTPUT_DIR)
	sdcc -c main.c -o $(OUTPUT_DIR)\main.rel

all: hex
	packihx $(OUTPUT_DIR)\main.ihx > $(OUTPUT_DIR)\main.hex

clean:
	rmdir /s /q $(OUTPUT_DIR)