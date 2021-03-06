#include "meter.h"

timePoint myClock (void) { 
  return std::chrono::system_clock::now(); 
}

Register cpuid (uint eax) {
  if (!hasCPUID ())
    throw std::runtime_error ("Error: No CPUID instruction avaivable on the current CPU.");
  
  uint ebx, ecx, edx;
  
  __asm__ __volatile__ 
	  (
	    "mov %0, %%eax\n"	// move the first input operant to 'eax'
	    "cpuid"		// run 'cpuid', results will be in e{a,b,c,d}x
	    : "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx) // output operants
	    : "a"(eax)					 // input operants
// 	    : "%rax", "%rbx", "%rcx", "%rdx"		 // TODO: take a closer look to CLOBBERLISTS!
	  );
 
  return Register (eax, ebx, ecx, edx);
}

uint64_t rdtscp (void) {
  if (!hasRDTSCP ())
    throw std::runtime_error ("Error: No RDTSCP instruction avaivable on the current CPU");
  
  uint lo, hi;
  
  __asm__ __volatile__
	  (
	    "rdtscp"
	    : "=a" (lo), "=d" (hi)	// output operants, 'rdtscp' writes the results into the 'eax' and 'edx' register
// 	    :: "%rax", "%rcx", "%rdx"
	  );
	  
  return ((uint64_t)hi << 32) | lo;
}

uint64_t rdtsc (void) {
  if (!hasRDTSC ())
    throw std::runtime_error ("Error: No RDTSC instruction avaivable on the current CPU");
  
  uint lo, hi;
  
  __asm__ __volatile__
	  (
	    "rdtsc"
	    : "=a" (lo), "=d" (hi)	// output operants, 'rdtscp' writes the results into the 'eax' and 'edx' register
	  );
	  
  return ((uint64_t)hi << 32) | lo;
}

uint64_t myCycles ( void ) {
  cpuid (0);
  return rdtsc();
}

