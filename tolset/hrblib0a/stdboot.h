struct Dobject{
	char *name;
	struct MEMMAN *memman;
	struct TASK *task;
	void (*unload)(struct Dobject *this); 
};
