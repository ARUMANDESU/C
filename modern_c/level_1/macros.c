#include <stdio.h>

enum corvid { magpie, raven, jay, chough, corvid_num, };

#define CORVID_NAME /**/                                                       \
    (char const *const[corvid_num]) {                                          \
        [chough] = "chough", [raven] = "raven", [magpie] = "magpie",           \
        [jay] = "jay",                                                         \
    }

int main() {
    for (unsigned i = 0; i < corvid_num; i++) {
        printf("Corvid %u is the %s\n", i, CORVID_NAME[i]);
    }
    
    return 0;
}
