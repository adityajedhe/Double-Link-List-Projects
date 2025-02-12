# Main Makefile

#TARGET_MAIN = main_target

OUTPUT_DIR = bin
Project_Common = Common
Project_BinaryTree = Binary_Tree_Operations
Project_HanoiTower = Tower_Of_Hanoi

all: $(Project_Common) $(Project_BinaryTree) $(Project_HanoiTower)

$(Project_Common):
	$(MAKE) -C $(Project_Common)

$(Project_BinaryTree):
	$(MAKE) -C $(Project_BinaryTree)

$(Project_HanoiTower):
	$(MAKE) -C $(Project_HanoiTower)

clean:
	$(MAKE) -C $(Project_Common) clean
	$(MAKE) -C $(Project_BinaryTree) clean
	$(MAKE) -C $(Project_HanoiTower) clean
	rm -rf $(OUTPUT_DIR)

.PHONY: all clean $(Project_Common) $(Project_BinaryTree) $(Project_HanoiTower)
