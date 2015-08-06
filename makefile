skip_dirs = .git
dirs := $(shell find . -maxdepth 1 -name '*' -type d)
dirs := $(basename $(patsubst ./%,%,$(dirs)))
dirs := $(filter-out $(skip_dirs), $(dirs))

all:
	$(foreach N, $(dirs), make -C $(N);)

clean:
	$(foreach N, $(dirs), make clean -C $(N);)
