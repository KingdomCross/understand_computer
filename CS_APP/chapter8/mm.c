/* Basic constants and macros */
#define WSIZE 4	// Word and header/footer size (bytes)
#define DSIZE 8 // Double word size (bytes)
#define CHUNKSIZE (1<<12) // Extend heap by this amount (bytes)

#define MAX(x,y) ((x) > (y) ? (x) : (y))

/* Pack a size and allocated bit into a word */
#define PACK(size, alloc) ((size) | (alloc))

/* Read and write a word at address p */ 
#define GET(p) (*(unsigned int *)(p))
#define PUT(p, val) (*(unsigned int *)(p) = (val))

/* Read the size and allocated fields from address p */
#define GET_SIZE(p) (GET(p) & ~0x7)
#define GET_ALLOC(p) (GET(p) & 0x1)

/* Given block ptr bp, compute address of its header and footer */
#define HERP(bp) ((char *)(bp) -WSIZE)
#define FTRP(bp) ((char *)(bp) + GET_SIZE(HDRP(BP)) -DSIZE)

/* Given block ptr bp, compute address of next and previous blocks */
#define NEXT_BLKP(bp) ((char *)(bp) + GET_SIZE(((char *)(bp) - WSIZE)))
#define PREV_BLKP(bp) ((char *)(bp) - GET_SIZE(((char *)(bp) - DSIZE)))

int mm_init(void)
{
	/* Create the initial empty heap */
	if((heap_listp = mem_sbrk(4 * WSIZE)) == (void *) -1)
		return -1;
	PUT(heap_listp, 0); // Alignment padding 
	PUT(heap_listp + (1*WSIZE), PACK(DSIZE, 1)); // Prologue header
	PUT(heap_listp + (2*WSIZE), PACK(DSIZE, 1)); // Prologue footer
	PUT(heap_listp + (3*WSIZE), PACK(0,1)); // Epilogue header
	heap_listp += (2*WSIZE);

	/* Extend the empty heap with a free block of CHUNKSIZE bytes */
	if(extend_heap(CHUNKSIZE/WSIZE) == NULL)
		return -1;
	return 0;
}

static void *extend_heap(size_t words)
{
	char *bp;
	size_t size;

	// Allocate an even number of words to maintain alignment
	size = (words % 2) ? (words + 1) * WSIZE : words * WSIZE;
	if((long )(bp = mem_sbrk(size)) == -1 )
		return NULL;

	// Initialize free block header/footer and the epilogue header
	PUT(HDRP(BP), PACK(size, 0)); // Free block header
	PUT(FTRP(bp), PACK(size, 0)); // Free block footer
	PUT(HDRP(NEXT_BLKP(bp)), PACK(0, 1)); // New epilogue header

	// Coalesce if the previous block was free
	return coalesce(bp);
}


void mm_free(void *bp)
{
	size_t size = GET_SIZE(HDRP(bp));

	PUT(HDRP(bp), PACK(size, 0));
	PUT(FTRP(bp), PACK(size, 0));
	coalesce(bp);
}

static void *coalesce(void *bp)
{
	size_t prev_alloc = GET_ALLOC(FTRP(PREV_BLKP(bp)));
	size_t next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(bp)));
	size_t size = GET_SIZE(HDRP(bp));

	if(prev_alloc && next_alloc)
	{
		return bp;
	}
	else if (prev_alloc && !next_alloc)
	{
		size += GET_SIZE(HDRP(PREV_BLKP(bp)));
		PUT(HDRP(bp), PACK(size,0));
		PUT(FTRP(bp), PACK(size,0));
	}
	else if (!prev_alloc && !next_alloc)
	{
		size += GET_SIZE(HDRP(PREV_BLKP(bp)));
		PUT(FTRP(bp), PACK(size, 0));
		PUT(HDRP(PREV_BLKP(bp)), PACK(size,0));
		bp = PREV_BLKP(bp);
	}
	else
	{
		size += GET_SIZE(HDRP(PREV_BLKP(bp))) + GET_SIZE(FTRP(NEXT_BLKP(bp)));

		PUT(HDRP(PREV_BLKP(bp)), PACK(size,0));
		PUT(FTRP(NEXT_BLKP(bp)), PACK(size,0));
		bp = PREV_BLKP(bp);
	}

	return bp;
}

void *mm_malloc(size_t size)
{
	size_t asize; // Adjust block size
	size_t extendsize; // Amount to extend heap if no fit
	char *bp;

	// IGnore spurious requests
	if(size == 0)
		return NULL;

	// Adjust block size to include overhead and alignment reps
	if (size <= DSIZE )
		asize = 2*DSIZE;
	else
		asize = DSIZE * ((size + (DSIZE) + (DSIZE -1))/DSIZE);

	// Search the free list for a fit
	if ((bp = find_fit(asize)) != NULL)
	{
		place(bp, aszie);
		return bp;
	}

	// No fit found. Get more memory and place the block
	extendsize = MAX(aszie, CHUNKSIZE);
	if((bp = extend_heap(extendsize/WSIZE)) == NULL)
		return NULL;
	place(bp, aszie);
	return bp;
}
