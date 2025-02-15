# Main Makefile

#TARGET_MAIN = main_target

OUTPUT_DIR := bin
Project_Common := Common
Project_BinaryTree := Binary_Tree_Operations
Project_HanoiTower := Tower_Of_Hanoi

TARGET := $(Project_Common) $(Project_BinaryTree) $(Project_HanoiTower)

all: $(TARGET)

$(TARGET):
	@$(MAKE) -s -C $@

clean:
	@echo "Cleaning output directory..."
	@rm -rf $(OUTPUT_DIR)
	@for project in $(TARGET); do \
		$(MAKE) clean -C $$project; \
	done

.PHONY: all clean $(TARGET)
