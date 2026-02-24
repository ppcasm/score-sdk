#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

/*
	_putc_r  -- put a character out of the serial port.
*/
void _putc_r (char ch){
	while(*(volatile unsigned int *)0x88150010 & 0x00000020);
	if((ch == '\n') || (ch == '\r'))
	{
		*(volatile unsigned int *)0x88150000 = '\r';
		while(*(volatile unsigned int *)0x88150010 & 0x00000020);
		*(volatile unsigned int *)0x88150000 = '\n';
	}
	else
		*(volatile unsigned int *)0x88150000 = ch;
	
}
/*
	read  -- read bytes from the serial port. Ignore fd, since
	we only have stdin.
*/
int _read_r (struct _reent *r, int fd, char *buf, int nbytes){
	int bk_nbytes = nbytes;
	if(isatty(fd)){
		while(bk_nbytes-- > 0){
			while(*(volatile unsigned int *)0x88150010 & 0x00000010);
			*buf = *(volatile unsigned int *)0x88150000;
			_putc_r(*buf);
			if(*buf == '\r')
				break;
			if(*buf == '\n')
				break;
			buf++;
		}
	}
	return (nbytes - bk_nbytes);
}

/*
	write -- write bytes to the serial port. Ignore fd, since
	stdout and stderr are the same. Since we have no filesystem,
	open will only return an error.
*/
int _write_r (struct _reent *r, int fd, char *buf, int nbytes){
	int bk_nbytes = nbytes;
	if(isatty(fd)){
		while(bk_nbytes-- > 0){
			_putc_r(*buf++);
		}
	}
     return nbytes;
}

/*
	open -- open a file descriptor. We don't have a filesystem, so
	we return an error.
*/
int _open_r (struct _reent *r, char *buf, int flags, int mode){
     return -1;
}

/*
	close -- close a file descriptor. We don't need
	to do anything, but pretend we did.
*/
int _close_r (struct _reent *ptr, int fd){
     return -1;
}

#if 1
/*
	exit
*/
void _exit (int extcode){
	while(!extcode);
	*(volatile unsigned int *)0x88210000 = 0x40;
	goto *0x9f000000;
}
#endif

/*
	sbrk -- changes heap size size. Get nbytes more
	RAM. We just increment a pointer in what's
	left of memory on the board.
*/
#define HEAPSIZE (1024*1024)
static unsigned char _heap[HEAPSIZE];
char * _sbrk_r (struct _reent *ptr, int nbytes){
	static unsigned char *heap_end = NULL;
	unsigned char *prev_heap_end;
	/* initialize */
	if(heap_end == NULL)
		heap_end = _heap;
	prev_heap_end = heap_end;

	if( heap_end + nbytes - _heap > HEAPSIZE ){
		/* heap overflow - announce on stderr */
		write(2, "Heap overflow!\n", 15);
		abort();
	}
	heap_end += nbytes;
	return (char *)prev_heap_end;
}


/*
	lseek -- move read/write pointer. Since a serial port
	is non-seekable, we return an error.
*/
off_t _lseek_r (struct _reent *ptr, int fd, off_t offset, int whence){
     return -1;
}

/*
	fstat -- get status of a file. Assume it is a
	terminal (character special file).
*/
int _fstat_r (struct _reent *r, int fd, struct stat *buf){
	buf->st_mode = S_IFCHR;
	return 0;
}

int isatty (int fd){
	 return fd == 0 || fd == 1 || fd == 2;
}

/*
	getpid -- only one process, so just return 1.
*/
#define __MYPID 1

int _getpid (){
	return __MYPID;
}

int _getpid_r (){
	return __MYPID;
}

/*
	kill -- go out via exit...
*/
int _kill (int pid, int sig){
	if (pid == __MYPID)
		return 0;
	return -1;
}

int _kill_r (int pid, int sig){
	if (pid == __MYPID)
		return 0;
	return -1;
}

