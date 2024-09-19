#define _GNU_SOURCE

#include <unistd.h>
#include <stdio.h>
#include <sys/syscall.h>
#include <stdint.h>
//#include <perfevents.h>

/**** Measurements procedures according to INTEL white paper

 "How to benchmark code execution times on INTEL IA-32 and IA-64" 
 
 *****/
 

// rdpmc_instructions uses a "fixed-function" performance counter to return the count of retired instructions on
//       the current core in the low-order 48 bits of an unsigned 64-bit integer.
inline static unsigned long rdpmc_instructions(void)
{
   unsigned a, d, c;

   c = (1<<30);
   __asm__ __volatile__("rdpmc" : "=a" (a), "=d" (d) : "c" (c));

   return ((unsigned long)a) | (((unsigned long)d) << 32);;
}


// rdpmc_actual_cycles uses a "fixed-function" performance counter to return the count of actual CPU core cycles
//       executed by the current core.  Core cycles are not accumulated while the processor is in the "HALT" state,
//       which is used when the operating system has no task(s) to run on a processor core.
unsigned long rdpmc_actual_cycles()
{
   unsigned a, d, c;

   c = (1<<30)+1;
   __asm__ volatile("rdpmc" : "=a" (a), "=d" (d) : "c" (c));

   return ((unsigned long)a) | (((unsigned long)d) << 32);;
}

// rdpmc_reference_cycles uses a "fixed-function" performance counter to return the count of "reference" (or "nominal")
//       CPU core cycles executed by the current core.  This counts at the same rate as the TSC, but does not count
//       when the core is in the "HALT" state.  If a timed section of code shows a larger change in TSC than in
//       rdpmc_reference_cycles, the processor probably spent some time in a HALT state.
unsigned long rdpmc_reference_cycles()
{
   unsigned a, d, c;

   c = (1<<30)+2;
   __asm__ volatile("rdpmc" : "=a" (a), "=d" (d) : "c" (c));

   return ((unsigned long)a) | (((unsigned long)d) << 32);;
}//*/
