# Truncated multiplication and batch software SIMD AVX512 implementation for faster Montgomery multiplications and modular exponentiation


## Overview

This project is a software implementation exploring a truncated version of the Montgomery multiplication and exploiting the AVX512 intel instruction set, specifically the VPMADD52 instructions, to enhance performance in multi-precision arithmetic multiplications. Our primary focus is on batch multiplications, squarings and exponentiations for bit sizes ranging from 260 to 4154 bits.



## Performance Measurement


Performance were measured in the following conditions :
- **Architecture**:  Processor supporting the latest AVX512IFMA instruction set.

- **GMP**: Version 6.2.0, utilizing the `mpn_sec_powm` function designed for cryptographic applications.
- **OpenSSL**: Version 3.2.1, compiled for our platform with support for `RSA_Z` operations using the AVX2 instruction set.
- **Compiler**: GCC version 9.4.0.

Benchmark :
1. **Turbo Boost Disabled**: Ensure consistent CPU performance during testing.
   **Activate rdpmc counter**: Ensure super user privileges to measure performances (run main_rdpmc.c).
2. **Warm-Up Runs**: Execute 1000 runs to warm up the cache memory.
3. **Data Set Generation**: Create 50 random data sets for testing.
4. **Execution Measurement**: For each data set, the minimum execution clock cycle count over 1000 runs is recorded.
5. **Average Calculation**: The final performance is the average of all recorded minimums.
6. **Clock Cycle Counting**: Utilized `rdtsc`/`rdtscp` instructions for accurate clock cycle measurement.

## Acknowledgements

This work was conducted by Laurent-Stéphane Didier, Nadia El Mrabet, Léa Glandus and Jean-Marc Robert.

## License

This project is licensed under the GNU General Public License. See the GNU General Public License file for details.

---

For further information, please refer to the related paper on IACR CIC 2024.
