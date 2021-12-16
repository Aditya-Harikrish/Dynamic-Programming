#include "Fibonacci.h"
#include "Timer.h"

int main(void) {
    std::vector<uint64_t> nArray{5, 10, 15, 20, 25, 30, 35, 40, 45};
    for (auto &n : nArray) {
        std::cout << "n = " << n << std::endl;
        std::cout.flush();
        {
            printf("%-19s : ", "Without Memoisation");

            Timer timer;
            std::vector<uint64_t> FibArray(n + 1);
            Fibonacci::Without_Memoisation(FibArray, n);
            std::cout << timer.Stop() << " ms" << std::endl;

#ifdef PRINT
            for (auto &it : FibArray) std::cout << it << " ";
            std::cout << std::endl;
#endif
        }

        {
            printf("%-19s : ", "With Memoisation");
            Timer timer;
            std::vector<uint64_t> FibArray(
                n + 1, 4);  // The default value to fill the array is 4, because 4 is not a Fibonacci number

            Fibonacci::With_Memoisation(FibArray, n);
            std::cout << timer.Stop() << " ms" << std::endl;

#ifdef PRINT
            for (auto &it : FibArray) std::cout << it << " ";
            std::cout << std::endl;
#endif
        }
        std::cout << std::endl;
    }
    return 0;
}