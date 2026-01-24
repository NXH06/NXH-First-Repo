#include <stdio.h>
#include <string.h>

#define NB_DISK_PAGE 5
#define PAGE_SIZE 20
#define NB_MEM_PAGE 4

#define boolean int
#define true 1
#define false 0

char Disk[NB_DISK_PAGE][PAGE_SIZE]; 
char Memory[NB_MEM_PAGE][PAGE_SIZE];
int PageTable[NB_DISK_PAGE]; // maps virtual memory to disk (secondary physical memory)
struct {
	boolean free;
	int date;
	int npage;
} MemState[NB_MEM_PAGE];

int Date = 1; // simulated global clock. In actual OSes, Unix Epoch Time is used

void init();
char *memory_read(int npage);
int memory_alloc();
void page_fault(int npage);
int lru_select();

void init() {
	int i;
	// initialize Disk
	for (i=0;i<NB_DISK_PAGE;i++) {
		strcpy(Disk[i],"page");
		Disk[i][4] = '0'+i;
		Disk[i][5] = 0;
	}
	/*
	for (i=0;i<NB_DISK_PAGE;i++) {
		printf(Disk[i]);
		printf("\n");
	}
	*/
	// initialize Memory
	for (i=0; i<NB_MEM_PAGE; i++)
		MemState[i].free = true;
		MemState[i].npage = -1;
	// initialize PageTable
	for (i=0; i<NB_DISK_PAGE; i++)
		PageTable[i] = -1;
}
void print_trace(int page) {
    int i;
    printf("\tAfter access to %d: ", page);
    for (i = 0; i < NB_MEM_PAGE; i++) {
        if (MemState[i].free)
            printf(". ");
        else
            printf("%d ", MemState[i].npage);
    }
    printf("\n");
}
char *memory_read(int npage) { // npage: 
	printf("memory_read (%d)\n", npage);
	int frame;
	// If page absent, raise page fault first
	if (PageTable[npage] == -1) { // -1 means the page is absent
		page_fault(npage);
	}
	// Then in either case,
	frame = PageTable[npage];
	MemState[frame].date = Date; // set date of new page to current date
	Date++; // advance the date
	return Memory[frame];
}
int memory_alloc() { // Find free frame
	int i;
	for (i = 0; i < NB_MEM_PAGE; i++) {
		if (MemState[i].free) {
			printf("memory_alloc: %d\n", i);
			return i;
		}
	}
	return -1;
}
void page_fault(int npage) {
	printf("page_fault (%d)\n", npage);
	int frame, old_page;
	frame = memory_alloc();
	if (frame == -1) {
		frame = lru_select(); // If no free frame, find an existing page via LRU
		old_page = MemState[frame].npage; // get page number of the page about to be evicted
		PageTable[old_page] = -1; // eviction!
	}
	strcpy(Memory[frame], Disk[npage]); // load page from disk to memory
	MemState[frame].free = false;
    MemState[frame].npage = npage;
	// no need to increment date since it's already done on access (in memory_read())
    PageTable[npage] = frame;
}
int lru_select() { // find oldest page
	int i, lru = -1, min_date = MemState[0].date;
	for (i = 0; i < NB_MEM_PAGE; i++) {
        if (!MemState[i].free) {
            if (MemState[i].date < min_date) { // if page date older than current oldest
                min_date = MemState[i].date;
                lru = i;
            }
        }
    }
    printf("lru_select: %d\n", MemState[lru].npage);
    return lru;
}

int main(int argc, char *argv[]) {
	int i;
	init();
/*
	printf("linear access of all pages\n");
	for (i=0;i<NB_DISK_PAGE;i++)
		printf("read access page %d : %s\n",i,memory_read(i));
*/
	printf("access pages as in lecture (0,1,2,3,0,1,4,0,1,2,3,4,1,2)\n");
	int series[14] = {0,1,2,3,0,1,4,0,1,2,3,4,1,2}; // just page numbers, not literal values inside the pages!!!
	for (i=0;i<14;i++) {
		memory_read(series[i]);
		//printf("read access page %d: %s\n", series[i], memory_read(series[i]));
		print_trace(series[i]);
	}
	printf("completed\n");
}
